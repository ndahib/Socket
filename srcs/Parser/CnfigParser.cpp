/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CnfigParser.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahib <ndahib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 11:39:10 by ndahib            #+#    #+#             */
/*   Updated: 2024/06/10 12:51:31 by ndahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ConfigParser.hpp"

/* ***Construction && Destruction******************************************** */
ConfigParser::ConfigParser(const char *path)
{
	_root = YAML::LoadFile(path);
}

/*	***methods*************************************************************** */

void	ConfigParser::parse()
{
	if (_root.IsNull() == true)
		throw (std::runtime_error("Empty Config File"));
	if (_root.IsMap() == false)
		throw (std::runtime_error("Correct the structure of Config File"));
	parse(_root);
	mergeServerBlocksAndGlobals();
	print();
}

// Merge the global Variables with the Server Blocks
void	ConfigParser::mergeServerBlocksAndGlobals()
{
	for (auto& ServerBlockIt : _serverdirectives) {
		for (auto globalIt = _global_directives.begin(); globalIt != _global_directives.end(); globalIt++)	{
			if (ServerBlockIt.find(globalIt->first) == ServerBlockIt.end())
				ServerBlockIt.insert(globalIt, globalIt);
		}
	}	
}


//Parsing Using Recursion to Handle the include Nodes
void ConfigParser::parse(const YAML::Node& node) {
	for (YAML::const_iterator it = node.begin(); it != node.end(); ++it) {
		std::string currentDirective = it->first.as<std::string>();
		if (currentDirective == "include") {
			try {
				YAML::Node includeConfig = YAML::LoadFile(it->second.as<std::string>());
				parse(includeConfig);
			} catch (const YAML::Exception& e) {
				std::cerr << "Error while parsing included file: " << e.what() << std::endl;
			}
		} else if (currentDirective == "http") {
			for (YAML::const_iterator serverIt = it->second.begin(); serverIt != it->second.end(); ++serverIt) {
				if (serverIt->first.as<std::string>() == "server") {
				{
					_serverdirectives.push_back(serverIt->second.as<std::map<std::string, YAML::Node>>());
				}
				} else if (serverIt->first.as<std::string>() == "include") {
					try {
						YAML::Node includeConfig = YAML::LoadFile(serverIt->second.as<std::string>());
						parse(includeConfig);
					} catch (const YAML::Exception& e) {
						std::cerr << "Error while parsing included file: " << e.what() << std::endl;
					}
				}
			}
		} else if (currentDirective == "global") {
			if (it->second.IsScalar() == true && it->second.as<std::string>() == "include") {
				try {
					YAML::Node includeConfig = YAML::LoadFile(it->second.as<std::string>());
					parse(includeConfig);
				} catch (const YAML::Exception& e) {
					std::cerr << "Error while parsing included file: " << e.what() << std::endl;
				}
			} else {
				ConvertNode(it->second);
			}
		}
	}
}
void ConfigParser::ConvertNode(const YAML::Node& node) {
	if (node.IsMap()) {
		for (YAML::const_iterator it = node.begin(); it != node.end(); ++it) {
			_global_directives[it->first.as<std::string>()] = it->second;
		}
	}
	else if (node.IsScalar())
	{
		//Not sure about it ;
		_global_directives[node.begin()->first.as<std::string>()] = node.begin()->second;
	}
	
	else if (node.IsSequence()) {
		for (auto &it : node){
			ConvertNode(it);
		}
	}
}
	

 void	ConfigParser::print()
 {
	for (auto& it : _serverdirectives)
	{
		for (auto& it2 : it)
		{
			std::cout << it2.first << " : " << it2.second << std::endl;
		}
		std::cout << "******************************" << std::endl;
	}
 }