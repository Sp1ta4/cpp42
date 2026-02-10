#pragma once

#include <iostream>
#include <sstream>
#include <string>

class bigint {
	private:
		std::string _num_str;
		bigint(std::string);

	public:
		bigint();
		~bigint();
		bigint(unsigned int);
		bigint(const bigint&);
		bigint& operator=(const bigint&);

		std::string getStr() const;

		bigint operator+(const bigint&) const;
		bigint& operator+=(const bigint&);

		bigint& operator++();
		bigint operator++(int);

		bigint operator<<(const bigint&) const;
		bigint operator>>(const bigint&) const;
		
		bigint& operator<<=(const bigint&);
		bigint& operator>>=(const bigint&);

		bigint operator<<(unsigned int) const;
		bigint operator>>(unsigned int) const;

		bigint& operator<<=(unsigned int);
		bigint& operator>>=(unsigned int);

		bool operator==(const bigint&) const;
		bool operator!=(const bigint&) const;
		bool operator>=(const bigint&) const;
		bool operator<=(const bigint&) const;
		bool operator>(const bigint&) const;
		bool operator<(const bigint&) const;


};

std::ostream& operator<<(std::ostream &ss, const bigint& n);
