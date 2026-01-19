#ifndef BIGINT_HPP
#define BIGINT_HPP
#include <string>
#include <sstream>
#include <iostream>

class bigint
{
	private:
		std::string _str_num;
		bigint(const std::string& str);

	public:
		bigint();
		bigint(unsigned int num);
		bigint(const bigint& source);
		~bigint();

		const std::string& getStrNum() const;
		bigint& operator=(const bigint& source);

		bigint  operator+(const bigint& num) const;
		bigint& operator+=(const bigint& num);
		bigint& operator++();
		bigint  operator++(int);

		bigint operator<<(unsigned int n) const;
		bigint operator>>(unsigned int n) const;
		bigint& operator<<=(unsigned int n);
		bigint& operator>>=(unsigned int n);

		bigint operator<<(bigint& other) const;
		bigint operator>>(bigint& other) const;
		bigint& operator<<=(const bigint& other);
		bigint& operator>>=(const bigint& other);

		bool operator==(const bigint& other) const;
		bool operator!=(const bigint& other) const;
		bool operator<(const bigint& other) const;
		bool operator>(const bigint& other) const;
		bool operator<=(const bigint& other) const;
		bool operator>=(const bigint& other) const;

	};

std::ostream& operator<<(std::ostream& out, const bigint& num);

#endif