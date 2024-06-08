/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HttpServer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahib <ndahib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 10:58:40 by codespace         #+#    #+#             */
/*   Updated: 2024/06/07 11:40:23 by ndahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HttpServer.hpp"

const char response1[] = "HTTP/1.1 200 OK\r\n"
                      "Content-Type: text/html\r\n"
                      "Content-Length: 70\r\n"
                      "\r\n"
                      "<html><head><title>My First HTTP Response</title></head>"
                      "<body><h1>Hello, World!</h1></body></html>";

/* ***Construction************************************************************ */

HttpServer* HttpServer::_instance = nullptr;
HttpServer::HttpServer()
{
	_multiplex = new SelectMultiplex();
	if (_multiplex == NULL)
	{
		throw std::runtime_error("Multiplex Error");
	}
	_handler = NULL;
	_instance = this;
}


HttpServer::~HttpServer()
{
	if (_instance != NULL) 
		delete _instance;
	if (_multiplex != NULL)
		delete _multiplex;
	if (_handler != NULL)
		delete _handler;
	_log.close();
}

/* ***Method*************************************************************** */
HttpServer *HttpServer::getInstance()
{
	if (_instance == NULL)
		_instance = new HttpServer();
	return (_instance);
}


void	HttpServer::readConfig(const char *config_file)
{
	_config = ConfigParser(config_file);
	_config.parse();
	exit(1);
}

void	HttpServer::setup()
{
	// std::vector<t_listen> listenVec = _config.getAllListens();
	// for (std::vector<t_listen>::iterator listen = listenVec.begin(); listen != listenVec.end(); listen++)
	// {
	// 	VirtualHost virtual_host = VirtualHost(*listen);
	// 	this->addVirtualHost(virtual_host);
	// 	if (virtual_host.SetupServer() == -1)
	// 		throw("Could not setup server with given listen");
	// 	_multiplex->Register(READ, virtual_host.get_socket());
	// }
}

void	HttpServer::run()
{
	for (size_t i = 0; i < _virtualHosts.size(); i++){
		if (_virtualHosts[i].SetupServer() != -1){
			_multiplex->Register(READ, _virtualHosts[i].get_socket());
		}
	}

	while (true)
	{
		if (_multiplex->multiplex(TIMEOUTS) == -1)
			continue;
		for (int i = 0; i < 8; i++)
		{
			if (_multiplex->isRegistered(READ, i) == true){
				SetHandler(i, READ);
			}
			else if (_multiplex->isRegistered(WRITE, i) == true){
				send(i, response1 , 163, 0);
				RemoveClient(i);
				std::cout << "Sending Response to Client" << std::endl;
				// SetHandler(i, WRITE);
			}
		}
	}
}

void	HttpServer::stop()
{
	//stop Server
}

void	HttpServer::log()
{
	_log.open("Server.log");
	
	// std::streambuf *coutBuffer = std::cout.rdbuf();
	std::cout.rdbuf(_log.rdbuf());
}



/* ***Getters**************************************************************** */
VirtualHost HttpServer::getVirtualHost(SOCKET fd) const {
	for (size_t i = 0; i < _virtualHosts.size(); i++){
		if (_virtualHosts[i].get_socket() == fd)
			return (_virtualHosts[i]);
	}
	return (_virtualHosts[0]);
}

bool	HttpServer::isVertualHostExist(SOCKET fd) const {
	for (size_t i = 0; i < _virtualHosts.size(); i++){
		if(_virtualHosts[i].get_socket() == fd)
			return	(true);
	}
	return (false);
}

IMultiplex	*HttpServer::getMultiplex() const { 
	return (_multiplex);
}

/* ***VirtualHostMethods*****************************************************	*/
void	HttpServer::addVirtualHost(const VirtualHost& virtualHost){
	_virtualHosts.push_back(virtualHost);	
}

/* ***ClientsMethods********************************************************* */
void	HttpServer::AddClient(SOCKET clientFd){
	if (clientFd != -1)
	{
		_clients[clientFd] = Client(clientFd);
		_multiplex->Register(READ, clientFd);
	}
}


Client	&HttpServer::getClient(SOCKET clientFd) {
	return (_clients[clientFd]);
}

void	HttpServer::RemoveClient(SOCKET fd){
	_multiplex->Unregister(READ_WRITE, fd);
	_clients.erase(fd);
	close(fd);
}


void	HttpServer::SetHandler(IHandler *handler){
	if (_handler != NULL)
		delete _handler;
	_handler = handler;
	_handler->handle();
}

void	HttpServer::SetHandler(SOCKET fd, IMultiplex::EVENT_TYPE type){

	switch (type){
		case READ : {
			if (isVertualHostExist(fd)){
				SetHandler(new AcceptHandler(fd));
				return ;	
			}
			SetHandler(new RequestHandler(fd)); break;
		}
		case WRITE: SetHandler(new ResponseHandler(fd)) ; break; 
	}
}