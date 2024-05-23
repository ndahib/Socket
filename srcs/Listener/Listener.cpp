/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Listener.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahib <ndahib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 15:17:59 by ndahib            #+#    #+#             */
/*   Updated: 2024/05/12 10:31:12 by ndahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Listener.hpp"

TcpSocket Listener::_socket; // Defenition for static member
Listener::Listener() {
}


Listener::~Listener(){
	_socket.Close();
}

SOCKET Listener::SetupListener(TcpSocket &socket)
{
	_socket = socket;
	try{
		_socket.setToLisner();
		std::cout << "Setting to Listener" << std::endl;
		_socket.createSocket();
		std::cout << "Creating SOcket" << std::endl;
		// _socket.seToNonBlocking();
		std::cout << "Setting to Non Blcoking" << std::endl;
		// _socket.setSocketOption(SO_REUSEADDR);
		std::cout << "Binding" << std::endl;
		// _socket.Bind();
		std::cout << "LIstening" << std::endl;
		// _socket.Listen();
	}catch(std::string &e){
		std::cout << e << errno << std::endl;
		_socket.Close();
	}
	return (_socket.Socket());
}
