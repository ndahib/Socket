/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RequestHandler.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 08:18:55 by codespace         #+#    #+#             */
/*   Updated: 2024/06/01 09:28:15 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REQUESTHANDLER_HPP
#define REQUESTHANDLER_HPP

#include "IHandler.hpp"
#include "websrv.hpp"
class  RequestHandler : public IHandler
{
	#define BUFFER_SIZE 4096
	/* ***Construction************************************************* */
	public:
		RequestHandler(int fd);
		~RequestHandler();
	
	/* ***Construction************************************************* */
		void handle();
};

template <typename T>
void print(T& t)
{
	for (typename T::const_iterator it = t.begin(); it != t.end(); ++it)
		std::cout << *it;
}
#endif