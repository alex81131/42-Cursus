#pragma once
#include <string>

bool	is_directory(const std::string &path);
bool	end_with_json(const std::string &c);
enum	CgiResult
{
	SUCCESS,
	TIMEOUT,
	NOTFOUND,
	ERROR
};