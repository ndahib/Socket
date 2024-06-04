/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TcpSocket.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahib <ndahib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 11:34:31 by ndahib            #+#    #+#             */
/*   Updated: 2024/06/03 11:07:29 by ndahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TcpSocket_HPP
#define TcpSocket_HPP

# include "websrv.hpp"

class	TcpSocket
{
	# define SOCKET int
	# define BACKLOG 100
	# define IN_ADDR struct addrinfo
	# define ISVALIDSOCKET(x) (x >= 0)
	
	/* ************************************************************************** */

	public:
	/* ******************************Constructor********************************** */
		TcpSocket();
		TcpSocket(const char* Ip, const char*  port);
		TcpSocket &operator=(const TcpSocket &obj);
		TcpSocket(const TcpSocket &obj);
		~TcpSocket();
	
	/* **********************************Method*********************************** */
		void				createSocket();
		void				Bind();
		void				Listen();
		// void				Accept();
		void				Close();
		void				setSocketOption(int Flag);
		void				setToLisner();
		void				seToNonBlocking();
	/* **********************************Getters*********************************** */
		SOCKET				Socket() const;
		int					getPort() const;
		int 				getBufferSize() const;
		bool				isListener() const;
		// std::vector<char> 	getBufferReceived() const;
		
	/* **********************************Check*********************************** */
		bool				isBound() const;
		bool				isClosed() const;
		bool				isListening() const;
		bool				isListenerSocket() const;
		bool				isBlocking() const;
	
	/* ********************************Attributes********************************* */
	private:
		bool		_isListening;
		int			_bytesReceived;
		int			_bytesSent;
		bool		_isListener;
		bool		_isBound;
		bool		_isClosed;
		bool		_isBlocking;
		SOCKET		_Socket;
		IN_ADDR*	_AddrToBind;
		const char*	_Ip;
		const char*	_Port;
	/* ********************************Exception********************************** */
	class	SocketExeption : public std::exception
	{
		char const * what();
	};
	class	BindException : public std::exception
	{
		char const * what();
	};

	class ConnectExeption : public std::exception
	{
		char const* what();
	};

	class ListenException : public std::exception
	{
		char const *what();
	};

	class AcceptExcption : public std::exception
	{
		char const *what();
	};

	class GeneralError : public std::exception // I3adata nadar2
	{
		private:
			mutable std::string strError;
		public:
			GeneralError(std::string strError);
			virtual const char* what() const throw();
			virtual ~GeneralError() throw() {};
	};
};
 
#endif