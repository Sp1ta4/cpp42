#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), m_target("UNDEFINED")
{
	std::cout << GREEN << "RobotomyRequestForm default constructor called" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), m_target(target)
{
	std::cout << GREEN << "RobotomyRequestForm constructor with parameters called" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), m_target(other.m_target)
{
	std::cout << GREEN << "RobotomyRequestForm copy constructor called" << RESET << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	std::cout << GREEN << "RobotomyRequestForm copy assignment operator called" << RESET << std::endl;
	if (this != &other)
	{
		AForm::operator=(other);
		this->m_target = other.m_target;
	}
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	AForm::execute(executor);
	std::cout << "###drilling noise###" << std::endl;
	if ((std::rand() % 2) == 0)
		std::cout << m_target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "The robotomyoform" << m_target << " failed." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << RED << "RobotomyRequestForm destructor called" << RESET << std::endl;
}