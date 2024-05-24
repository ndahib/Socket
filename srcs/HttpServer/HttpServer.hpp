/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HttpServer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 07:07:34 by codespace         #+#    #+#             */
/*   Updated: 2024/05/24 08:36:03 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Listener.hpp"

class HttpServer
{
    // basing on configuration file we will know the number of socket that we will lunch
    private:
    public:
        HttpServer();
        HttpServer(const HttpServer &other);
        HttpServer& operator=(const HttpServer &other);
        ~HttpServer();

        void    launchListeners();
          
};