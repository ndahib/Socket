/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ISocket.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahib <ndahib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 11:12:47 by ndahib            #+#    #+#             */
/*   Updated: 2024/05/11 15:48:56 by ndahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include <arpa/inet.h>
 #include <unistd.h>
#include <netdb.h>
#include <fcntl.h>
#include <vector>
#include <string>

class	ISocket
{
	# define SOCKET int
	# define IN_ADDR struct addrinfo
	# define ISVALIDSOCKET(x) (x >= 0)
	protected:
		ISocket();
		ISocket(const ISocket &obj);
		ISocket &operator=(const ISocket &obj);
	public:
		ISocket(const char* Ip, const char*  port, bool _isListener = false);
		virtual ~ISocket();
		
		virtual SOCKET	Socket() const = 0;
		virtual void	createSocket() = 0;
		virtual void	SendData() = 0;
		virtual void	receivData() = 0;
		virtual void	setSocketOption() = 0;
		virtual void	seToNonBlocking() = 0;
		virtual void	setToLisner()0;
		virtual int		getPort() const = 0;
		virtual int 	getBufferSize() const = 0;
		virtual bool	isListener() const = 0;
		virtual void	Bind() = 0;
		virtual void	Listen() = 0;
		virtual void	Accept() = 0;
		virtual void	Close() = 0;
		virtual // std::vector<char> 	getBufferReceived() const;
	/* * *********************************Check*********************************** */
		virtual bool	isBound() const = 0;
		virtual bool	isClosed() const = 0;
		virtual bool	isListening() const = 0;
		virtual bool	isListenerSocket() const = 0;
		virtual bool	isBlocking() const = 0;

	protected:
		int			_bytesReceived;
		int			_bytesSent;
		bool		_isListener;
		bool		_isBound;
		bool		_isClosed;
		bool		_isListener;
		bool		_isBlocking;
		SOCKET		_Socket;
		IN_ADDR*	_AddrToBind;
		const char*	_Port;
		std::string	_Ip;	
};