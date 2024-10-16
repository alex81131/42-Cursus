#ifndef SED_HPP
# define SED_HPP

# include <iostream>
# include <fstream>

class	sed {

	public:
		sed();
		~sed();

		static int	replace(std::string filename, const std::string s1, const std::string s2);

	private:
		std::string	_in;
		std::string	_out;

};

#endif

// <fstream>:
// 	input and output file stream