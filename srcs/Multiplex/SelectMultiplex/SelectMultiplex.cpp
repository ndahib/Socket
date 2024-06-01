/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SelectMultiplex.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 10:59:16 by codespace         #+#    #+#             */
/*   Updated: 2024/05/31 11:09:01 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SelectMultiplex.hpp"

/* ***Construction*********************************************************** */

SelectMultiplex::SelectMultiplex() {
	FD_ZERO(&_readfds);
	FD_ZERO(&_writefds);
	FD_ZERO(&_copy_readfds);
	FD_ZERO(&_copy_writefds);
	_maxfd = 0;
}

SelectMultiplex::~SelectMultiplex() {
	FD_ZERO(&_readfds);
	FD_ZERO(&_writefds);
	FD_ZERO(&_copy_readfds);
	FD_ZERO(&_copy_writefds);
}


/* ***Methods*************************************************************** */

int	SelectMultiplex::multiplex(long timeout) {
	
	struct timeval tv;
	tv.tv_sec = timeout;
	tv.tv_usec = 0;
	
	_copy_readfds = _readfds;
	_copy_writefds = _writefds;
	return (select(_maxfd + 1, &_copy_readfds, &_copy_writefds, NULL, &tv));
}

void SelectMultiplex::Register(EVENT_TYPE type, SOCKET socket) {
	switch (type)
	{
		case READ:
			FD_SET(socket, &_readfds); break;
		case WRITE:
			FD_SET(socket, &_writefds); break;
	};
	_maxfd = std::max(_maxfd, socket);
}

void	SelectMultiplex::Unregister(EVENT_TYPE type, SOCKET socket) {
	switch (type)
	{
		case READ:
			FD_CLR(socket, &_readfds); break;
		case WRITE:
			FD_CLR(socket, &_writefds); break;
		case READ_WRITE:
			FD_CLR(socket, &_readfds);
			FD_CLR(socket, &_writefds);
			break;
	};
}

bool	SelectMultiplex::isRegistered(EVENT_TYPE type, SOCKET socket) {	
	switch (type)
	{
		case READ:
			return (FD_ISSET(socket, &_copy_readfds));
		case WRITE:
			return (FD_ISSET(socket, &_copy_writefds));
	};
	return (false);
}