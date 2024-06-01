/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SelectMultiplex.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 10:56:03 by codespace         #+#    #+#             */
/*   Updated: 2024/05/30 06:41:33 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SELECTMULTIPLEX_HPP
#define SELECTMULTIPLEX_HPP

#include "IMultiplex.hpp"

class SelectMultiplex : public IMultiplex
{
	/* ****Attributs********************************************************* */
	private:
		int		_maxfd;
		fd_set	_readfds;
		fd_set	_writefds;
		fd_set 	_copy_readfds;
		fd_set	_copy_writefds;
	/* ****Method************************************************************* */
	public:
		SelectMultiplex();
		~SelectMultiplex();
		int		multiplex(long timeout);
		void	Register(EVENT_TYPE type, SOCKET socket);
		void	Unregister(EVENT_TYPE type, SOCKET socket);
		bool	isRegistered(EVENT_TYPE type, SOCKET socket);
};
#endif