/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HttpServer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 10:58:40 by codespace         #+#    #+#             */
/*   Updated: 2024/05/29 09:31:10 by codespace        ###   ########.fr       */
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
		_multiplex->multiplex(TIMEOUTS);
		for (int i = 0; i < FD_SETSIZE; i++) 
		{
			if (_multiplex->isRegistered(READ, i)){
				SetHandler(new AcceptHandler(i));
			}
			else if (_multiplex->isRegistered(WRITE, i)){
				SetHandler(new ResponseHandler(i));
			}
			_handler->handle();
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

IMultiplex	*HttpServer::getMultiplex() const { 
	return (_multiplex);
}

/* ***VirtualHostMethods*****************************************************	*/
void	HttpServer::addVirtualHost(const VirtualHost& virtualHost)
{
	_virtualHosts.push_back(virtualHost);	
}

/* ***ClientsMethods********************************************************* */
void	HttpServer::AddClient(SOCKET clientFd){
	_clients[clientFd] = Client(clientFd);
}

void	HttpServer::RemoveClient(SOCKET fd){
	_multiplex->Unregister(READ_WRITE, fd);
	_clients.erase(fd);
}


void	HttpServer::SetHandler(IHandler *handler){
	delete _handler;
	_handler = handler;
}