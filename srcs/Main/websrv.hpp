/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   websrv.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 09:20:44 by codespace         #+#    #+#             */
/*   Updated: 2024/05/29 12:05:27 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSRV_HPP
# define WEBSRV_HPP


/* ***Colors**************************************************************** */
# define COLORS_HPP
# define RED	"\033[0;31m"
# define GREEN	"\033[0;32m"
# define YELLOW	"\033[0;33m"
# define BLUE	"\033[0;34m"
# define PURPLE	"\033[0;35m"
# define CYAN	"\033[0;36m"

# define END	"\033[0m"


/* ***Includes************************************************************** */
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>
#include <unistd.h>
#include <fstream>


# include "TcpSocket.hpp"
# include "Client.hpp"
# include "IMultiplex.hpp"
# include "SelectMultiplex.hpp"
# include "VirtualHost.hpp"
# include "ResponseHandler.cpp"
# include "AcceptHandler.hpp"
# include "RequestHandler.cpp"
# include "HttpServer.hpp"

#endif