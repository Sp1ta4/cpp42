#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string	const	m_name;
		bool 				m_isSigned;
		int			const 	m_signGrade;
		int			const 	m_execGrade;
	public:
		Form();
		Form(std::string name, int signGrade, int execGrade);
		Form(Form const & other);
		Form & operator=(Form const & other);
		~Form();

		int					getSignGrade()	const;
		int					getExecGrade()	const;
		bool				getIsSigned()	const;
		const std::string	getName()		const;
		void				beSigned(const Bureaucrat& bureaucrat);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream & operator<<(std::ostream & o, Form const & f);


#endif