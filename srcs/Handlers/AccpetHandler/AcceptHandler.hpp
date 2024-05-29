/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AcceptHandler.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 07:21:34 by codespace         #+#    #+#             */
/*   Updated: 2024/05/29 11:19:39 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACCEPTHANDLER_HPP
# define ACCEPTHANDLER_HPP

#include "IHandler.hpp"

class AcceptHandler : public IHandler
{
	/* ***Construction************************************************* */
	public:
		AcceptHandler(int fd);
		~AcceptHandler();
	
	/* ***Construction************************************************* */
		void handle();
};
#endif