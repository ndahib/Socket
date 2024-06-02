/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 06:53:33 by codespace         #+#    #+#             */
/*   Updated: 2024/06/02 06:37:37 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Client.hpp"

/* ***Construction*********************************************************** */

Client::Client(SOCKET socket){
	_socket = socket;
}
Client::Client()
{
}

Client::~Client(){
	// Maybe add something here
	// close(_socket);
	_request.clear();
	std::cout << "Destructor Client" << std::endl;
}

/* ***Method***************************************************************** */
void	Client::parseRequest(std::vector<char> &buffer){
	_request.setup(buffer);
}

void	Client::printRerquest(){
	_request.print();
}

bool	Client::isRequestCompleted() const{
	return (_request.isComplete);
}

void	Client::setRequest(Request &newRequest){
	_request = newRequest;
}

SOCKET	Client::getSocket() const{
	return (_socket);
}

Request	Client::getRequest() const{
	return (_request);
}
