/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HttpServer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 10:46:32 by codespace         #+#    #+#             */
/*   Updated: 2024/05/25 12:16:49 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HTTPSERVER_HPP
# define HTTPSERVER_HPP

#include "websrv.hpp"

class HttpServer
{
	private:
	/* ***Attributes*************************************************** */
	
	// ServerConfig _config; that have info aboutVirtualHost;
	static HttpServer 			*_instance;
	std::vector<VirtualHost> 	_virtualHosts;
	/* ***Construction************************************************* */
		
		HttpServer(std::vector<VirtualHost> virtualHosts );
		HttpServer(HttpServer const &copy) = delete;
		HttpServer &operator=(HttpServer const &copy) = delete;
		~HttpServer();
	
	/* ***Method******************************************************* */
	public:
		void 	run();
		void 	stop();
		void	log();
		static HttpServer *getInstance();
		void 	addVirtualHost(const VirtualHost &virtualHost);
};

#endif