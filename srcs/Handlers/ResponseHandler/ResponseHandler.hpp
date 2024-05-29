/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ResponseHandler.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:30:56 by codespace         #+#    #+#             */
/*   Updated: 2024/05/29 11:31:08 by codespace        ###   ########.fr       */
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