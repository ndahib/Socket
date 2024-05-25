/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 08:15:52 by ndahib            #+#    #+#             */
/*   Updated: 2024/05/25 09:47:27 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "websrv.hpp"

int main()
{
	VirtualHost  	server1 = VirtualHost("127.0.0.1", "8000");
	VirtualHost  	server2 = VirtualHost("127.0.0.1", "8001");
	VirtualHost		server3 = VirtualHost("127.0.0.1", "8002");

	std::cout << server1.SetupServer() << std::endl;;
	std::cout << server2.SetupServer()  << std::endl;
	std::cout << server3.SetupServer() << std::endl;;
}