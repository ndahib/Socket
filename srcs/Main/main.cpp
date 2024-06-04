/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahib <ndahib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 08:15:52 by ndahib            #+#    #+#             */
/*   Updated: 2024/06/04 11:11:53 by ndahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <yaml-cpp/yaml.h>


void Parsertest()
{
	YAML::Node root;

	root = YAML::LoadFile("Yaml/Test.yml");
	std::cout << "Loading map is successful" << std::endl;
	if (root.IsMap())
	{
		std::cout << "Our root is a map Structured" << std::endl;
		for (YAML::const_iterator it = root.begin(); it != root.end(); ++it)
		{
			std::cout <<"Node :" << it->first << ": " << it->second << std::endl;
		}
	}
} r                                                         

void testLoginFile()
{
	YAML::Node config = YAML::LoadFile("Yaml/Login.yaml");

	const std::string username = config["username"].as<std::string>();
	const std::string password = config["password"].as<std::string>();

	std::cout << "Username : " << username << std::endl;
	std::cout  << "Password: " << password << std::endl;
}

void testConfigServer()
{
	try{
		YAML::Node config = YAML::LoadFile("Yaml/config.yaml");
		{
			if (config["server"])
			{
				std::cout << "The Server :" << std::endl;
			}
			const std::string host = config["server"]["host"].as<std::string>();
			const std::string index = config["server"]["index"].as<std::string>();
			const int port = config["server"]["port"].as<int>();
			std::cout << "Host: " << host << std::endl;
			std::cout << "Port: " << port << std::endl;
			std::cout << "Index: " << index << std::endl;
			
		}
	}catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}


int main(){
	try{
		// testConfigServer();
		// testLoginFile();
		Parsertest();
	}catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
