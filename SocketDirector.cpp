/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SocketDirector.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahib <ndahib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 15:17:59 by ndahib            #+#    #+#             */
/*   Updated: 2024/05/12 10:31:12 by ndahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SocketDirector.hpp"

SocketDirector::SocketDirector(const TcpSocket &socketBuilder) : _socketBuilder(socketBuilder) {
}


SocketDirector::~SocketDirector(){
	_socketBuilder.Close();
}
SOCKET SocketDirector::SetupServer()
{
	try{
		_socketBuilder.setToLisner();
		_socketBuilder.createSocket();
		_socketBuilder.seToNonBlocking();
		_socketBuilder.setSocketOption(SO_REUSEADDR);
		_socketBuilder.Bind();
		_socketBuilder.Listen();
	}catch(std::string &e){
		std::cout << e << errno << std::endl;
		_socketBuilder.Close();
		return (-1);
	}
	return (_socketBuilder.Socket());
}

SOCKET SocketDirector::SetupClient()
{
	try{
		_socketBuilder.createSocket();
		_socketBuilder.seToNonBlocking();
		_socketBuilder.setSocketOption(SO_REUSEADDR);
		_socketBuilder.Bind();
	}catch(std::string &e)
	{
		std::cout << e << errno << std::endl;
		_socketBuilder.Close();
		return (-1);
	}
	return (_socketBuilder.Socket());
}

// void	SocketDirector::HandleServerConnection()
// {
	
// }