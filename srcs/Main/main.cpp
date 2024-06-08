/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahib <ndahib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 08:15:52 by ndahib            #+#    #+#             */
/*   Updated: 2024/06/07 12:04:04 by ndahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HttpServer.hpp"
// void Parsertest()
// {
// 	YAML::Node root;

// 	root = YAML::LoadFile("Ressources/Config/Test.yml");
// 	std::cout << "Loading map is successful" << std::endl;
// 	if (root.IsMap())
// 	{
// 		std::cout << "Our root is a map Structured" << std::endl;
// 		for (YAML::const_iterator it = root.begin(); it != root.end(); ++it)
// 		{
// 			std::cout <<"Node :" << it->first << std::endl;
// 		}
// 	}
// }                                                  


int main(int ac, char **av)
{
	(void)ac;
	HttpServer *DirectorServer = HttpServer::getInstance();
	try{
		if (av[1] != NULL)
			DirectorServer->readConfig(av[1]);
		else
			DirectorServer->readConfig();
		DirectorServer->run();
	}
	catch(YAML::Exception &e)
	{
		std::cout << e.what() << std::endl;
		delete DirectorServer;
	}
	catch(YAML::KeyNotFound &e)
	{
		std::cout << e.what() << std::endl;
		delete DirectorServer;
	}
	catch(YAML::BadFile &e)
	{
		std::cout << e.what() << std::endl;
		delete DirectorServer;
	}
	catch(...)
	{
		std::cout << "Unknown Fatal error in Server , Server will Stop " << std::endl;
		delete DirectorServer;
	};
	return (0);
}