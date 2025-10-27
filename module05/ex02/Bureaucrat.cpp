#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() :
	m_name("NO_NAME"),
	m_grade(150)
{
	std::cout << GREEN << "Bureaucrat default constructor called" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) :
	m_name(name),
	m_grade(grade)
{
	std::cout << GREEN << "Bureaucrat parameterized constructor called" << RESET << std::endl;

	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const & other) :
	m_name(other.m_name),
	m_grade(other.m_grade)
{
	std::cout << GREEN << "Bureaucrat copy constructor called" << RESET << std::endl;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const & other)
{
	std::cout << GREEN << "Bureaucrat copy assignment operator called" << RESET << std::endl;
	if (this != &other)
		this->m_grade = other.m_grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << RED << "Bureaucrat destructor called" << RESET << std::endl;
}

int Bureaucrat::getGrade() const
{
	return this->m_grade;
}

const std::string Bureaucrat::getName() const
{
	return this->m_name;
}

void Bureaucrat::incrementGrade()
{
	if (this->m_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	this->m_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (this->m_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	this->m_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

void	Bureaucrat::signForm(AForm &form) const {
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
};


std::ostream & operator<<(std::ostream & o, Bureaucrat const & b)
{
	o << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return o;
}