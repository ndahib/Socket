/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Request.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 06:55:11 by codespace         #+#    #+#             */
/*   Updated: 2024/06/01 11:40:08 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "websrv.hpp"

std::vector<std::string> split(const std::string& str, char c) {
	std::vector<std::string> result;
	std::string currentWord;
	bool inWord = false;

	for (size_t i = 0; i < str.length(); ++i) {
		char ch = str[i];

		if (ch == c) {
			if (inWord) {
				result.push_back(currentWord);
				currentWord.clear();
				inWord = false;
			}
		} else {
			currentWord += ch;
			inWord = true;
		}
	}
	if (inWord) {
		result.push_back(currentWord);
	}
	return result;
}

std::vector<std::string> split( const std::string str )
{
	std::stringstream			ss;
	std::string					tmp;
	std::vector<std::string>	result;

	ss << str;
	while ( ss >> tmp )
	{
		result.push_back( tmp );
	}
	return ( result );
}


int ConvertHex(const std::string& path) 
{
	int len = path.size();
	int base = 1;
	int dec_val = 0;
	for (int i = len - 1; i >= 0; i--) 
	{
		if (path[i] >= '0' && path[i] <= '9')
		{
			dec_val += (int(path[i]) - 48) * base;
			base = base * 16;
		} else if (path[i] >= 'A' && path[i] <= 'F')
		{
			dec_val += (int(path[i]) - 55) * base;
			base = base * 16;
		}else if (path[i] >= 'a' && path[i] <= 'f')
		{
			dec_val += (int(path[i]) - 87) * base;
			base = base * 16;
		}
	}
	return (dec_val);
}

char	HexToChar(const std::string& path)
{
	return ((char)( ConvertHex(path) ));
}


void	toLower(std::string &key)
{
	for (size_t i = 0; i < key.size(); i++)
	{
		if (std::isdigit(key[i]) || (key[i] != '-' && !std::isalpha(key[i])))
		{
			std::cout << "400 Bad Request : " << key <<std::endl;
			throw (400);
		}
		key[i] = std::tolower(key[i]);
	}
}

std::string trim(const std::string & str) {
    size_t start = 0;
    size_t end = str.length();

    while (start < str.length() && std::isspace(str[start])) {
        ++start;
    }
    while (end > start && std::isspace(str[end - 1])) {
        --end;
    }
    return ( str.substr(start, end - start) );
}

/* ************************************************************************** */
/*               ORTHODOX_CANONICAL_FORM                                      */
/* ************************************************************************** */

template <typename T>
void print(T body)
{
	// Just For asscociative Containers;
	for ( size_t i = 0; i < body.size(); i++ )
		std::cout << body[i];
}

template <typename T>
bool	isExist(T contenair, std::string key) 
{
	// Just For containers that holds std::pair
	for (typename T::iterator it = contenair.begin(); it != contenair.end(); it++)
	{
		if (it->first == key)
			return (true);
	}
	return (false);
}


Request::Request()
{
	statusCode = 0;
	index = 0;
	chunkIndex = 0;
	chunkLength = 0;
	inBody = false;
	isComplete = false;
}

Request::Request(const Request &obj)
{
	(void)obj;
}

Request &Request::operator=(const Request &obj)
{
	if (this != &obj)
	{
		this->index = obj.index;
		this->statusCode = obj.statusCode;
		this->inBody = obj.inBody;
		this->rem = obj.rem;
		this->buffer = obj.buffer;
		this->method = obj.method;
		this->path = obj.path;
		this->protocol = obj.protocol;
		this->fragement = obj.fragement;
		this->Finalpath = obj.Finalpath;
		this->query = obj.query;
		this->lines = obj.lines;
		this->header = obj.header;
		this->body = obj.body;
		this->isComplete = obj.isComplete;
	}
	return (*this);
}

Request::~Request(){
	std::cout << "Request Destructor" << std::endl;
}

/* ************************************************************************** */
/*               Getters                                    				  */
/* ************************************************************************** */
std::string Request::get_method() const {
	return ( method );
}

std::string Request::get_path() const {
	return ( path );
}

int Request::get_statusCode() const {
	return ( statusCode );
}

std::vector< char > Request::get_body() const {
	return ( body );
}

std::string const Request::getHeader( const std::string & key ) const
{
	for ( size_t i = 0; i < header.size(); i++ )
	{
		if ( header[ i ].first == key )
		{
			return ( header[ i ].second.c_str() );
		}
	}
	return ( std::string() );
}

bool Request::headerExist( const std::string & key ) const
{
	return (isExist(header, key));
}


/* ************************************************************************** */
/*					Parsing Methods											  */
/* ************************************************************************** */
void	Request::parse_path()
{
	size_t found;
	std::string Finalpath;

	while  ((found = path.find('%')) != std::string::npos)
	{
		path.replace(found, 3, 1, HexToChar(path.substr(found + 1, 2)));
	}
	std::stringstream	ss(path);	

	getline(ss, Finalpath, '?');
	std::string part;
	size_t	del;
	size_t	fragement_found;
	while (std::getline(ss, part, '?') && part.empty() == false) 
	{
		fragement_found = part.find( '#' );
		if ((del = part.find( '=' )) == std::string::npos)
		{
			throw(400);
		}
		query[part.substr(0, del)] = part.substr(del + 1, part.size() - fragement_found + 1);
		if (fragement_found != std::string::npos)
		{
			fragement = part.substr(fragement_found + 1);
			break;
		}
	}
	if (path.size() > 1024)
		throw(414);
	path = Finalpath;
}

void	Request::parseRequestLine()
{
	std::cout << index << std::endl;
	if ( index != 0 || lines[ index ] == "\r\n" )
		return ;
	std::vector<std::string> tokens = split(lines[index]);
	
	if (tokens.size() < 3 || tokens[0].empty() || tokens[1].empty() || tokens[2].empty()) 
	{
		std::cout << "Enter here" << std::endl;
		throw (404);
	}
	method = tokens[0];
	if (method != "GET" && method != "POST" && method != "DELETE")
		throw(405);
	if (tokens[2] != "HTTP/1.1")
		throw(505);
	path = tokens[1];
	protocol = tokens[2];
	parse_path();
}

void	Request::parseHeader()
{
	std::string	key;
	std::string	value;
	size_t		found_del;

	std::cout << "index : " << index << std::endl;
	exit(1);
	if ( index == 0)
		return;
	if (lines.empty() == false && lines[index] == "\r\n")
		return ;
	found_del = lines[index].find(':');
	key = lines[index].substr(0, found_del);
	value = lines[index].substr(found_del + 1);
	toLower(key);
	value = trim( value );
	if (key == "host" && ( isExist(header, key) == true || value.empty() ) ) 
	{
		throw(400);
	}
	header.push_back(std::make_pair(key, value));
}


void	Request::parse()
{
	parseRequestLine();
	parseHeader();
	checkEndOfHeaders();
}

/* ************************************************************************** */
/*               Methods                                     				  */
/* ************************************************************************** */
void Request::checkEndOfHeaders()
{
	if ( index == 0 && lines[index] == "\r\n" ) {
		throw ( 400 );
	}
	else if ( lines[index] == "\r\n" && lines[index - 1] != "\r\n" )
	{
		if (method != "POST")
		{
			(method == "GET" && !headerExist( "host" )) ? throw(400) : throw(200);
		}
		else
		{
			if ((headerExist( "content-length" ) && headerExist( "transfer-encoding" ))||
				(!headerExist( "content-length" ) && !headerExist( "transfer-encoding" )) )
			{
				throw(400);
			}
		}
		inBody = true;
	}
	else if ( lines[index] == "\r\n" && lines[index - 1] == "\r\n" ) {
		throw ( 400 );
	}
}

void	Request::headerFill()
{
	std::string	currentLine;
	std::size_t lineEndPos;

	if (inBody == true)
		return;
	if ( !rem.empty() )
	{
		currentLine = rem;
		rem.clear();
	}
	while (!buffer.empty())
	{
		currentLine += buffer[ 0 ];
		lineEndPos = currentLine.find("\r\n");
		buffer.erase(buffer.begin());
		if (lineEndPos != std::string::npos)
		{
			lines.push_back(currentLine);
			currentLine.clear();
			parse();
			if (inBody == true)
				return ;
			index++;
		}
	}
	if ( !currentLine.empty() )
	{
		rem = currentLine;
	}
}

void	Request::handleContentLength()
{
	body.insert( body.end(), buffer.begin(), buffer.end());
	if ( (int)body.size() != std::atoi(getHeader("content-length").c_str()) )
	{
		throw ( 400 );
	}
	else if ( (int)body.size() == std::atoi(getHeader("content-length").c_str()))
		throw ( 200 );
}

void	Request::handleTransferEncoding()
{
	std::string chunkLine;
	std::string chunkData;

	for (size_t i = 0; i < buffer.size(); i++ )
	{
		chunkLine += buffer.at( i );

		if (chunkLine.find("\r\n") != std::string::npos)
		{
			chunkLine.erase(chunkLine.size() - 2);

			if (chunkIndex == 0)
			{
				chunkLength = ConvertHex(chunkLine);
				chunkIndex++;
			}
			else
			{
				chunkData += chunkLine;
				chunkIndex++;
			}

			if (chunkIndex == 2)
			{
				if (chunkLength != chunkData.length())
					throw ( 400 );
				if (chunkLength == 0)
					throw ( 200 );
				body.insert(body.end(), chunkData.begin(), chunkData.end());
				chunkIndex = 0;
				chunkLine.clear();
				chunkData.clear();
			}
		}
	}
}

void	Request::bodyFill()
{
	if (inBody == true && !buffer.empty())
	{
		if (headerExist( "content-length" ))
			handleContentLength();
		else
			handleTransferEncoding();
	}
}

void	Request::print()
{
	std::cout << " ****************************Request Line***********************************" << std::endl;
	std::cout << "Method-->		:" << method << std::endl;
	std::cout << "Path---->		:" << path << std::endl;
	std::cout << "Prinintg the query if Exist---->>:" << std::endl;
	for(std::map<std::string, std::string>::iterator it = query.begin();
		it != query.end(); ++it)
	{
		std::cout << it->first << "=" << it->second << "\n";
	}  
	std::cout << "Fragement---->:" << fragement << std::endl;
	std::cout << "Protocol->	:" << protocol << std::endl;
	std::cout << " ******************************Headre*************************************" << std::endl;
	for (size_t i = 0; i < header.size(); i++)
	{
		std::cout << "===key :[" << header[i].first << "] = [" << header[i].second << "]" << std::endl; 
	}
	std::cout << " ********************************Body**************************************" << std::endl;
	// ::print(body);
}

void Request::clear()
{
	index = 0;
	statusCode = 0;
	inBody = false;
	isComplete = false;
	method.clear();	
	path.clear();
	protocol.clear();
	header.clear();
	body.clear();
	lines.clear();
	rem.clear();
	buffer.clear();
	fragement.clear();
	Finalpath.clear();
	query.clear();
}

/* ************************************************************************** */
/*				Setup											  			  */
/* ************************************************************************** */

void Request::setup( std::vector<char> & newBuffer )
{
	buffer = newBuffer;
	try {
		headerFill();
		bodyFill();
	}
	catch ( int & e )
	{
		statusCode = e;
		std::cout << statusCode << std::endl;
		isComplete = true;
	};
}
