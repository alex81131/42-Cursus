#include "Request.hpp"

Request::Request(const std::string& str): AHttpData(str, true)
{
	try
	{this->parseHead();}
	catch(const std::exception& e)
	{std::cerr << "[Request] Error: " << e.what() << std::endl;}
}

Request::Request(const Request& other): AHttpData(other.getRaw(), true)
{*this = other;}

Request&	Request::operator=(const Request& other)
{
	if (this != &other)
	{
		AHttpData::operator=(other);
		this->_method = other._method;
		this->_url = other._url;
		this->_http_version = other._http_version;
	}
	return *this;
}

Request::~Request() {}

const std::string&	Request::getMethod() const
{return this->_method;}

const std::string&	Request::getUrl() const
{return this->_url;}

const std::string&	Request::getHttpVersion() const
{return this->_http_version;}

const std::string&	Request::getQueryString() const
{return this->_query_string;}

void	Request::parseHead()
{
	/* Parse Method */
	std::size_t	mtd_end = _raw.find(" ");
	if (mtd_end == std::string::npos)
		throw std::runtime_error("Method Not Found.\n");
	_method = _raw.substr(0, mtd_end);

	/* Parse URL */
	std::size_t	url_start = _raw.find_first_not_of(" ", mtd_end + 1);
	if (url_start == std::string::npos)
		throw std::runtime_error("URL Not Found.\n");
	std::size_t url_end = _raw.find(" ", url_start);
	if (url_end == std::string::npos)
		throw std::runtime_error("URL Not Found.\n");
	_url = _raw.substr(url_start, url_end - url_start);
	std::size_t query_start = _url.find('?');
	if (query_start != std::string::npos)
		_query_string = _url.substr(query_start + 1);
	_url = _url.substr(0, query_start);

	/* Parse HTTP version */
	std::size_t http_start = _raw.find_first_of("HTTP/", url_end + 1);
	if (http_start == std::string::npos)
		throw std::runtime_error("HTTP version Not Found.\n");
	std::size_t http_end = _raw.find('\n', http_start);
	if (http_end == std::string::npos)
		throw std::runtime_error("HTTP version Not Found.\n");
	_http_version = _raw.substr(http_start, http_end - http_start);
	if (!_http_version.empty() && _http_version[_http_version.length() - 1] == '\r')
		_http_version.erase(_http_version.length() - 1);
}

// Debug function to print all elements in Request class
void	Request::printAll()
{
	std::cout << "Method:\t" << this->getMethod() << std::endl;
	std::cout << "Url:\t" << this->getUrl() << std::endl;
	std::cout << "Http:\t" << this->getHttpVersion() << std::endl;
	std::cout << "Query String:\t" << this->getQueryString() << std::endl;
	std::cout << "\n------------------Headers------------------" << std::endl;
	std::map<std::string, std::string>::iterator it;
	for (it = this->_headers.begin(); it != this->_headers.end(); it++) {
		std::cout << "[" << it->first << "] : \"" << it->second << "\"" << std::endl;
	}
	std::cout << "\n---------------End of Headers---------------" << std::endl;
	// std::cout << "\n-------------------Body---------------------" << std::endl;
	// std::cout << this->getBody() << std::endl;
	// std::cout << "\n--------------------Raw---------------------" << std::endl;
	// std::cout << this->_raw << std::endl;
}