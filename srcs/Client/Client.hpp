/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 06:53:38 by codespace         #+#    #+#             */
/*   Updated: 2024/05/29 06:58:16 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_HPP
# define CLIENT_HPP

#include "websrv.hpp"

class Client
{
	private:
	/* ***Attributes*************************************************** */
		SOCKET			_socket;
		// Request			_request;
		// Response		_response;
	public:
	/* ***Construction************************************************* */
		Client(/* args */);
		~Client();
	/* ***Method******************************************************* */
};

#endif
