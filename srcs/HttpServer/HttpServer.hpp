/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HttpServer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 10:46:32 by codespace         #+#    #+#             */
/*   Updated: 2024/06/02 10:08:04 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HTTPSERVER_HPP
# define HTTPSERVER_HPP

#include "Config.hpp"
#include "Client.hpp"
#include "VirtualHost.hpp"

#define TIMEOUTS 5

class HttpServer
{
	private:
	/* ***Attributes*************************************************** */
	
		// ServerConfig _config; that have info aboutVirtualHost;
		Config 						_config;
		IHandler					*_handler;
		IMultiplex					*_multiplex;
		std::fstream				_log;
		static HttpServer			*_instance;
		std::map <SOCKET, Client>	_clients;
		std::vector<VirtualHost > 	_virtualHosts;
		
		
	/* ***Construction************************************************* */
		
		HttpServer();
		HttpServer(HttpServer const &copy) = delete;
		HttpServer &operator=(HttpServer const &copy) = delete;
	
	/* ***Method******************************************************* */
	public:
		void 				readConfig(const char *config_file);
		void				setup();
		void 				run();
		void 				stop();
		void				log();
		void				RemoveClient(SOCKET fd);
		void				AddClient(SOCKET clientFd);
		void				SetHandler(IHandler *handler);
		bool 				isVertualHostExist(SOCKET fd) const;
		void 				addVirtualHost(const VirtualHost &virtualHost);
		void				SetHandler(SOCKET fd, IMultiplex::EVENT_TYPE type);
		Client&				getClient(SOCKET clientFd);
		VirtualHost			getVirtualHost(SOCKET fd) const;
		IMultiplex*			getMultiplex() const ;
		static HttpServer*	getInstance();
	/* ***Destructor*************************************************** */
		~HttpServer();
};

#endif