/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AcceptHandler.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 07:22:35 by codespace         #+#    #+#             */
/*   Updated: 2024/05/31 09:20:20 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AcceptHandler.hpp"
#include "websrv.hpp"

/* ***Construction*********************************************************** */

AcceptHandler::AcceptHandler(int fd)
{
	_fd = fd;
	VirtualHost		server1 = VirtualHost("127.0.0.1", "8000");
	VirtualHost		server2 = VirtualHost("127.0.0.1", "8001");
	VirtualHost		server3 = VirtualHost("127.0.0.1", "8002");

	std::vector<VirtualHost> virtualHosts = {server1, server2, server3};
	_server = HttpServer::getInstance(virtualHosts);
}

AcceptHandler::~AcceptHandler(){
}

/* ***Method***************************************************************** */

void AcceptHandler::handle(){
	try{
		SOCKET newClientFd = _server->getVirtualHost(_fd).accept();
		std::cout << "Socket Accepted : " << newClientFd << std::endl;
		_server->AddClient(newClientFd);
	}catch(std::string &s){
		_server->getMultiplex()->Unregister(READ_WRITE, _fd);
		std::cout << s << std::endl;
	}
}