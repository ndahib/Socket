/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SocketDirector.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahib <ndahib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 12:50:55 by ndahib            #+#    #+#             */
/*   Updated: 2024/05/11 15:31:31 by ndahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOCKETDIRECTOR_HPP
#define SOCKETDIRECTOR_HPP

#include "ISocket.hpp"

class SocketDirector
{
	private:
		ISocket* _socketBuilder;
	public:
		SocketDirector(ISocket* socketBuilder);
		~SocketDirector();
		SOCKET buildClient();
		SOCKET buildServer();
};

#endif /*SOCKETDIRECTOR_HPP*/
