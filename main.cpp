/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahib <ndahib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 08:15:52 by ndahib            #+#    #+#             */
/*   Updated: 2024/05/12 15:02:59 by ndahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SocketDirector.hpp"

int main(int ac, char **av)
{
	if (ac == 3)
	{
		SOCKET listener;
		try
		{	
			TcpSocket ServerSocket(av[1], av[2]);
			SocketDirector director(ServerSocket);
			if ((listener = director.SetupServer()) == -1)
				throw(std::error_code());
			std::cout << listener << std::endl;
			director.
		}
		catch(std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
		
		return (0);
	}
	return(1);
}