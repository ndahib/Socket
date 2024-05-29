/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HttpServer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 10:58:40 by codespace         #+#    #+#             */
/*   Updated: 2024/05/29 08:12:14 by codespace        ###   ########.fr       */
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
	_instance = this;
}


HttpServer::~HttpServer()
{
	delete _instance;
	delete _multiplex;
	_log.close();
}

/* ***Private:Methods*************************************************************** */
void	HttpServer::Read_Handler(SOCKET fd)
{
	/*
	if (isServer (fd) == true)
		// Accept(fd);
		// set to NonBlocking
		// add client
		// registrer in Multiplex;
	else
		// Read(fd)
		// Parse the request
		//if Parsed is Ok or is Finished
		///register in Multiplex to write
	*/
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
				Read_Handler(i);
			}
			else if (_multiplex->isRegistered(WRITE, i)){
				Write_Handler(i);
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

void	HttpServer::addVirtualHost(const VirtualHost& virtualHost)
{
	_virtualHosts.push_back(virtualHost);	
}
