/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahib <ndahib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 08:15:52 by ndahib            #+#    #+#             */
/*   Updated: 2024/06/10 12:16:00 by ndahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HttpServer.hpp"
// // void Parsertest()
// // {
// // 	YAML::Node root;

// // 	root = YAML::LoadFile("Ressources/Config/Test.yml");
// // 	std::cout << "Loading map is successful" << std::endl;
// // 	if (root.IsMap())
// // 	{
// // 		std::cout << "Our root is a map Structured" << std::endl;
// // 		for (YAML::const_iterator it = root.begin(); it != root.end(); ++it)
// // 		{
// // 			std::cout <<"Node :" << it->first << std::endl;
// // 		}
// // 	}
// // }    

// #include <iostream>
// #include <fstream>
// #include "yaml-cpp/yaml.h"

// void copyYamlFile(const std::string& inputFile, const std::string& outputFile) {
//     try {
//         // Load YAML file
//         YAML::Node root = YAML::LoadFile(inputFile);

//         // Open output file
//         std::ofstream fout(outputFile);

//         // Write specific parts of the YAML data to the output file
//         fout << "desired_key:\n";
//         fout << root["desired_key"];

//         // Close the output file
//         fout.close();

//         std::cout << "File copied successfully!" << std::endl;
//     } catch (const std::exception& e) {
//         std::cerr << "Error: " << e.what() << std::endl;
//     }
// }

// int main() {
//     copyYamlFile("Ressources/config/Test.yml", "Ressources/config/default.yaml");
//     return 0;
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
	}
	catch(YAML::KeyNotFound &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch(YAML::BadFile &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch(std::runtime_error &e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "Unknown Fatal error in Server , Server will Stop " << std::endl;
	};
	// delete 	DirectorServer;
	return (0);
}