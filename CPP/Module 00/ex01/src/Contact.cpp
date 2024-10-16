#include "Contact.hpp"
Contact::Contact() {

	// std::cout << "Contact constructed." << std::endl;
}

Contact::~Contact() {

	// std::cout << "Contact destroyed." << std::endl;
}

std::string	Contact::get_fname(void) const {

	return this->_fname;
}

std::string	Contact::get_lname(void) const {

	return this->_lname;
}

std::string	Contact::get_nick(void) const {

	return this->_nick;
}

std::string	Contact::get_number(void) const {

	return this->_number;
}

std::string	Contact::get_secret(void) const {

	return this->_secret;
}

void	Contact::set_fname(std::string str) {

	this->_fname = str;
}

void	Contact::set_lname(std::string str) {

	this->_lname = str;
}

void	Contact::set_nick(std::string str) {

	this->_nick = str;
}

void	Contact::set_number(std::string str) {

	this->_number = str;
}

void	Contact::set_secret(std::string str) {

	this->_secret = str;
}