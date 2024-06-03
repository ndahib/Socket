/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Request.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 06:51:39 by codespace         #+#    #+#             */
/*   Updated: 2024/06/03 09:06:58 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REQUEST_HPP
# define REQUEST_HPP

# include "websrv.hpp"
class	Request
{
	/* ***********************************Methods************************ */		
	public:
		Request();
		Request(const Request &obj);
		Request &operator=(const Request &obj);
		~Request();
	
		void				print();
	private:
		void				parse();
		void				bodyFill();
		void				headerFill();
		void				parse_path();
		void				parseHeader();
		void				parseRequestLine();
		void				checkEndOfHeaders();
		void				handleContentLength();
		void				handleTransferEncoding();
	
	public:
		
		void				clear();
		void				setup( std::vector<char> & newBuffer );
		bool				headerExist( const std::string & key ) const;
		std::string const	getHeader( const std::string & key ) const;
		
		/* ****************************Getters************************ */
		
		std::string 		get_path() const;
		std::string			get_method() const;
		int					get_statusCode() const;
		std::vector< char >	get_body() const;
	/* *******************************Attributes************************ */
		bool												isComplete;
	private:
		// General Elements;
			int 												index;
			int													statusCode;
			bool												inBody;
			std::string											rem;
			std::vector<char> 									buffer;
			


		// For Chunked
			int 												chunkIndex;
			size_t												chunkLength;
			std::string											chunkBuffer;
			
		
		// http Request have 3 component:
			//1- Request Line : that contain Mthod Path and HTTP version;
			std::string											method;
			std::string											path;
			std::string 										protocol;
			//1.1 Components  of Path
			std::string											fragement;
			std::string											Finalpath;
			std::map<std::string, std::string>					query;
		
			//2- Headres 
			std::vector<std::string> 							lines;
			std::vector<std::pair<std::string, std::string> >	header;
			//3- Message Body
			std::vector<char>									 body;

};

#endif