/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HttpServer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 10:58:40 by codespace         #+#    #+#             */
/*   Updated: 2024/05/25 12:19:04 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HttpServer.hpp"

/* ***Construction************************************************************ */

static HttpServer *_instance;
HttpServer::HttpServer(std::vector<VirtualHost> virtualHosts ) : _virtualHosts(virtualHosts)
{
	_instance = this;
}


HttpServer::~HttpServer()
{
	delete _instance;
}

/* ***Method*************************************************************** */
HttpServer *HttpServer::getInstance()
{
	(void)_instance;
	// if (_instance == NULL)
	// 	_instance = new HttpServer();
	return (_instance);
}

void	HttpServer::run()
{
	//Run Server by listeneing and lunch the multiplex
}

void	HttpServer::stop()
{
	// stop the loop of Multiplex
}

void 	HttpServer::log()
{
	// register inforamtion in file log
}

void	HttpServer::addVirtualHost(const VirtualHost& virtualHost)
{
	_virtualHosts.push_back(virtualHost);	
}
