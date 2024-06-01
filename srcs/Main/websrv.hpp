/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   websrv.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 09:20:44 by codespace         #+#    #+#             */
/*   Updated: 2024/05/30 06:58:03 by codespace        ###   ########.fr       */
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

# include <map>
# include <utility>
# include <fstream>
# include <algorithm>


# include "Client.hpp"
# include "SelectMultiplex.hpp"
# include "VirtualHost.hpp"
# include "ResponseHandler.hpp"
# include "AcceptHandler.hpp"
# include "RequestHandler.hpp"
# include "HttpServer.hpp"

#endif