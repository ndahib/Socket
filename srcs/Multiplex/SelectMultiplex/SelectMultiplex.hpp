/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SelectMultiplex.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 10:56:03 by codespace         #+#    #+#             */
/*   Updated: 2024/05/26 11:26:35 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SELECTMULTIPLEX_HPP
#define SELECTMULTIPLEX_HPP

#include "websrv.hpp"

class SelectMultiplex : public IMultiplex
{
	/* ****Attributs********************************************************* */
	private:
		fd_set _readfds;
		fd_set _writefds;
	/* ****Method************************************************************* */
	public:
		SelectMultiplex();
		~SelectMultiplex();
		void	multiplex(long timeout);
		void	Register(EVENT_TYPE type, SOCKET socket);
		void	Unregister(EVENT_TYPE type, SOCKET socket);
		bool	isRegistered(EVENT_TYPE type, SOCKET socket);
};
#endif