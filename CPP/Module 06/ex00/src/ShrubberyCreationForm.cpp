#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void):
	AForm("ShrubberyCreationForm", "N/A", 145, 137)
{
	std::cout << "[ShrubberyCreationForm] Default constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target):
	AForm("ShrubberyCreationForm", target, 145, 137)
{
	std::cout << "[ShrubberyCreationForm] Parameterized constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src):
	AForm(src.getName(), src.getTarget(), src.getSignGrade(), src.getExeGrade())
{
	std::cout << "[ShrubberyCreationForm] Copy constructor called." << std::endl;
	*this = src;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator = (const ShrubberyCreationForm& src)
{
	std::cout << "[ShrubberyCreationForm] Assignment operator called." << std::endl;
	if (this == &src)
		return *this;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "[ShrubberyCreationForm] Destructor called." << std::endl;
}

/*________________Utils_________________*/
void	ShrubberyCreationForm::doExe(void) const
{
	{
		std::string		filename = this->getTarget() + "_shrubbery";
		std::ofstream	ofs(filename.c_str(), std::ofstream::out | std::ofstream::trunc);
		if (ofs.fail())
			throw std::exception();
		ofs << 
		"                   @                         \n" <<
		"                  X*o                        \n" <<
		"                 *O**x                       \n" <<
		"                o**X***                      \n" <<
		"               ***x****O                     \n" <<
		"              X******o***                    \n" <<
		"               ***xO****                     \n" <<
		"              ***o****X**                    \n" <<
		"             **O***x****O*                   \n" <<
		"            *o*X******o*X**                  \n" <<
		"           O*******xO*******                 \n" <<
		"          ***x****o****X*****                \n" <<
		"        **X*****O**********x***              \n" <<
		"                  ###                        \n" <<
		"                  ###                        \n" <<
		"                  ###                        \n" <<
		"              ###########                    \n" <<
		"              ###########                    " << std::endl;
	}
}

// std::ofstream::out | std::ofstream::trunc:
// 1. specify that the file is opened for output
// 2. truncate, if the file already exists, its content will be cleared when opened