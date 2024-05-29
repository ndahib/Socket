/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IHandler.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 07:25:11 by codespace         #+#    #+#             */
/*   Updated: 2024/05/29 08:15:20 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IHandler.hpp"

/* ***Construction************************************************************ */
IHandler::IHandler(int fd)
{
	//Permentaly
	VirtualHost		server = VirtualHost("127.0.0.1", "8000");
	VirtualHost     server2 = VirtualHost("127.0.0.1", "8001");
	VirtualHost     server3 = VirtualHost("127.0.0.1", "8002");
	std::vector<VirtualHost> virtualHosts = {server, server2, server3};
	_server = HttpServer::getInstance(virtualHosts);

	_fd = fd;
}

IHandler::~IHandler()
{
	_server->stop();
}
	
