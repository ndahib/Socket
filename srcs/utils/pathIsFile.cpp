/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathIsFile.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 12:16:55 by hbaudet           #+#    #+#             */
/*   Updated: 2024/06/02 10:00:55 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "websrv.hpp"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


int		pathIsFile(const std::string& path)
{
	struct stat s;
	if (stat(path.c_str(), &s) == 0 )
	{
		if (s.st_mode & S_IFDIR)
			return 0;
		else if (s.st_mode & S_IFREG)
			return 1;
		else
			return 0;
	}
	else
		return 0;
}
