/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AcceptHandler.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 07:22:35 by codespace         #+#    #+#             */
/*   Updated: 2024/05/29 10:27:33 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AcceptHandler.hpp"

/* ***Construction*********************************************************** */

AcceptHandler::AcceptHandler(int fd)
{
	_fd = fd;
	_server = nullptr;
}

AcceptHandler::~AcceptHandler(){
}

/* ***Method***************************************************************** */

void AcceptHandler::handle(){
	// try{
	// 	SOCKET newClientFd = _server->getVirtualHost(_fd).accept();
	// 	_server->AddClient(newClientFd);
	// 	_server->getMultiplex()->Register(READ, newClientFd);
	// }catch(...){
	// 	std::cerr << "Error AcceptHandler" << std::endl;
	// }
}