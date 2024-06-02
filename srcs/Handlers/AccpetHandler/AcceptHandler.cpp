/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AcceptHandler.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 07:22:35 by codespace         #+#    #+#             */
/*   Updated: 2024/06/02 09:19:49 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AcceptHandler.hpp"
#include "websrv.hpp"

/* ***Construction*********************************************************** */

AcceptHandler::AcceptHandler(int fd)
{
	_fd = fd;
	_server = HttpServer::getInstance();
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