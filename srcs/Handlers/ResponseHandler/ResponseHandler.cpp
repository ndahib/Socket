/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ResponseHandler.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 07:22:35 by codespace         #+#    #+#             */
/*   Updated: 2024/05/30 06:55:40 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ResponseHandler.hpp"

/* ***Construction*********************************************************** */

#include "websrv.hpp"
ResponseHandler::ResponseHandler(int fd)
{
	_fd = fd;
	_server = NULL;
}

ResponseHandler::~ResponseHandler(){
}

/* ***Method***************************************************************** */

void ResponseHandler::handle(){
	// Send the response to client
	// remove client from write
	// return client to read again
}