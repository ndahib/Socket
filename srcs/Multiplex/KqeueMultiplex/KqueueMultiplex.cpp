/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   KqueueMultiplex.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 10:13:28 by codespace         #+#    #+#             */
/*   Updated: 2024/05/26 10:52:34 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if defined(__APPLE__)

#include "KqueueMultiplex.hpp"

/* ***Construction********************************************************** */

KqueueMultiplex::KqueueMultiplex(/* args */) : _kq(kqeue()){
    std::cout << "KqueueMultiplex Constructor" << std::endl;
}

KqueueMultiplex::~KqueueMultiplex(){
    close(_kq);
}


/* ***Method**************************************************************** */

void    KqueueMultiplex::Register(EVENT_TYPE type){
    Kquevent eventStruct;
    
    
}

#endif
    
