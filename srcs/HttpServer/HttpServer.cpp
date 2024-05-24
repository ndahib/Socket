/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HttpServer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 07:27:00 by codespace         #+#    #+#             */
/*   Updated: 2024/05/24 08:37:50 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HttpServer.hpp"

/* *****Constructors and Destructors**************************************** */

HttpServer::HttpServer()
{
	std::cout << "The server is up and running" << std::endl;	
}

HttpServer::~HttpServer()
{
	std::cout << "The server is down" << std::endl;
}

HttpServer::HttpServer(const HttpServer &other)
{
	(void)other;
}

HttpServer& HttpServer::operator=(const HttpServer &other){(void)other;
	return(*this);}

/* *****Methods************************************************************* */
void	HttpServer::launchListeners(){
	for (int i = 0; i < 10; i++)
	{
		TcpSocket socket = TcpSocket("127.0.0.1", "8080");
		Listener::SetupListener(socket);
	}
}