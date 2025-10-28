#include "AForm.hpp"

AForm::AForm()
	: m_name("NO_NAME")
	, m_isSigned(false)
	, m_signGrade(150)
	, m_execGrade(150)
{
	std::cout << GREEN << "AForm default constructor called" << RESET << std::endl;
}

AForm::AForm(std::string name, int signGrade, int execGrade)
	: m_name(name)
	, m_isSigned(false)
	, m_signGrade(signGrade)
	, m_execGrade(execGrade)
{
	std::cout << GREEN << "AForm parameterized constructor called" << RESET << std::endl;
	
	if (this->m_signGrade < 1 || this->m_execGrade < 1)
		throw AForm::GradeTooHighException();
	else if (this->m_signGrade > 150 || this->m_execGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const & other) 
	: m_name(other.m_name)
	, m_isSigned(other.m_isSigned)
	, m_signGrade(other.m_signGrade)
	, m_execGrade(other.m_execGrade)
{
	std::cout << GREEN << "AForm copy constructor called" << RESET << std::endl;
};

AForm& AForm::operator=(AForm const & other)
{
	std::cout << GREEN << "AForm copy assignment operator called" << RESET << std::endl;
	if (this != &other)
		this->m_isSigned = other.m_isSigned;
	return *this;
}

AForm::~AForm()
{
	std::cout << RED << "AForm destructor called" << RESET << std::endl;
}

int	AForm::getSignGrade() const {
	return (this->m_signGrade);
};

int	AForm::getExecGrade() const {
	return (this->m_execGrade);
};

bool	AForm::getIsSigned() const {
	return (this->m_isSigned);
};

const std::string	AForm::getName() const { 
	return (this->m_name);
};

void	AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() <= this->m_signGrade)
		this->m_isSigned = true;
	else
		throw AForm::GradeTooLowException();
};

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

const char *AForm::FormNotSignedException::what() const throw() {
	return "Form is not signed!";
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (this->m_isSigned == false)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->m_execGrade)
		throw AForm::GradeTooLowException();
}


std::ostream& operator<<(std::ostream& os, const AForm& point) {
        os << "AForm name : " << point.getName() << ", Grade to sign : " << \
				point.getSignGrade() << ", Grade to execute : " << point.getExecGrade() \
				<< ", AForm " << (point.getIsSigned() ? ", is signed" : ", is not signed");
        return os;
}