#include "ShrubberyCreationForm.hpp"

const std::string ShrubberyCreationForm::m_shrubbery =
	"          &&& &&  & &&\n"
	"      && &\\/&\\|& ()|/ @, &&\n"
	"      &\\/(/&/&||/& /_/)_&/_&\n"
	"   &() &\\/&|()|/&\\/ '%\" & ()\n"
	"  &_\\_&&_\\ |& |&&/&__%_/_& &&\n"
	"&&   && & &| &| /& & % ()& /&&\n"
	"   ()&_---()&\\&\\|&&-&&--%---()~\n"
	"               &&     \\|||\n"
	"                        |||\n"
	"                        |||\n"
	"                        |||\n"
	"                  , -=-~  .-^- _\n";

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

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	AForm::execute(executor);
	std::ofstream fileout(m_target + "_shrubbery");
	if (!fileout.is_open())
	{
		std::cerr << "File can't be opened" << std::endl;
		return;
	}
	fileout << m_shrubbery << std::endl;
	fileout.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm's Destructor called" << std::endl;
}