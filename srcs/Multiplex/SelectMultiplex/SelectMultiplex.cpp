/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SelectMultiplex.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 10:59:16 by codespace         #+#    #+#             */
/*   Updated: 2024/05/26 11:27:00 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SelectMultiplex.hpp"

/* ***Construction*********************************************************** */

SelectMultiplex::SelectMultiplex() {
	FD_ZERO(&_readfds);
	FD_ZERO(&_writefds);
}

SelectMultiplex::~SelectMultiplex() {
	//Clear Set and close all file descriptors
	//registred in SelectMultiplex
}


/* ***Methods*************************************************************** */

void SelectMultiplex::multiplex(long timeout) {

	struct timeval tv;
	tv.tv_sec = timeout;
	tv.tv_usec = 0;
	int ret = select(0, &_readfds, &_writefds, nullptr, &tv);
	if (ret < 0) {
		// throw SelectMultiplexException();
	}
}

void SelectMultiplex::Register(EVENT_TYPE type, SOCKET socket) {
	switch (type)
	{
		case READ:
			FD_SET(socket, &_readfds); break;
		case WRITE:
			FD_SET(socket, &_writefds); break;
		case READ_WRITE:
			FD_SET(socket, &_readfds);
			FD_SET(socket, &_writefds);
			break;
	};
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
			return (FD_ISSET(socket, &_readfds));
		case WRITE:
			return (FD_ISSET(socket, &_writefds));
		case READ_WRITE:
			return (FD_ISSET(socket, &_readfds) && FD_ISSET(socket, &_writefds));
	};
	return (false);
}