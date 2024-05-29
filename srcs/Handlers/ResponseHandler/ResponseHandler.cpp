/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ResponseHandler.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 07:22:35 by codespace         #+#    #+#             */
/*   Updated: 2024/05/29 10:36:08 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ResponseHandler.hpp"

/* ***Construction*********************************************************** */

ResponseHandler::ResponseHandler(int fd) : _fd(fd)
{
	_server = nullptr;
}

ResponseHandler::~ResponseHandler(){
}

/* ***Method***************************************************************** */

void ResponseHandler::handle(){
	// Send the response to client
	// remove client from write
	// return client to read again
}