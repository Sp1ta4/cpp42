#ifndef FORM_HPP
# define FORM_HPP

# include <string>
class Form

{
	private:
		const std::string	m_name;
		bool 				m_isSigned;
		const int			m_signGrade;
		const int			m_execGrade;
	public:
		Form(/* args */);
		~Form();

		const int						getSignGrade()	const;
		const int						getExecGrade()	const;
		bool							getIsSigned()	const;
		const std::string				getName()		const;

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