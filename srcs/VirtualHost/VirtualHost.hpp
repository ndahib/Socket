/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VirtualHost.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 08:45:41 by codespace         #+#    #+#             */
/*   Updated: 2024/05/25 09:44:18 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIRTUALHOST_HPP
# define VIRTUALHOST_HPP

#include "websrv.hpp"
class VirtualHost
{
	private:
		/* *******Attributes****************************************** */
		const char*	_ip;
		const char*	_port;
		std::string	_server_name;
		long client_max_body_size;
		bool autoindex;
		std::string root;
		std::string	index;
		// Addd Location : std::vector<struct Location>

	public:
		/* *******Constructors and Destructors************************* */
		VirtualHost(const char *ip, const char *port);
		~VirtualHost();
		/* *******Methods********************************************** */
		SOCKET		SetupServer();
		void		print();

		/* *******Getters and Setters********************************** */
		
		void		set_ip(const char* ip);
		void		set_port(const char* port);
		void		set_server_name(std::string server_name);
		void		set_client_max_body_size(long client_max_body_size);
		void		set_autoindex(bool autoindex);
		void		set_root(std::string root);
		void		set_index(std::string index);
	
		int			get_client_max_body_size();
		bool		get_autoindex();
		const char*	get_ip();
		const char*	get_port();
		std::string	get_root();
		std::string	get_index();
		std::string	get_server_name();	
};

#endif