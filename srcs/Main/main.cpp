/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 08:15:52 by ndahib            #+#    #+#             */
/*   Updated: 2024/05/28 09:45:13 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "websrv.hpp"
#include "HttpServer.hpp"

int main()
{
	VirtualHost		server1 = VirtualHost("127.0.0.1", "8000");
	VirtualHost		server2 = VirtualHost("127.0.0.1", "8001");
	VirtualHost		server3 = VirtualHost("127.0.0.1", "8002");

	std::vector<VirtualHost> virtualHosts = {server1, server2, server3};
	HttpServer *PtrServer = HttpServer::getInstance(virtualHosts);
	std::cout << GREEN << "Server is Running" << END << std::endl;
	// std::cout << "Server access log and error at /workspaces/Socket/Server.log" << std::endl;
	// PtrServer->log();

	PtrServer->run();
}

