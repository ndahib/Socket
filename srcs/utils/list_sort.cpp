/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_sort.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 17:52:04 by hbaudet           #+#    #+#             */
/*   Updated: 2024/06/02 10:00:52 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "websrv.hpp"

bool compare_langs(const std::pair<std::string, float> first, const std::pair<std::string, float> second)
{
  return ( first.second > second.second );
}