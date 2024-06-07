/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CnfigParser.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahib <ndahib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 11:39:10 by ndahib            #+#    #+#             */
/*   Updated: 2024/06/06 13:22:39 by ndahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ConfigParser.hpp"

/* ***Construction && Destruction******************************************** */
ConfigParser::ConfigParser(const char *path)
{
	YAML::Node root = YAML::LoadFile(path);
}

/*	***methods*************************************************************** */
enum ROOT_DIRECTIVE{
	HTTP,
	error_page,
	clinet_max_body_size,
	allowed_methods,
	include
};

void	ConfigParser::parse()
{
	for (YAML::Node::iterator it = root.begin(); it != root.end(); ++it){
		std::string Directive = it->first.as<std::string>();
		if (Directive == "HTTP")
			std::cout << "HTTP Directive" << std::endl;
		else if (Directive == "error_page" || Directive == "client_max_body_size" || Directive == "allowed_methods")
		{
			std::cout << "Global Directive" << std::endl;
		}
		else if 
		// switch (it->first.as<std::string>()){
		// case HTTP:{
		// 	std::cout << it->second << std::endl;
		// }
		// 	break;
		// case error_page:
		// case clinet_max_body_size:
		// case allowed_methods:{
		// 	// Share Data with other Server Blokc that is inside HTTP directive 
		// 	break;
		// }
		// case include:{
		// 	// Load other file and add it to the root
		// }
		// 	break;
		// default:
		// 	break;
		// 	//  throw YAML::Exception(YAML::Mark::null_mark(), "Invalid Directive : " + it->first.as<std::string>());
		// } /*Switch case*/
	} /*For loop*/
}