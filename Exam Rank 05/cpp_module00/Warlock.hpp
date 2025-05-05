#pragma once
# include <string>
# include <iostream>

// Coplien's Form = Orthodox Canonical Form
class	Warlock
{
	public:
		Warlock(const std::string& name, const std::string& title);
		~Warlock();

		const std::string&	getName() const;
		const std::string&	getTitle() const;
		void				setTitle(const std::string& title);

		void				introduce() const;

	private:
		std::string	name;
		std::string	title;

		Warlock();		// Private default constructor to prevent instantiation without name and title
		Warlock(const Warlock& other);					// Warlock bob(jim);
		Warlock&	operator = (const Warlock& other);	// bob = jim;

};