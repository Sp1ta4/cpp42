#include "Form.hpp"

Form::Form()
	: m_name("NO_NAME")
	, m_isSigned(false)
	, m_signGrade(150)
	, m_execGrade(150)
{
	std::cout << GREEN << "Form default constructor called" << RESET << std::endl;
}

Form::Form(std::string name, int signGrade, int execGrade)
	: m_name(name)
	, m_isSigned(false)
	, m_signGrade(signGrade)
	, m_execGrade(execGrade)
{
	std::cout << GREEN << "Form parameterized constructor called" << RESET << std::endl;
	
	if (this->m_signGrade < 1 || this->m_execGrade < 1)
		throw Form::GradeTooHighException();
	else if (this->m_signGrade > 150 || this->m_execGrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(Form const & other) 
	: m_name(other.m_name)
	, m_isSigned(other.m_isSigned)
	, m_signGrade(other.m_signGrade)
	, m_execGrade(other.m_execGrade)
{
	std::cout << GREEN << "Form copy constructor called" << RESET << std::endl;
};

Form& Form::operator=(Form const & other)
{
	std::cout << GREEN << "Form copy assignment operator called" << RESET << std::endl;
	if (this != &other)
		this->m_isSigned = other.m_isSigned;
	return *this;
}

Form::~Form()
{
	std::cout << RED << "Form destructor called" << RESET << std::endl;
}

int	Form::getSignGrade()	const {
	return (this->m_signGrade);
};

int	Form::getExecGrade()	const {
	return (this->m_execGrade);
};

bool	Form::getIsSigned()	const {
	return (this->m_isSigned);
};

const std::string	Form::getName()		const { 
	return (this->m_name);
};

void	Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() <= this->m_signGrade)
		this->m_isSigned = true;
	else
		throw Form::GradeTooLowException();
};

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

std::ostream& operator<<(std::ostream& os, const Form& point) {
        os << "Form name : " << point.getName() << ", Grade to sign : " << \
				point.getSignGrade() << ", Grade to execute : " << point.getExecGrade() \
				<< ", Form " << (point.getIsSigned() ? ", is signed" : ", is not signed");
        return os;
}