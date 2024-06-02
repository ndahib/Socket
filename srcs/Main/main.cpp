/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 08:15:52 by ndahib            #+#    #+#             */
/*   Updated: 2024/06/02 09:19:17 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HttpServer.hpp"

int main(int ac , char **av)
{
	HttpServer *PtrServer = HttpServer::getInstance();
	try{
		// std::cout << "Server access log and error at /workspaces/Socket/Server.log" << std::endl;
		// PtrServer->log();
		PtrServer->readConfig(av[1]);
		PtrServer->setup();
		std::cout << GREEN << "Server is Running" << END << std::endl;
		PtrServer->run();
	}catch(...)
	{
		delete PtrServer;
	};
	return (0);
}

