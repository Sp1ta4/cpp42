#ifndef BIGINT_HPP
# define BIGINT_HPP
# include <string>
# include <sstream>
# include <iostream>

class bigint
{
	private:
		std::string _num_str;
		bigint(const std::string& num_str);
	public:
		bigint();
		bigint(unsigned int num);
		bigint(const bigint& src);
		~bigint();

		const std::string& getStrNum() const;

		bigint& operator=(const bigint& src);

		bigint  operator+(const bigint& num) const;
		bigint& operator+=(const bigint& num);
		bigint& operator++();
		bigint 	operator++(int);

		bigint  operator<<(unsigned int n) const;
		bigint  operator>>(unsigned int n) const;
		bigint& operator<<=(unsigned int n);
		bigint& operator>>=(unsigned int n);
		
		bigint  operator<<(const bigint& n) const;
		bigint  operator>>(const bigint& n) const;
		bigint& operator<<=(const bigint& n);
		bigint& operator>>=(const bigint& n);

		bool operator==(const bigint& n) const;
		bool operator>=(const bigint& n) const;
		bool operator<=(const bigint& n) const;
		bool operator>(const bigint& n) const;
		bool operator<(const bigint& n) const;
		bool operator!=(const bigint& n) const;
};


std::ostream& operator<<(std::ostream& ss, const bigint& num);

#endif