/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConfigParser.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahib <ndahib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:32:15 by ndahib            #+#    #+#             */
/*   Updated: 2024/06/07 12:02:24 by ndahib           ###   ########.fr       */
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
public:
	ConfigParser(const char *path = DEFAULT_CONFIG);
	~ConfigParser() = default;

	void parse();
	std::vector<YAML::Node> getDirective(const std::string& directive);

private:
	YAML::Node _root;
	std::map<std::string, std::vector<YAML::Node>> _directives;

	void loadIncludeFiles();
};

#endif	/* CONFIGPARSER_HPP */