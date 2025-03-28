#pragma once

#include "json.hpp"
#include <netdb.h>
#include <stdint.h>
#include <map>
#include <set>
#include <sys/types.h>
#include <vector>

class Config
{
	public:
		Config(const JsonValue &j);
		~Config();

		typedef std::vector<Config>			config_list;
		static void							check_error_page(int page);
		static addrinfo*					ini_addrinfo(const std::string &host, const std::&port);
		// Getters
		const std::string&					get_name() const;
		const std::string&					get_host() const;
		uint64_t							get_address() const;
		uint64_t							get_max_body_size() const;
		int									get_port() const;
		const addrinfo*						get_addr() const;
		const std::map<int, std::string>&	get_error_page() const;
		const std::vector<Route>&			get_route() const;

		class BadValue: public std::exception
		{
			public:
				BadValue(): _message("Bad value in config.") {}
				BadValue(const std::string &s): _message(s) {}
				virtual ~BadValue() throw() {}

				const char *what() const throw() {return _message.c_str();}
			private:
				std::string _message;
		};

		struct Route
		{
			Route();
			Route(const JsonValue &j);

			std::string	path;			// Corresponds to "route" in the config "routes". Use this to find the most matched routes to URL.
			std::string	index;			// Default file to open if the file path is empty.
			std::string	directory;		// Default redirected directory methods except for POST
			std::string	upload;			// Default redirected directory for POST
			bool		dir_listing;	// Flag to see if the output is a listing of directories.
			bool		is_redirection;
			std::string	redirection;

			std::set<std::string>				method;
			std::map<std::string, std::string>	cgi;
		};

	private:
		std::string					_name;
		std::string					_host;
		uint64_t					_address;
		uint64_t					_max_body_size;
		int							_port;
		addrinfo					*_addr;
		std::map<int, std::string>	_error_page;
		std::vector<Route>			_route;
		const JsonValue				&_json;

		static std::string			handle_directory(const std::string &s);
		const std::string			&set (const std::string &value_, const std::string &__default);
		static const std::string	&set (const std::string &value, const std::string &__default, const JsonValue &j);
};