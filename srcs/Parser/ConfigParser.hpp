/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConfigParser.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahib <ndahib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:32:15 by ndahib            #+#    #+#             */
/*   Updated: 2024/06/09 12:31:05 by ndahib           ###   ########.fr       */
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

	void 					parse();
	void					print();
	std::vector<YAML::Node> getDirective(const std::string& directive);

private:
	YAML::Node _root;
	std::vector<std::map<std::string, YAML::Node>>							_serverdirectives;
	std::map<std::string, YAML::Node>										_global_directives;

	void	parse(const YAML::Node &node);
	void	ConvertNode(const YAML::Node &node);
	void	mergeServerBlocksAndGlobals();
};

#endif	/* CONFIGPARSER_HPP */