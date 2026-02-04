#include "bigint.hpp"

bigint::bigint(): _num_str("0")
{}

bigint::bigint(const std::string& num_str) {
	this->_num_str = num_str;
}

bigint::bigint(unsigned int num) {
	std::ostringstream ss;
	ss << num;
	if (!ss)
	{
		throw std::runtime_error("Cannot parse number");
	}
	this->_num_str = ss.str();
}

bigint::bigint(const bigint& src) {
	*this = src;
}

bigint& bigint::operator=(const bigint& src) {
	if (this != &src)
	{
		this->_num_str = src._num_str;
	}
	return *this;
}

bigint::~bigint()
{}

const std::string& bigint::getStrNum() const {
	return this->_num_str;
}

bigint& bigint::operator+=(const bigint& num) {
	std::string& num1 = this->_num_str;
	const std::string& num2 = num._num_str;

	int i = num1.length() - 1;
	int j = num2.length() - 1;
	int carry = 0;

	std::string res;

	while (i >= 0 || j >= 0 || carry)
	{
		int sum = carry;
		if (i >= 0)
			sum += num1[i--] - '0';
		if (j >= 0)
			sum += num2[j--] - '0';
		res.insert(res.begin(), (sum % 10) + '0');
		carry = sum / 10;
	}
	num1 = res;
	return *this;
}

bigint bigint::operator+(const bigint& num) const {
	bigint res(*this);
	res += num;
	return res;
}

bigint& bigint::operator++() {
	*this += bigint(1);
	return (*this);
}

bigint bigint::operator++(int) {
	bigint temp(*this);
	++(*this);

	return (temp);
}

std::ostream& operator<<(std::ostream& ss, const bigint& num) {
	ss << num.getStrNum();
	return ss;
}

bigint bigint::operator<<(unsigned int n) const {
	bigint res(*this);

	res._num_str.insert(res._num_str.end(), n, '0');
	return res;
}

bigint bigint::operator>>(unsigned int n) const {
	bigint res;

	if (n >= this->_num_str.length())
	{
		return res;
	}	
	res._num_str = this->_num_str;
	res._num_str.erase(res._num_str.length() - n, n);
	return(res);
}

bigint& bigint::operator<<=(unsigned int n) {
	*this = (*this << n);
	return *this;
}

bigint& bigint::operator>>=(unsigned int n) {
	*this = *this >> n;
	return *this;
}

unsigned int bigintToUINT(const bigint& n) {
	std::stringstream ss(n.getStrNum());
	unsigned int r;
	ss >> r;
	return r;
}

bigint bigint::operator<<(const bigint& n) const {
	bigint res(*this);

	res._num_str.insert(res._num_str.end(), bigintToUINT(n), '0');
	return res;
}

bigint bigint::operator>>(const bigint& n) const {
	bigint res;

	if (bigintToUINT(n) >= this->_num_str.length())
		return res;
	res._num_str = this->_num_str;
	res._num_str.erase(res._num_str.length() - bigintToUINT(n), bigintToUINT(n));
	return(res);
}

bigint& bigint::operator<<=(const bigint& n) {
	*this = (*this << n);
	return *this;
}

bigint& bigint::operator>>=(const bigint& n) {
	*this = *this >> n;
	return *this;
}

bool bigint::operator==(const bigint& n) const {
	return this->_num_str == n._num_str;
}

bool bigint::operator>(const bigint& n) const {
	return !((*this) < n);
}

bool bigint::operator<(const bigint& n) const {
	const std::string& a = this->_num_str;
	const std::string& b = n._num_str;

	if (a.length() != b.length())
		return a.length() < b.length();

	return a < b;
}

bool bigint::operator>=(const bigint& n) const {
	return ((*this > n) || (*this == n));
}
		
bool bigint::operator<=(const bigint& n) const {
	return ((*this < n) || (*this == n));
}

bool bigint::operator!=(const bigint& n) const {
	return this->_num_str != n._num_str;
}
		