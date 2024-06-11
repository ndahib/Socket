/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VirtualHost.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahib <ndahib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 08:45:41 by codespace         #+#    #+#             */
/*   Updated: 2024/06/11 10:41:25 by ndahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIRTUALHOST_HPP
# define VIRTUALHOST_HPP

#include "ConfigParser.hpp"

typedef struct s_listen
{
	int Ip;
	int Port;
}	t_listen;

/* Includes ***************************************************************** */
#include "TcpSocket.hpp"
class VirtualHost
{
	private:
		/* *******Attributes****************************************** */
		long 								_client_max_body_size;
		bool 								_autoindex;
		SOCKET								_socket;
		const char*							_ip;
		const char*							_port;
		std::string 						_root;
		std::string							_index;
		std::string							_server_name;
		std::vector<t_listen>				_listen;
		std::vector<std::string>			_allowed_methods;
		std::map<std::string, std::string>	_location_directives;
		std::map<std::string, std::string>	_error_pages;

	public:
		/* *******Constructors and Destructors************************* */
		VirtualHost(std::map<std::string, YAML::Node> directives);
		~VirtualHost();
		/* *******Methods********************************************** */
		SOCKET		SetupServer();
		SOCKET		accept();
		void		print();

		/* *******Getters and Setters********************************** */
		int				get_client_max_body_size() const;
		bool			get_autoindex() const;
		const char*		get_ip() const;
		const char*		get_port() const;
		std::string		get_root() const;
		std::string		get_index() const ;
		std::string		get_server_name() const;
		SOCKET			get_socket(t_listen listen) const ;
	// private:
		
	// 	void			set_root(std::string root);
	// 	void			set_index(std::string index);
	// 	void			set_autoindex(bool autoindex);
	// 	void			set_server_name(std::string server_name);
	// 	void			set_listen(std::vector<t_listen> listen);
	// 	void			set_client_max_body_size(long client_max_body_size);
	// 	void			set_alowed_methods(std::vector<std::string> allowed_methods);
	// 	void			set_error_pages(std::map<std::string, std::string> error_pages);
	// 	void			set_location_directives(std::map<std::string, std::string> location_directives);
};

#endif