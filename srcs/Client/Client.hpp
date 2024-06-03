/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 06:53:38 by codespace         #+#    #+#             */
/*   Updated: 2024/06/02 10:34:25 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Client_HPP
# define Client_HPP

#include "TcpSocket.hpp"
#include "Request.hpp"
#include "websrv.hpp"


class Client
{
	private:
	/* ***Attributes*************************************************** */
		SOCKET			_socket;
		Request			_request;
	public:
	/* ***Construction************************************************* */
		Client();
		Client(SOCKET socket);
		~Client();
	/* ***Method******************************************************* */
		void			parseRequest(std::vector<char> &buffer);
		void			printRerquest();
		bool			isRequestCompleted() const;
		void			setRequest(Request &newRequest);
		SOCKET			getSocket() const;
		Request			getRequest() const;
};

#endif
