/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VirtualHost.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 09:19:33 by codespace         #+#    #+#             */
/*   Updated: 2024/05/28 11:26:20 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "VirtualHost.hpp"


/* *******Constructors and Destructors************************************** */
VirtualHost::VirtualHost(const char *ip, const char *port) {
	this->set_ip(ip);
	this->set_port(port);
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

void        VirtualHost::set_index(std::string index){
	this->_index = index;
}

int         VirtualHost::get_client_max_body_size(){
	return this->_client_max_body_size;
}

bool        VirtualHost::get_autoindex(){
	return this->_autoindex; 
}

const char* VirtualHost::get_ip(){
	return this->_ip;
}

const char* VirtualHost::get_port(){
	return this->_port;
}

std::string VirtualHost::get_server_name(){
	return this->_server_name;
}

std::string VirtualHost::get_root(){
	return this->_root;
}

std::string VirtualHost::get_index(){
	return this->_index;
}

SOCKET     VirtualHost::get_socket(){
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
	}catch(std::string &e){
		std::cout << e << errno << std::endl;
		socket.Close();
	}
	_socket = socket.Socket();
	return (_socket);
}