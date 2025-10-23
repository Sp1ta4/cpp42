#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <stdexcept>

# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN    "\033[36m"

class Bureaucrat
{
	private:
		std::string const m_name;
		int m_grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const & other);
		Bureaucrat & operator=(Bureaucrat const & other);
		~Bureaucrat();

		int						getGrade()	const;
		const std::string		getName()	const;
		void					incrementGrade();
		void					decrementGrade();

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

std::ostream & operator<<(std::ostream & o, Bureaucrat const & b);

#endif