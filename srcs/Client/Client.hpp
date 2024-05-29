/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 06:53:38 by codespace         #+#    #+#             */
/*   Updated: 2024/05/29 10:33:33 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Client_HPP
# define Client_HPP

#include "TcpSocket.hpp"


class Client
{
	private:
	/* ***Attributes*************************************************** */
		SOCKET			_socket;
		// Request			_request;
		// Response		_response;
	public:
	/* ***Construction************************************************* */
		Client();
		Client(SOCKET socket);
		~Client();
	/* ***Method******************************************************* */
};

#endif