#include <string>
#include <sys/stat.h>
#include "utils.hpp"

bool	is_directory(const std::string &path)
{
	struct stat	s;

	if (stat(path.c_str(), &s) == 0)
		if (s.st_mode & S_IFDIR)
			return true;
	return false;
}

bool	end_with_json(const std::string &c)
{
	std::string	suffix = ".json";

	if (c.length() >= suffix.length())
		return (c.compare(c.length() - suffix.length(), suffix.length(), suffix) == 0);
	return false;
	}
