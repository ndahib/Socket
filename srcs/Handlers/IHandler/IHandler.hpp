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

class HttpServer;
class IHandler
{
	protected:
	/* ***Attributes*************************************************** */
		HttpServer		*_server;
		int				_fd;
	public:
	/* ***Construction************************************************* */
		virtual	 		~IHandler();
	/* ***Method******************************************************* */
		virtual void	handle() = 0;
};
#endif
