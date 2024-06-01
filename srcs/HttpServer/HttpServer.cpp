/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HttpServer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 10:58:40 by codespace         #+#    #+#             */
/*   Updated: 2024/05/31 11:10:05 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HttpServer.hpp"

/* ***Construction************************************************************ */

HttpServer* HttpServer::_instance = nullptr;
HttpServer::HttpServer(std::vector<VirtualHost>& virtualHosts ) : _virtualHosts(virtualHosts)
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
	delete _instance;
	delete _multiplex;
	if (_handler != NULL)
		delete _handler;
	_log.close();
}

/* ***Method*************************************************************** */
HttpServer *HttpServer::getInstance(std::vector<VirtualHost>& virtualHosts)
{
	if (_instance == NULL)
		_instance = new HttpServer(virtualHosts);
	return (_instance);
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
			exit(1);
		for (int i = 0; i < 8; i++)
		{
			if (_multiplex->isRegistered(READ, i) == true){
				SetHandler(i, READ);
			}
			else if (_multiplex->isRegistered(WRITE, i) == true){
				send(i, "HTTP/1.1 200 Ok\r\n\r\n", 25, 0);
				RemoveClient(i);
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