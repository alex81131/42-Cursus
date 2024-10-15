#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class	Contact {

	private:
		std::string	_fname;
		std::string	_lname;
		std::string	_nick;
		std::string	_number;
		std::string	_secret;

	public:
		Contact(void);
		~Contact(void);

		std::string	get_fname(void) const;
		std::string	get_lname(void) const;
		std::string	get_nick(void) const;
		std::string	get_number(void) const;
		std::string	get_secret(void) const;
		void		set_fname(std::string str);
		void		set_lname(std::string str);
		void		set_nick(std::string str);
		void		set_number(std::string str);
		void		set_secret(std::string str);

};

#endif
// <iostream>:
// 	std::cin, cout, getline

// <string>:
// 	std::string

// A class is basically a group.
// public:		Accessible from anywhere
// private:	Accessible only within the class
// In many coding standards, a leading underscore is used to signify that a variable is a private member of a class