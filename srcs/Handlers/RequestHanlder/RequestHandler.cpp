/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RequestHandler.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 07:22:35 by codespace         #+#    #+#             */
/*   Updated: 2024/05/31 07:22:24 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RequestHandler.hpp"

/* ***Construction*********************************************************** */

RequestHandler::RequestHandler(int fd){
	_fd = fd;
	VirtualHost		server1 = VirtualHost("127.0.0.1", "8000");
	VirtualHost		server2 = VirtualHost("127.0.0.1", "8001");
	VirtualHost		server3 = VirtualHost("127.0.0.1", "8002");

	std::vector<VirtualHost> virtualHosts = {server1, server2, server3};
	_server = HttpServer::getInstance(virtualHosts);
}

RequestHandler::~RequestHandler(){
}

/* ***Method***************************************************************** */
void copyBuffer(std::vector<char>& destination, const char* source, int size)
{
	destination.assign(source, source + size);
}

#include <iostream>
void RequestHandler::handle()
{
	std::vector<char> buffer;
	char receiveBuffer[BUFFER_SIZE];

	buffer.clear();
	memset(receiveBuffer, '\0', BUFFER_SIZE);

	int bytesReceived = recv(_fd, receiveBuffer, BUFFER_SIZE, 0);
	if (bytesReceived <= 0)
	{
		if (bytesReceived == 0)
		{
			std::cout << "Client disconnected: " << _fd << std::endl;
		}
		std::cout << "error Occured while reading " << std::endl;
		_server->RemoveClient(_fd);
		return;
	}

	copyBuffer(buffer, receiveBuffer, bytesReceived);
	::print(buffer);
	// RequestParser(buffer)
	// if (_server->getClient(_fd).isRequestComplete(buffer))
	// {
		_server->getMultiplex()->Unregister(READ, _fd);
		_server->getMultiplex()->Register(WRITE,_fd);
	// }
}

