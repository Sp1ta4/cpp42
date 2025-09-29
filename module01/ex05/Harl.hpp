#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>


class Harl
{
	private:
		void warning(void);
		void debug(void);
		void error(void);
		void info(void);

	public:
		Harl(void);
		~Harl(void);
		void complain(std::string level);
};

#endif