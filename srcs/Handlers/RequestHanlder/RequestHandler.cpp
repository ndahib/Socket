/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RequestHandler.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 07:22:35 by codespace         #+#    #+#             */
/*   Updated: 2024/06/02 09:20:04 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RequestHandler.hpp"

/* ***Construction*********************************************************** */

RequestHandler::RequestHandler(int fd){
	_fd = fd;
	_server = HttpServer::getInstance();
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

	int bytesReceived = recv(_server->getClient(_fd).getSocket(), receiveBuffer, BUFFER_SIZE, 0);
	if (bytesReceived <= 0)
	{
		if (bytesReceived == 0)
		{
			std::cout << "_server->getClient(_fd) disconnected: " << _fd << std::endl;
		}
		std::cout << "error Occured while reading " << std::endl;
		_server->RemoveClient(_fd);
		return;
	}

	copyBuffer(buffer, receiveBuffer, bytesReceived);
	_server->getClient(_fd).parseRequest(buffer);
	_server->getClient(_fd).printRerquest();
	if (_server->getClient(_fd).isRequestCompleted() == true)
	{
		_server->getClient(_fd).printRerquest();
		std::cout << "Enter here to test if Complete" << std::endl;
		_server->getMultiplex()->Unregister(READ, _server->getClient(_fd).getSocket());
		_server->getMultiplex()->Register(WRITE,_server->getClient(_fd).getSocket());
	}
}

