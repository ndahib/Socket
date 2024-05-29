/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IHandler.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 07:09:44 by codespace         #+#    #+#             */
/*   Updated: 2024/05/29 07:19:15 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IHandler_HPP
# define IHandler_HPP

#include "websrv.hpp"
class IHandler
{
	protected:
	/* ***Attributes*************************************************** */
		HttpServer		*_server;
		SOCKET			_fd;
	public:
	/* ***Construction************************************************* */
		IHandler(int fd);
		virtual ~IHandler();
	/* ***Method******************************************************* */
		virtual void	handle() = 0;
};
#endif
