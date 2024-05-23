/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahib <ndahib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 08:15:52 by ndahib            #+#    #+#             */
/*   Updated: 2024/05/21 10:16:41 by ndahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Listener.hpp"

int main(int ac, char **av)
{
	if (ac == 3)
	{
		try
		{	
			TcpSocket ServerSocket(av[1], av[2]);
			std::cout << Listener::SetupListener(ServerSocket) << std::endl;
		}
		catch(std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
		
		return (0);
	}
	return(1);
}