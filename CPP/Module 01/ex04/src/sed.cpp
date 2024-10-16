#include "sed.hpp"
#include <limits>

sed::sed(){}

sed::~sed(){}

int	sed::replace(std::string filename, const std::string s1, const std::string s2) {
	std::ifstream	infile(filename.c_str());

	if (infile.fail()) {
		std::cerr << "Error: failed to open " << filename << "." << std::endl;
		return 1;
	}
	std::ofstream	outfile((filename + ".replace").c_str(), std::ios::trunc);
	if (outfile.fail()) {
		std::cerr << "Error: invalid output file." << std::endl;
		infile.close();
		return 1;
	}
	if (s1.size() > 0 && s2.size() > 0) {
		std::string	line;
		// Read lines
		bool	firstLine = true;
		while (std::getline(infile, line)) {
			std::size_t pos = 0;
			// Replace strings
			while ((pos = line.find(s1, pos)) != std::string::npos) {
				line.erase(pos, s1.size());
				line.insert(pos, s2);
				pos += s2.size();
			}
			// Line break except for the first line
			if (firstLine)
				firstLine = false;
			else
				outfile << '\n';
			outfile << line;
		}
	}
	else {
		std::cerr << "Error: invalid strings." << std::endl;
		infile.close();
		outfile.close();
		return 1;
	}
	infile.close();
	outfile.close();
	return 0;
}

// .c_str()
// 	converts the std::string object to a C-style string.
// std::ios::trunc
// 	if the file already exists, it will be emptied before writing.
// std::getline(infile, line)
// 	reads "infile" until \n and stores it in "line"
// std::string::npos
// 	find() searches for a substring and returns the position of the first occurrence.
// 	If the substring is not found, it returns std::string::npos,
// 	which is typically equal to the maximum possible value of std::size_t,
// 	and often used to signify an invalid index or position in a string.
// outfile << line
// 	writes the string "line" to the file "outfile"