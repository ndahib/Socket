/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMultiplex.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 09:56:31 by codespace         #+#    #+#             */
/*   Updated: 2024/05/30 06:42:47 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMULTIPLEX_HPP
# define IMULTIPLEX_HPP

#include "TcpSocket.hpp"
class	IMultiplex
{
	#define READ 0
	#define WRITE 1
	#define	READ_WRITE 2
public:
	typedef int EVENT_TYPE;
	
	virtual 			~IMultiplex(){};
	virtual int			multiplex(long timeout) = 0;
	virtual void		Register(EVENT_TYPE type, SOCKET socket) = 0;
	virtual void		Unregister(EVENT_TYPE type, SOCKET socket) = 0;
	virtual bool		isRegistered(EVENT_TYPE type, SOCKET socket) = 0;
};

#endif