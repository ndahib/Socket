/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CnfigParser.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahib <ndahib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 11:39:10 by ndahib            #+#    #+#             */
/*   Updated: 2024/06/08 15:25:27 by ndahib           ###   ########.fr       */
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
	std::vector<std::map<std::string, YAML::Node>> ServerConfigs;

	if (_root.IsNull() == true)
		throw (std::runtime_error("Empty Config File"));
	if (_root.IsMap() == true)
		throw (std::runtime_error("Correct the structure of Config File"));
	for (YAML::const_iterator rootIt = _root.begin(); rootIt != _root.end(); ++rootIt)
	{
		std::string CurrentDirective = rootIt->first.as<std::string>();
		if (CurrentDirective == "HTTP")
		{
			// Create a Vector of ServerConfig 
		}
		else if (CurrentDirective == "GLOBAL")
		{
			if (rootIt->IsScalar()) //Just key :Value
				_global_directives[CurrentDirective] = rootIt->second;
			else if (rootIt->IsSequence())
			{
				// Convert from complex nodes to scalar nodes
				
			}
		}
	}
}