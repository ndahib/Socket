/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 08:15:52 by ndahib            #+#    #+#             */
/*   Updated: 2024/06/03 09:48:25 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <yaml-cpp/yaml.h>

int main() {
	// Load the YAML file
	YAML::Node config = YAML::LoadFile("config.conf");

	// Access the data
	std::string host = config["server"]["host"].as<std::string>();
	int port = config["server"]["port"].as<int>();

	// Print the data
	std::cout << "Server Host: " << host << std::endl;
	std::cout << "Server Port: " << port << std::endl;

	return 0;
}
