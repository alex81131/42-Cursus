#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void):
	AForm("RobotomyRequestForm", "N/A", 72, 45)
{
	std::cout << "[RobotomyRequestForm] Default constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target):
	AForm("RobotomyRequestForm", target, 72, 45)
{
	std::cout << "[RobotomyRequestForm] Parameterized constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src):
	AForm(src.getName(), src.getTarget(), src.getSignGrade(), src.getExeGrade())
{
	std::cout << "[RobotomyRequestForm] Copy constructor called." << std::endl;
	*this = src;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& src)
{
	std::cout << "[RobotomyRequestForm] Assignment operator called." << std::endl;
	if (this == &src)
		return *this;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "[RobotomyRequestForm] Destructor called." << std::endl;
}

/*________________Utils_________________*/
void	RobotomyRequestForm::doExe(void) const
{
	// Use current time as seed for random generator
	srand(time(NULL));
	std::cout <<"🤖🔊 *BOOP* ⚙️🛠️" << std::endl;
	std::cout <<"🤖🔊 *BEEP* | *BOOP* ⚙️🛠️" << std::endl;
	std::cout <<"🤖🔊 *BZZZZT* ⚡️💥 *BEEP* | *BOOP* ⚙️🛠️" << std::endl;
	if (rand() % 2 == 0)
		std::cout << this->getTarget() <<" has been successfully robotomized." << std::endl << std::endl;
	else
		std::cout << this->getTarget()  << " failed to get robotomized." << std::endl << std::endl;
}