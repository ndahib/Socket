/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ResponseHandler.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 07:22:35 by codespace         #+#    #+#             */
/*   Updated: 2024/05/29 08:24:46 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ResponseHandler.hpp"

/* ***Construction*********************************************************** */

ResponseHandler::ResponseHandler(int fd) : IHandler(fd){
	
}

ResponseHandler::~ResponseHandler(){-
}

/* ***Method***************************************************************** */

void ResponseHandler::handle(){
    // Send the response to client
}