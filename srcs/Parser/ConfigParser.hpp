/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConfigParser.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahib <ndahib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:32:15 by ndahib            #+#    #+#             */
/*   Updated: 2024/06/11 10:04:09 by ndahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIGPARSER_HPP
#define CONFIGPARSER_HPP

#include <map>
#include <vector>
#include <iostream>
#include <yaml-cpp/yaml.h>

#ifndef DEFAULT_CONFIG
#define DEFAULT_CONFIG "./Ressources/config/default.yaml"
#endif /*!_DEFAULT_CONFIG*/


class ConfigParser {
/* *******Construction******************************************************* */
	typedef std::vector<std::map<std::string, YAML::Node>> SERVER_BLOCKS;
public:
	ConfigParser(const char *path = DEFAULT_CONFIG);
	~ConfigParser() = default;

/* *******Public Method****************************************************** */
	void 			parse();
	SERVER_BLOCKS	getServers() const ;

private:

/* *******Method************************************************************* */
	void					print();
	void					parse(const YAML::Node &node);
	void					ConvertNode(const YAML::Node &node);
	void					mergeServerBlocksAndGlobals();

/* *******Atrributes********************************************************* */
	YAML::Node _root;
	SERVER_BLOCKS	_serverdirectives;
	std::map<std::string, YAML::Node>				_global_directives;
};

#endif	/* CONFIGPARSER_HPP */