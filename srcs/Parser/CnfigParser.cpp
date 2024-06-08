/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CnfigParser.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahib <ndahib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 11:39:10 by ndahib            #+#    #+#             */
/*   Updated: 2024/06/07 12:10:41 by ndahib           ###   ########.fr       */
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
	if (_root.IsNull())
		std::cout << "_root is Null" << std::endl;
		// throw(YAML::Exception(__LINE__, "Empty File"));
	for (YAML::const_iterator it = _root.begin(); it != _root.end(); ++it){
		std::string Directive = it->first.as<std::string>();
		if (Directive == "HTTP"){
			std::cout << "HTTP Directive" << std::endl;
			std::vector<YAML::Node> servers;
			if (it->second.IsMap())
			{
				for (YAML::const_iterator it1 = it->second.begin(); it1 != it->second.end(); ++it1)
				{
					std::cout << it->second << std::endl;
					servers.push_back(*it1);
				std::cout << "===========================" << std::endl;
				}
				_directives["HTTP"] = servers;
			}
		}
		else if (Directive == "error_page" || Directive == "client_max_body_size" || Directive == "allowed_methods"){
			std::cout << "Global Directive" << std::endl;
			// Share 
		}
		else if (Directive == "include"){
			std::cout << "Include Directive" << std::endl;
		}
		else {
			std::cout << "Enter here to unknow directive of ParserConig" << std::endl;
			throw YAML::ParserException(it->Mark(), "unkonw directive");
		}
	} /*For loop*/
}