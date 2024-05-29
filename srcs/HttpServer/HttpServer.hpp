/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HttpServer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 10:46:32 by codespace         #+#    #+#             */
/*   Updated: 2024/05/29 12:07:03 by codespace        ###   ########.fr       */
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
		IHandler					*_handler;
		std::fstream				_log;
		static HttpServer			*_instance;
		std::map <SOCKET, Client>	_clients;
		std::vector<VirtualHost > 	_virtualHosts;
		
		
	/* ***Construction************************************************* */
		
		HttpServer(std::vector<VirtualHost>	&virtualHosts );
		HttpServer(HttpServer const &copy) = delete;
		HttpServer &operator=(HttpServer const &copy) = delete;
		~HttpServer();
	
	/* ***Method******************************************************* */
	public:
		void 				run();
		void 				stop();
		void				log();
		void 				addVirtualHost(const VirtualHost &virtualHost);
		void				AddClient(SOCKET clientFd);
		void				RemoveClient(SOCKET fd);
		void				SetHandler(IHandler *handler);
		VirtualHost			getVirtualHost(SOCKET fd) const;
		IMultiplex*			getMultiplex() const ;
		static HttpServer*	getInstance();
		
		static HttpServer*	getInstance(std::vector<VirtualHost>& virtualHosts);
};

#endif