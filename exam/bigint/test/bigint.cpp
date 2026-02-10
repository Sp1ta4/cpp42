#include "bigint.hpp"

bigint::bigint(): _num_str("0") {}

bigint::~bigint(){}

bigint::bigint(unsigned int n) {
	std::ostringstream ss;

	ss << n;
	_num_str = ss.str();
}

bigint::bigint(const bigint& b) {
	*this = b;
}

bigint& bigint::operator=(const bigint& b) {
	if (this != &b)
		this->_num_str = b._num_str;
	return *this;
}

bigint::bigint(std::string s) {
	this->_num_str = s;
}

std::string bigint::getStr() const {
	return this->_num_str;
}

bigint bigint::operator+(const bigint& n) const {
	bigint res(*this);

	res += n;
	return res;
}

bigint& bigint::operator+=(const bigint& n) {
		std::string &num1 = this->_num_str;
		const std::string& num2 = n._num_str;

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
			res.insert(res.begin(), sum % 10 + '0');
			carry = sum / 10;
		}
		num1 = res;
		return *this;
}

bigint& bigint::operator++() {
	*this += bigint(1);
	return *this;
}

bigint bigint::operator++(int) {
	bigint res(*this);
	++(*this);

	return res;
}

unsigned int bigintToUINT(const bigint& n) {
	std::stringstream ss(n.getStr());

	unsigned int res;
	
	ss >> res;
	return res;
}

bigint bigint::operator<<(const bigint& n) const {
	bigint res(*this);
	std::string &s = res._num_str;
	
	s.insert(s.end(), bigintToUINT(n), '0');
	return res;
}

bigint bigint::operator>>(const bigint& n) const {
	bigint res;
	
	unsigned int nn = bigintToUINT(n);

	if (nn >= this->_num_str.length())
		return res;
	res = *this;
	std::string &s = res._num_str;
	s.erase(s.length() - nn, nn);
	return res;
}

bigint& bigint::operator<<=(const bigint& n) {
	*this = *this << n;
	return *this;
}

bigint& bigint::operator>>=(const bigint& n) {
	*this = *this >> n;
	return *this;
}

bigint bigint::operator<<(unsigned int n) const {
	bigint res(*this);

	res._num_str.insert(res._num_str.end(), n, '0');
	return res;
}

bigint bigint::operator>>(unsigned int n) const {
	bigint res;

	if (n >= this->_num_str.length())
		return res;

	res = *this;
	std::string &s = res._num_str;

	s.erase(s.length() - n, n);
	return res;
}

bigint& bigint::operator<<=(unsigned int n) {
	*this = *this << n;

	return *this;
}

bigint& bigint::operator>>=(unsigned int n) {
	*this = *this >> n;
	return *this;
}


bool bigint::operator==(const bigint& n) const
{
	return this->_num_str == n._num_str;
}

bool bigint::operator!=(const bigint& n) const
{
	return !(*this == n);
}

bool bigint::operator<(const bigint& n) const {
	std::string a = this->_num_str;
	const std::string b = n._num_str;
	
	if (a.length() != b.length())
		return a.length() < b.length();

	return a < b;
}

bool bigint::operator>(const bigint& n) const {
	return !(*this < n);
}

bool bigint::operator<=(const bigint& n) const {
	return ((*this < n) || (*this == n));
}

bool bigint::operator>=(const bigint& n) const {
	return ((*this > n) || (*this == n));
}

std::ostream& operator<<(std::ostream& ss, const bigint& n) {
	ss << n.getStr();
	return ss;
}







