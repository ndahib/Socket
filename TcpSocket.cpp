/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TcpSocket.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahib <ndahib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 13:11:53 by ndahib            #+#    #+#             */
/*   Updated: 2024/05/11 15:49:40 by ndahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TcpSocket.hpp"

/* ************************************************************************** */
TCPSocket::TCPSocket(){}
TCPSocket::TCPSocket(const ISocket &obj){}
TCPSocket &TCPSocket::operator=(const ISocket &obj){}

/* ******************************Constructor********************************** */

TCPSocket::TCPSocket(const char* Ip, const char*  port) : ISocket(Ip, port){
	struct addrinfo hints;
	memset(&hints, '\0', sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;

	getaddrinfo(Ip, port, &hints, &_AddrToBind);
}
TCPSocket::~TCPSocket(){
	freeaddrinfo(_AddrToBind);
}

/* **********************************Method*********************************** */
void	TCPSocket::createSocket(){
	_Socket = socket(_AddrToBind->ai_family, _AddrToBind->ai_socktype, _AddrToBind->ai_protocol);
	if (!ISVALIDSOCKET(_Socket))
		throw(std::string("Creating Socket error"));
}
void	TCPSocket::Bind(){
	if(bind(_Socket, _AddrToBind->ai_addr, _AddrToBind->ai_addrlen) < 0)
		throw(std::string ("Bind error"));
	_isBound = true;
}

void	TCPSocket::Listen(){
	if (listen(_Socket, BACKLOG) == -1)
		throw(std::string("Listen Error"));
	_isListening = true;
}

void	TCPSocket::Accept(){
	int newfd = accept(_Socket , NULL, NULL);
	if (newfd == -1)
		throw( std::string ("Accept error"));
	ClientsAccpeted.push_back(newfd);
}

void	TCPSocket::Close(){
	close(_Socket);
}
void	TCPSocket::setToreuseAddr(){
	int reusaddr = 1;
	if(setsockopt(_Socket, SOL_SOCKET, SO_REUSEADDR, &reusaddr, sizeof(reusaddr)) < 0)
		throw std::string("setsockopt error");
}

void	TCPSocket::seToNonBlocking(){
	_isBlocking = fcntl(_Socket, F_SETFL, O_NONBLOCK);
	if (_isBlocking == -1)
		throw std::string("fcntl error");
}

void	TCPSocket::setToLisner(){
	_isListener = true;
}

/* **********************************Getters*********************************** */
SOCKET  TCPSocket::Socket() const{
	return (_Socket);
}
int	    TCPSocket::getPort() const{
	return (std::atoi(_Port));
}
int TCPSocket::getBufferSize() const{
	return (_bytesReceived);
}
bool    TCPSocket::isListener() const{
	return (_isListener);
}
// std::vector<char> 	TCPSocket::getBufferReceived() const;

/* **********************************Check*********************************** */
bool	TCPSocket::isBound() const{
	return (_isBound);
}
bool	TCPSocket::isClosed() const{
	(ISVALIDSOCKET(_Socket) ? false : true);
}
bool	TCPSocket::isListening() const{
	return (_isListening);
}
bool	TCPSocket::isListenerSocket() const{
	return (_isListener);
}
bool	TCPSocket::isBlocking() const{
	return (_isBlocking);
}
