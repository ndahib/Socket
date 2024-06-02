/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConfigDataStructures.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 14:24:34 by user42            #+#    #+#             */
/*   Updated: 2024/06/02 10:06:18 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_DATA_STRUCTURES_HPP

# define CONFIG_DATA_STRUCTURES_HPP

# include "websrv.hpp"

# define parseMap std::map<std::string, void (ConfigServer::*)(fileVector) >

class ConfigServer;
class RequestConfig;

typedef struct	s_listen {
	int				port;
	unsigned int	host;
}				t_listen;

typedef struct  s_error_page {
	std::vector<int>    errorCodes; // all of the codes that will be redirected
	std::string         uri;		// uri to which they are redirected
}               t_error_page;

#endif
