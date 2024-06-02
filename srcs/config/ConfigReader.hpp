/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConfigReader.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:33:47 by user42            #+#    #+#             */
/*   Updated: 2024/06/02 08:30:30 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_READER_HPP

# define CONFIG_READER_HPP

# include "websrv.hpp"

# define READER_BUFFER_SIZE 1024

typedef std::vector<std::string> fileVector;

class ConfigReader {
	public:
		ConfigReader(void);
		ConfigReader(ConfigReader const &src);
		virtual	~ConfigReader(void);

		ConfigReader			&operator=(ConfigReader const &src);
		static fileVector  		readFile(const char *filename);
		static fileVector		split(std::string str, std::string charset);
		class	FileNotFoundException: public std::exception{
			virtual const char	*what() const throw();
		};
	private:
};

#endif
