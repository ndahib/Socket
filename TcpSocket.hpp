/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TcpSocket.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahib <ndahib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 11:34:31 by ndahib            #+#    #+#             */
/*   Updated: 2024/05/11 15:48:46 by ndahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TCPSOCKET_HPP
#define TCPSOCKET_HPP


#include "ISocket.hpp"

class	TCPSocket : public ISocket
{
	 # define BACKLOG 100
	/* ************************************************************************** */
	private:
		TCPSocket();
		TCPSocket(const ISocket &obj);
		TCPSocket &operator=(const ISocket &obj);
		std::vector <SOCKET> ClientsAccpeted;

	public:
	/* ******************************Constructor********************************** */
		TCPSocket(const char* Ip, const char*  port);
		~TCPSocket();
	
	/* **********************************Method*********************************** */
		void				createSocket();
		void				Bind();
		void				Listen();
		void				Accept();
		void				Close();
		void				setToreuseAddr();
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
	
	private:
		bool	_isListening;
};

#endif