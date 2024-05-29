/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AcceptHandler.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 07:22:35 by codespace         #+#    #+#             */
/*   Updated: 2024/05/29 08:18:31 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AcceptHandler.hpp"

/* ***Construction*********************************************************** */

AcceptHandler::AcceptHandler(int fd) : IHandler(fd){
	
}

AcceptHandler::~AcceptHandler(){
}

/* ***Method***************************************************************** */

void AcceptHandler::handle(){
	//  ACcpet client and add him to the pool
	//  set to Non Blocking
	// register him in multiplex 
	// if error
	// delete him 
}