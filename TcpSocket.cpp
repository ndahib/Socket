/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TcpSocket.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahib <ndahib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 13:11:53 by ndahib            #+#    #+#             */
/*   Updated: 2024/05/12 13:10:26 by ndahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TcpSocket.hpp"

/* ************************************************************************** */
TcpSocket::TcpSocket(){}
TcpSocket::TcpSocket(const TcpSocket &obj){
	_Socket = obj._Socket;
	_isBound = obj._isBound;
	_isClosed = obj._isClosed;
	_isListener = obj._isListener;
	_isBlocking = obj._isBlocking;
	_bytesReceived = obj._bytesReceived;
	_bytesSent = obj._bytesReceived;
	_Port = obj._Port;
	_Ip = obj._Ip;
	
	if (std::atoi(_Port) < 1024 || std::atoi(_Port) > 65535)
	{
		throw(TcpSocket::GeneralError("Please , Use ports between 1024 and 65535 :) "));
	}

	struct addrinfo hints;
	memset(&hints, '\0', sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;

	getaddrinfo(_Ip, _Port, &hints, &_AddrToBind);
}
TcpSocket &TcpSocket::operator=(const TcpSocket &obj){
	(void)obj;
	return (*this);
}

/* ******************************Constructor********************************** */

TcpSocket::TcpSocket(const char* Ip, const char*  port) : _Ip(Ip), _Port(port){

 	_Socket = -1;
	_isBound = false;
	_isClosed = false;
	_isListener = false;
	_isBlocking = false;
	_bytesReceived = 0;
	_bytesSent = 0;

	struct addrinfo hints;
	memset(&hints, '\0', sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;
	getaddrinfo(Ip, port, &hints, &_AddrToBind);
}

TcpSocket::~TcpSocket(){
	if (_AddrToBind != NULL)
		freeaddrinfo(_AddrToBind);
}

/* **********************************Method*********************************** */
void	TcpSocket::createSocket(){
	_Socket = socket(_AddrToBind->ai_family, _AddrToBind->ai_socktype, _AddrToBind->ai_protocol);
	if (!ISVALIDSOCKET(_Socket))
		throw(TcpSocket::SocketExeption());
}

void	TcpSocket::Bind(){
	if(bind(_Socket, _AddrToBind->ai_addr, _AddrToBind->ai_addrlen) < 0)
		throw(TcpSocket::BindException());
	_isBound = true;
}

void	TcpSocket::Listen(){
	if (listen(_Socket, BACKLOG) == -1)
		throw(TcpSocket::ListenException());
	_isListening = true;
}

void	TcpSocket::Accept(){
	int newfd = accept(_Socket , NULL, NULL);
	if (newfd == -1)
		throw (TcpSocket::AcceptExcption());
	ClientsAccpeted.push_back(newfd);
}

void	TcpSocket::Close(){
	close(_Socket);
}
void	TcpSocket::setSocketOption(int Flag){
	int reusaddr = 1;
	if(setsockopt(_Socket, SOL_SOCKET, Flag, &reusaddr, sizeof(reusaddr)) < 0)
		throw (TcpSocket::SocketExeption());
}

void	TcpSocket::seToNonBlocking(){
	if (fcntl(_Socket, F_SETFL, O_NONBLOCK) < 0)
		throw (TcpSocket::AcceptExcption());
	_isBlocking = true;
}

void	TcpSocket::setToLisner(){
	_isListener = true;
}

/* **********************************Getters*********************************** */
SOCKET  TcpSocket::Socket() const{
	return (_Socket);
}
int	    TcpSocket::getPort() const{
	return (std::atoi(_Port));
}
int TcpSocket::getBufferSize() const{
	return (_bytesReceived);
}
bool    TcpSocket::isListener() const{
	return (_isListener);
}
// std::vector<char> 	TcpSocket::getBufferReceived() const;

/* **********************************Check*********************************** */
bool	TcpSocket::isBound() const{
	return (_isBound);
}
bool	TcpSocket::isClosed() const{
	return ((ISVALIDSOCKET(_Socket) ? false : true));
}
bool	TcpSocket::isListening() const{
	return (_isListening);
}
bool	TcpSocket::isListenerSocket() const{
	return (_isListener);
}
bool	TcpSocket::isBlocking() const{
	return (_isBlocking);
}


/* ********************************Exception********************************** */
char const *TcpSocket::SocketExeption::what(){
	std::string error = "Socket failure: " ;
	error +=  std::strerror(errno);
	return (error.c_str());
}

char const *TcpSocket::BindException::what(){
	std::string error = "Bind failure: " ;
	error +=  std::strerror(errno);
	return (error.c_str());
}

char const *TcpSocket::ConnectExeption::what(){
	std::string error = "Connect failure: " ;
	error +=  std::strerror(errno);
	return (error.c_str());
}

char const *TcpSocket::ListenException::what(){
	std::string error = "Listen failure: " ;
	error +=  std::strerror(errno);
	return (error.c_str());
}

char const *TcpSocket::AcceptExcption::what(){
	std::string error = "Accept failure: " ;
	error +=  std::strerror(errno);
	return (error.c_str());
}

TcpSocket::GeneralError::GeneralError(std::string strError)
{
	this->strError = strError;
}

const char *TcpSocket::GeneralError::what() const throw() {
	strError += std::strerror(errno);
	return (this->strError.c_str());
}