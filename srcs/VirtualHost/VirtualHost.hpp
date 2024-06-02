/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VirtualHost.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 08:45:41 by codespace         #+#    #+#             */
/*   Updated: 2024/06/02 08:39:21 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIRTUALHOST_HPP
# define VIRTUALHOST_HPP

/* Includes ***************************************************************** */
#include "TcpSocket.hpp"
#include "ConfigDataStructures.hpp"
class VirtualHost
{
	private:
		/* *******Attributes****************************************** */
		long 			_client_max_body_size;
		bool 			_autoindex;
		SOCKET			_socket;
		const char*		_ip;
		const char*		_port;
		t_listen		_listen;
		std::string 	_root;
		std::string		_index;
		std::string		_server_name;
		// Addd Location : std::vector<struct Location>

	public:
		/* *******Constructors and Destructors************************* */
		VirtualHost(const t_listen &listen);
		~VirtualHost();
		/* *******Methods********************************************** */
		SOCKET		SetupServer();
		SOCKET		accept();
		void		print();

		/* *******Getters and Setters********************************** */
		
		void			set_ip(const char* ip);
		void			set_port(const char* port);
		void			set_server_name(std::string server_name);
		void			set_client_max_body_size(long client_max_body_size);
		void			set_autoindex(bool autoindex);
		void			set_root(std::string root);
		void			set_index(std::string index);
	
		int				get_client_max_body_size() const;
		bool			get_autoindex() const;
		SOCKET			get_socket() const ;
		const char*		get_ip() const;
		const char*		get_port() const;
		std::string		get_root() const;
		std::string		get_index() const ;
		std::string		get_server_name() const;
};

#endif