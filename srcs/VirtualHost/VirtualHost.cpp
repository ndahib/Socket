/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VirtualHost.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 09:19:33 by codespace         #+#    #+#             */
/*   Updated: 2024/06/02 09:25:25 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "VirtualHost.hpp"


/* *******Constructors and Destructors************************************** */
VirtualHost::VirtualHost(const t_listen &listen) {
	_listen = listen;
	// this->set_ip((_listen.Ip).to_string());
	// this->set_port(_listen.Port);
	this->set_server_name("localhost");
	this->set_client_max_body_size(1000000);
	this->set_autoindex(false);
	this->set_root("/");
	this->set_index("index.html");
}

VirtualHost::~VirtualHost() {
}

/* *******Getters and Setters*********************************************** */

void		VirtualHost::set_ip(const char* ip){
	this->_ip = ip;
}

void		VirtualHost::set_port(const char* port){
	this->_port = port;
}

void        VirtualHost::set_server_name(std::string server_name){
	this->_server_name = server_name;
}

void        VirtualHost::set_client_max_body_size(long client_max_body_size){   
	this->_client_max_body_size = client_max_body_size;
}

void        VirtualHost::set_autoindex(bool autoindex){
	this->_autoindex = autoindex;
}

void        VirtualHost::set_root(std::string root){
	this->_root = root;
}

void        VirtualHost::set_index(std::string index)  {
	this->_index = index;
}

int         VirtualHost::get_client_max_body_size() const {
	return this->_client_max_body_size;
}

bool        VirtualHost::get_autoindex() const {
	return this->_autoindex; 
}

const char* VirtualHost::get_ip() const {
	return this->_ip;
}

const char* VirtualHost::get_port() const {
	return this->_port;
}

std::string VirtualHost::get_server_name() const {
	return this->_server_name;
}

std::string VirtualHost::get_root() const {
	return this->_root;
}

std::string VirtualHost::get_index() const {
	return this->_index;
}

SOCKET     VirtualHost::get_socket() const {
	return this->_socket;
}

/* *******Printer************************************************************* */


void        VirtualHost::print(){
	std::cout << "ip : " << this->get_ip() << std::endl;
	std::cout << "port : " << this->get_port() << std::endl;
	std::cout << "server_name : " << this->get_server_name() << std::endl;
	std::cout << "client_max_body_size : " << this->get_client_max_body_size() << std::endl;
	std::cout << "autoindex : " << this->get_autoindex() << std::endl;
	std::cout << "root : " << this->get_root() << std::endl;
	std::cout << "index : " << this->get_index() << std::endl;
}


/* *******SetupServer*********************************************************/

SOCKET		VirtualHost::SetupServer(){
	
	TcpSocket socket = TcpSocket(this->get_ip(), this->get_port());
	try{
		socket.setToLisner();
		socket.createSocket();
		socket.seToNonBlocking();
		socket.setSocketOption(SO_REUSEADDR);
		socket.Bind();
		socket.Listen();
	}catch(std::exception &e){
		std::cout << e.what() << errno << std::endl;
		socket.Close();
	}
	_socket = socket.Socket();
	return (_socket);
}

SOCKET VirtualHost::accept() {
	SOCKET NewAccpet = ::accept(_socket, NULL, NULL);
	if (ISVALIDSOCKET(NewAccpet) == false)
		throw(std::string("accept error : ") + strerror(errno) + std::string(" ") + std::to_string(_socket));
	return (NewAccpet);
}
	