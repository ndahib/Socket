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

Listener::Listener() {
}


Listener::~Listener(){
	_socket.Close();
}
SOCKET Listener::SetupListener(TcpSocket &socket)
{
	_socket = _socket;
	try{
		_socket.setToLisner();
		_socket.createSocket();
		_socket.seToNonBlocking();
		_socket.setSocketOption(SO_REUSEADDR);
		_socket.Bind();
		_socket.Listen();
	}catch(std::string &e){
		std::cout << e << errno << std::endl;
		_socket.Close();
		return (-1);
	}
	return (_socket.Socket());
}
