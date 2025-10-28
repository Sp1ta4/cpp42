#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string	const	m_name;
		bool 				m_isSigned;
		int			const 	m_signGrade;
		int			const 	m_execGrade;
	public:
		AForm();
		AForm(std::string name, int signGrade, int execGrade);
		AForm(AForm const & other);
		AForm & operator=(AForm const & other);
		virtual ~AForm();

		int					getSignGrade()	const;
		int					getExecGrade()	const;
		bool				getIsSigned()	const;
		const std::string	getName()		const;
		void				beSigned(const Bureaucrat& bureaucrat);
		virtual void		execute(Bureaucrat const &executor) const = 0;

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

		class FormNotSignedException : public std::exception
		{
			const char *what() const throw();
		};
};

std::ostream & operator<<(std::ostream & o, AForm const & f);


#endif