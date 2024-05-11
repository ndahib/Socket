/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ISocket.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahib <ndahib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 13:49:05 by ndahib            #+#    #+#             */
/*   Updated: 2024/05/11 15:17:03 by ndahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ISocket.hpp"

ISocket::ISocket(const char* Ip, const char*  port, bool isListener): _Ip(Ip), _Port(port), _isListener(isListener) {
 	_Socket = -1;
	_isBound = false;
	_isClosed = false;
	_isListener = false;
	_isBlocking = false;
	_bytesReceived = 0;
	_bytesSent = 0;
}

ISocket::ISocket(){}
ISocket::ISocket(const ISocket &obj){}
ISocket &ISocket::operator=(const ISocket &obj){}
