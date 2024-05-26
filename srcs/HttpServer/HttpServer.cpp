/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HttpServer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 10:58:40 by codespace         #+#    #+#             */
/*   Updated: 2024/05/26 11:55:53 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HttpServer.hpp"

/* ***Construction************************************************************ */

HttpServer* HttpServer::_instance = nullptr;
HttpServer::HttpServer(std::vector<VirtualHost>& virtualHosts ) : _virtualHosts(virtualHosts)
{
	_multiplex = new SelectMultiplex();
	_instance = this;
}


HttpServer::~HttpServer()
{
	delete _instance;
	_log.close();
}

/* ***Method*************************************************************** */
HttpServer *HttpServer::getInstance(std::vector<VirtualHost>& virtualHosts)
{
	if (_instance == NULL || _instance->_virtualHosts.size() != virtualHosts.size())
		_instance = new HttpServer(virtualHosts);
	return (_instance);
}

void	HttpServer::run()
{
	for (size_t i = 0; i < _virtualHosts.size(); i++){
		_virtualHosts[i].SetupServer();
	}
	IMultiplex *selectMx = new SelectMultiplex();
	while (true)
	{
		selectMx->multiplex(1000);
		if (selectMx->isRegistered(READ, _virtualHosts[0].get_socket()))
		{
			//Hnadle Read 
			std::cout << _virtualHosts[0].get_socket() << "Read Data" << std::endl;
		}
		else if (selectMx->isRegistered(READ, _virtualHosts[1].get_socket()))
			//Handle Write
	}
}

void	HttpServer::stop()
{
	//stop Server
}

void	HttpServer::log()
{
	_log.open("Server.log");
	
	std::streambuf *coutBuffer = std::cout.rdbuf();
	std::cout.rdbuf(_log.rdbuf());
	std::cout << "Server access log and error at web/Server.log" << std::endl;
}

void	HttpServer::addVirtualHost(const VirtualHost& virtualHost)
{
	_virtualHosts.push_back(virtualHost);	
}
