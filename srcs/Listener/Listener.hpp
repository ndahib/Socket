/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Listener.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahib <ndahib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 12:50:55 by ndahib            #+#    #+#             */
/*   Updated: 2024/05/21 09:38:59 by ndahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Listener_HPP
#define Listener_HPP

#include "TcpSocket.hpp"

class Listener
{
	private:
		static TcpSocket _socket;
		Listener();

	public:
		~Listener();
		static SOCKET SetupListener(TcpSocket &socket);

		// Maybe to Add after:
			// SHould set alwyas non-blocking?
			// SHould set alwyas Set socketoption
};

#endif /*Listener_HPP*/
