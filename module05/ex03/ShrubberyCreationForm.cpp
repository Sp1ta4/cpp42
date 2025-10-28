#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), m_target("UNDEFINED")
{
	std::cout << GREEN "ShrubberyCreationForm default constructor called" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), m_target(target)
{
	std::cout << GREEN "ShrubberyCreationForm constructor with parameters called" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), m_target(other.m_target)
{
	std::cout << GREEN "ShrubberyCreationForm copy constructor called" << RESET << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	std::cout << GREEN "ShrubberyCreationForm copy assignment operator called" << RESET << std::endl;
	if (this != &other)
	{
		AForm::operator=(other);
		this->m_target = other.m_target;
	}
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    AForm::execute(executor);
    std::ofstream fileout((m_target + "_shrubbery").c_str());
    if (!fileout.is_open())
        throw std::runtime_error("Failed to open output file");
    fileout << "       _-_       " << std::endl;
    fileout << "    /~~   ~~\\   " << std::endl;
    fileout << " /~~         ~~\\ " << std::endl;
    fileout << "{               }" << std::endl;
    fileout << " \\  _-     -_  / " << std::endl;
    fileout << "   ~  \\\\ //  ~  " << std::endl;
    fileout << "_- -   | | _- _  " << std::endl;
    fileout << "  _ -  | |   -_  " << std::endl;
    fileout << "      // \\\\      " << std::endl;
    fileout.close();
}


ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm's Destructor called" << std::endl;
}