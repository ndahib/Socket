/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ISocket.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahib <ndahib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 11:12:47 by ndahib            #+#    #+#             */
/*   Updated: 2024/05/11 12:41:51 by ndahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include <arpa/inet.h>
#include <vector>

class	ISocket
{
	# define SOCKET int
	# define PORT int
	# define IN_ADDR struct sockaddr_in
	# define ISVALIDSOCKET(x) (x >= 0)

	private:
		SOCKET	_Socket;
		bool	_isListener;
		PORT	_Port;	
		IN_ADDR	_AddrToBind;
	
		ISocket();
		ISocket(const ISocket &obj);
		ISocket &operator=(const ISocket &obj);
	public:
		ISocket(IN_ADDR addrToBind, PORT port, bool _isListener = false);
		virtual ~ISocket();
		
		virtual void	Socket() = 0;
		virtual SOCKET	Socket() = 0;
		virtual void	SendData() = 0;
		virtual void	receivData() = 0;
		virtual void	setSocketOption() = 0;
		virtual void	seToNonBlocking() = 0;
		virtual void	setProtocol() = 0;
};