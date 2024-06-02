/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConfigHelperFunctions.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 14:26:35 by user42            #+#    #+#             */
/*   Updated: 2024/06/02 08:30:05 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_HELPER_FUNCTIONS_HPP

# include "websrv.hpp"

# define CONFIG_HELPER_FUNCTIONS_HPP

bool 			isDigits(const std::string &str);
unsigned int	strToIp(std::string strIp);
std::string		removeAdjacentSlashes(const std::string &str);


#endif
