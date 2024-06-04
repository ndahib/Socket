/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConfigParser.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahib <ndahib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:32:15 by ndahib            #+#    #+#             */
/*   Updated: 2024/06/04 13:10:04 by ndahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIGPARSER_HPP
# define CONFIGPARSER_HPP

#include <map>
#include <vector>
#include <yaml-cpp/yaml.h>

#ifndef DEFAULT_CONFIG
#define DEFAULT_CONFIG "./srcs/Ressources/config/default.yml"
#endif

class ConfigParser 
{
private:
	/* data */
public:
	ConfigParser(/*FilePath*/);
	~ConfigParser();
	// void parse();
	// void print();
	// void LoadIncludeFiles();
	//std::map<std::string, std::vector<YAML::Node>> ComplexDirectives();
	// std::map	
};

#endif