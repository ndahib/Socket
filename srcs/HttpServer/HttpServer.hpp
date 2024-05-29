/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HttpServer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 10:46:32 by codespace         #+#    #+#             */
/*   Updated: 2024/05/29 06:48:21 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HTTPSERVER_HPP
# define HTTPSERVER_HPP

#include "websrv.hpp"

#define TIMEOUTS 3000

class HttpServer
{
	private:
	/* ***Attributes*************************************************** */
	
		// ServerConfig _config; that have info aboutVirtualHost;
		IMultiplex					*_multiplex;
		static HttpServer			*_instance;
		std::vector<VirtualHost> 	_virtualHosts;
		std::fstream				_log;
		
	/* ***Construction************************************************* */
		
		HttpServer(std::vector<VirtualHost>& virtualHosts );
		HttpServer(HttpServer const &copy) = delete;
		HttpServer &operator=(HttpServer const &copy) = delete;
		~HttpServer();
	
	/* ***Method******************************************************* */
	public:
		void 				run();
		void 				stop();
		void				log();
		void 				addVirtualHost(const VirtualHost &virtualHost);
		static HttpServer*	getInstance(std::vector<VirtualHost>& virtualHosts);
	private:
		void				Read_Handler(SOCKET fd);
		void				Write_Handler(SOCKET fd);
};

#endif