/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SocketDirector.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahib <ndahib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 12:50:55 by ndahib            #+#    #+#             */
/*   Updated: 2024/05/12 14:58:02 by ndahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOCKETDIRECTOR_HPP
#define SOCKETDIRECTOR_HPP

#include "TcpSocket.hpp"

class SocketDirector
{
	private:
		TcpSocket _socketBuilder;
	public:
		SocketDirector(const TcpSocket &socketBuilder);
		~SocketDirector();
		SOCKET SetupClient();
		SOCKET SetupServer(); 

		
		void	HandleServerConnection();
		void	HandleClientConnection();
};

#endif /*SOCKETDIRECTOR_HPP*/
