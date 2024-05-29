/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RequestHandler.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 08:18:55 by codespace         #+#    #+#             */
/*   Updated: 2024/05/29 11:38:28 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REQUESTHANDLER_HPP
#define REQUESTHANDLER_HPP

#include "IHandler.hpp"
class  RequestHandler : public IHandler
{
    /* ***Construction************************************************* */
    public:
        RequestHandler(int fd);
        ~RequestHandler();
    
    /* ***Construction************************************************* */
        void handle();
};

#endif