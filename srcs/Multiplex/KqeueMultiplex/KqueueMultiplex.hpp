/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   KqueueMultiplex.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 10:00:47 by codespace         #+#    #+#             */
/*   Updated: 2024/05/26 10:47:36 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if defined(__APPLE__)
# ifndef KQEUUEMULTIPLEX_HPP
# define KQEUUEMULTIPLEX_HPP

# include "websrv.hpp"
# include "IMultiplex.hpp"
	# include <sys/event.h>


class KqueueMultiplex : public IMultiplex
{
		typedef int Kq;
		typedef struct kevent Kquevent;
		typedef struct timespec KqTime;
	
		#define KqueUE_MAX 1024
	/* ****Attributs********************************************************* */
	private:
		Kq _kq;
	/* ****Method************************************************************* */
	public:
		KqueueMultiplex(/* args */);
		~KqueueMultiplex();
		void multiplex(long timeout) = 0;
		void Register(EVENT_TYPE type) = 0;
		void Unregister(EVENT_TYPE type) = 0;
};


#endif
#endif