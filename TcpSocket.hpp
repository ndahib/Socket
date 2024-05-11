/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TcpSocket.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahib <ndahib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 11:34:31 by ndahib            #+#    #+#             */
/*   Updated: 2024/05/11 12:42:17 by ndahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TCPSOCKET_HPP
#define TCPSOCKET_HPP


#include "ISocket.hpp"

class	TCPSocket : public ISocket
{
	/* ************************************************************************** */
	private:
		TCPSocket();
		TCPSocket(const TCPSocket &obj);
		TCPSocket &operator=(const TCPSocket &obj);

	public:
	/* ******************************Constructor********************************** */
		TCPSocket(IN_ADDR addrToBind, int port);
		~TCPSocket();
	
	/* **********************************Method*********************************** */
		void				Socket();
		void				bind();
		void				listen();
		void				accept();
		void				close();
		void				setListener(bool _isListener);
		void				setToreuseAddr();
		void				setProtocol();
		void				seToNonBlocking();
	/* **********************************Getters*********************************** */
		SOCKET				Socket() const;
		int					getPort() const;
		int 				getBufferSize() const;
		bool				isListener() const;
		std::vector<char> 	getBufferReceived() const;
		
	/* **********************************Check*********************************** */
		bool				isBound() const;
		bool				isClosed() const;
		bool				isListening() const;
		bool				isListenerSocket() const;
		bool				isBlocking() const;
};

#endif