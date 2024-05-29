/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RequestHandler.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 07:22:35 by codespace         #+#    #+#             */
/*   Updated: 2024/05/29 11:21:13 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RequestHandler.hpp"

/* ***Construction*********************************************************** */

RequestHandler::RequestHandler(int fd){
	_fd = fd;
	_server = nullptr; // To be Changed
}

RequestHandler::~RequestHandler(){
}

/* ***Method***************************************************************** */

void RequestHandler::handle(){
	// Read the buffer send by the client
	// Parse the request
	// if Parsed is Ok or is Finished
	// register in Multiplex to write 
	// if error
	// delete him
}