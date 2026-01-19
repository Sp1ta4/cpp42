#include "bigint.hpp"

bigint::bigint() : _str_num("0")
{}

bigint::bigint(unsigned int num)
{
	std::ostringstream ss;

	ss << num;
	if (!ss)
	{
		throw std::runtime_error("Cannot parse numer");
	}
	this->_str_num = ss.str();
}

bigint& bigint::operator=(const bigint& source)
{
	if (this != &source)
		this->_str_num = source._str_num;

	return *this;
}

bigint::bigint(const std::string& str)
{
	if (str.empty())
		_str_num = "0";
	else
		_str_num = str;
}

bigint::bigint(const bigint& source) {
	*this = source;
}

bigint::~bigint()
{
}

const std::string& bigint::getStrNum() const {
	return this->_str_num;
}

bigint bigint::operator+(const bigint& rhs) const
{
	bigint tmp(*this);
	tmp += rhs;
	return tmp;
}

bigint& bigint::operator+=(const bigint& num)
{
	const std::string& num2 = num._str_num;
	std::string& num1 = this->_str_num;

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

bigint& bigint::operator++()
{
	*this += bigint(1);
	return *this;
}

bigint bigint::operator++(int) {
	bigint temp = *this;
	*this += bigint(1);

	return temp;
}

bigint bigint::operator<<(unsigned int n) const
{
	bigint res = *this;
	res._str_num.insert(res._str_num.end(), n, '0');
	return res;
}

bigint bigint::operator>>(unsigned int n) const
{
	bigint res = *this;
	size_t len = res._str_num.length();

	if (n >= len)
		res._str_num = "0";
	else
		res._str_num.erase(res._str_num.length() - n, n);
	
	return res;
}

bigint& bigint::operator<<=(unsigned int n) {
	*this = *this << n;
	return *this; 
}

bigint& bigint::operator>>=(unsigned int n) {
	*this = *this >> n;
	return *this; 
};

unsigned int stringToUINT(std::string str)
{
	std::stringstream ss(str);
	unsigned int res;
	ss >> res;
	return (res);
}

bigint bigint::operator<<(bigint& other) const
{
	bigint res = *this;
	res._str_num.insert(res._str_num.end(), stringToUINT(other._str_num), '0');
	return res;
}

bigint bigint::operator>>(bigint& other) const
{
	bigint res = *this;
	res = res >> stringToUINT(other._str_num);
	return res;
}

bigint& bigint::operator<<=(const bigint& other) {
	*this = *this << stringToUINT(other._str_num);
	return *this; 
}

bigint& bigint::operator>>=(const bigint& other) {
	*this = *this >> stringToUINT(other._str_num);
	return *this; 
};

bool bigint::operator==(const bigint& other) const {
	return (this->_str_num == other._str_num);
}

bool bigint::operator!=(const bigint& other) const {
	return (this->_str_num != other._str_num);	
};
	
bool bigint::operator<(const bigint& other) const
{
	const std::string& a = _str_num;
	const std::string& b = other._str_num;

	if (a.length() != b.length())
		return a.length() < b.length();

	return a < b;
}

bool bigint::operator>(const bigint& other) const
{
	return (!((*this) < other));
}

bool bigint::operator<=(const bigint& other) const
{
	return (((*this) < other) || ((*this) == other));
}

bool bigint::operator>=(const bigint& other) const
{
	return (((*this) > other) || ((*this) == other));
}

std::ostream& operator<<(std::ostream& out, const bigint& num) {
	out << num.getStrNum();
	return out;
}
