/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   websrv.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 09:20:44 by codespace         #+#    #+#             */
/*   Updated: 2024/06/03 07:05:50 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSRV_HPP
# define WEBSRV_HPP


/* ***Colors**************************************************************** */
# define COLORS_HPP
# define RED	"\033[0;31m"
# define GREEN	"\033[0;32m"
# define YELLOW	"\033[0;33m"
# define BLUE	"\033[0;34m"
# define PURPLE	"\033[0;35m"
# define CYAN	"\033[0;36m"

# define END	"\033[0m"
# define RESET "\033[0m"

# define DEFAULT_CONFIG "./srcs/config/files/default.conf"

/* ***Includes************************************************************** */


// CPP Includes
# include <exception>
# include <iostream>
# include <iomanip>
# include <sstream>
# include <fstream>
# include <string>
# include <limits>
# include <cstdio>
# include <cstdlib>
# include <cstring>

// CPP Containers
# include <map>
# include <set>
# include <vector>
# include <algorithm>
# include <iterator>
# include <list>
# include <utility>


// C Includes
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <time.h>
# include <limits.h>
# include <errno.h>
# include <dirent.h>

// C System
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/time.h>

// C Network
# include <netdb.h>
# include <sys/socket.h>
# include <sys/select.h>
# include <arpa/inet.h>
# include <netinet/in.h>

// Define two names ntoh functions
# define ft_htonl ft_ntohl
# define ft_htons ft_ntohs

// Bytes for endian conversion
# define BYTE_0 0xff000000
# define BYTE_1 0x00ff0000
# define BYTE_2 0x0000ff00
# define BYTE_3 0x000000ff

// Default
# define RECV_SIZE 65536
# define CGI_BUFSIZE 65536
# define DEFAULT_CONFIG "./srcs/config/files/default.conf"

// Output
# ifndef OUT
#  define OUT 1
# endif
# ifndef TIME
#  define TIME 0
# endif

std::string					readKey(char *line); //Deprecated
std::string					readKey(const std::string& line);
std::string					readValue(char *line); //Deprecated
std::string					readValue(const std::string& line);
std::string&				strip(std::string& str, char c);
std::vector<std::string>	split1(const std::string& str, char c);
std::string&				to_lower(std::string& str);
std::string&				to_upper(std::string& str);
std::string&				capitalize(std::string& str);
std::string					to_string(size_t n);
int							checkEnd(const std::string& str, const std::string& end);
int							checkStart(const std::string& str, const std::string& end);
int							countSubstr(const std::string& str, const std::string& sub);
std::string&				pop(std::string& str);


// UTILS
int							pathIsFile(const std::string & path);
void						timeit(std::string breakpoint);
bool 						compare_langs(const std::pair<std::string, float> first, const std::pair<std::string, float> second);


#endif