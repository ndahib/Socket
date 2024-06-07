/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConfigParser.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahib <ndahib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:32:15 by ndahib            #+#    #+#             */
/*   Updated: 2024/06/06 12:52:23 by ndahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIGPARSER_HPP
#define CONFIGPARSER_HPP

#include <map>
#include <vector>
#include <iostream>
#include <yaml-cpp/yaml.h>

#ifndef DEFAULT_CONFIG
#define DEFAULT_CONFIG "./srcs/Ressources/config/default.yml"
#endif

class ConfigParser {
public:
    ConfigParser(const char *path = DEFAULT_CONFIG);
    ~ConfigParser() = default;

    void parse();
    std::vector<YAML::Node> getDirective(const std::string& directive);

private:
    YAML::Node root;
    std::map<std::string, std::vector<YAML::Node>> directives;

    void loadIncludeFiles();
};

#endif	/* CONFIGPARSER_HPP */