/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SocketDirector.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahib <ndahib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 15:17:59 by ndahib            #+#    #+#             */
/*   Updated: 2024/05/11 15:50:05 by ndahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SocketDirector.hpp"

SocketDirector::SocketDirector(ISocket* socketBuilder){
	
}

SOCKET SocketDirector::buildServer()
{
	_socketBuilder->setToLisner();
	_socketBuilder->createSocket();
	_socketBuilder->seToNonBlocking();
	_socketBuilder->setSocketOption();
	_socketBuilder->Bind();
	_socketBuilder->Listen();
	return (_socketBuilder->Socket());
}



