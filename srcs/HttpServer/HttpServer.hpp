/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HttpServer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahib <ndahib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 10:46:32 by codespace         #+#    #+#             */
/*   Updated: 2024/06/07 10:33:39 by ndahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HTTPSERVER_HPP
# define HTTPSERVER_HPP

#include "Client.hpp"
#include "VirtualHost.hpp"
# include "TcpSocket.hpp"
# include "IMultiplex.hpp"
# include "IHandler.hpp"
#include "AcceptHandler.hpp"
# include "RequestHandler.hpp"
# include "ResponseHandler.hpp"
# include "SelectMultiplex.hpp"
# include "ConfigParser.hpp"

#define TIMEOUTS 5

class HttpServer
{
	private:
	/* ***Attributes*************************************************** */
	
		// ServerConfig _config; that have info aboutVirtualHost;
		ConfigParser 				_config;
		IHandler					*_handler;
		IMultiplex					*_multiplex;
		std::fstream				_log;
		static HttpServer			*_instance;
		std::map <SOCKET, Client>	_clients;
		std::vector<VirtualHost > 	_virtualHosts;
		
		
	/* ***Construction************************************************* */
		
		HttpServer();
		HttpServer(HttpServer const &copy){(void)copy;}; // To change by delete
		HttpServer &operator=(HttpServer const &copy)
		{
			(void)copy;
			return (*this);
		};
	
	/* ***Method******************************************************* */
	public:
		void 				readConfig(const char *config_file = DEFAULT_CONFIG);
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