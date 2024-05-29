/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Response.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 08:18:55 by codespace         #+#    #+#             */
/*   Updated: 2024/05/29 08:22:35 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ResponseHandler_HPP
#define ResponseHandler_HPP

#include "IHandler.hpp"
class  ResponseHandler : public IHandler
{
    /* ***Construction************************************************* */
    public:
        ResponseHandler(int fd);
        ~ResponseHandler();
    
    /* ***Construction************************************************* */
        void handle();
};

#endif