#include "Contact.hpp"

Contact::Contact(void)
	: _firstName("")
	, _lastName("")
	, _nickname("")
	, _darkestSecret("")
	, _phoneNumber("")
{}

Contact::Contact(const Contact &other)
{
	*this = other;
}

Contact::Contact(std::string firstName,
				 std::string lastName,
				 std::string nickname,
				 std::string darkestSecret,
				 std::string phoneNumber)
	: _firstName(firstName), _lastName(lastName), _nickname(nickname), _darkestSecret(darkestSecret), _phoneNumber(phoneNumber)
{}

Contact &Contact::operator=(const Contact &other)
{
	if (this != &other)
	{
		this->_firstName = other._firstName;
		this->_lastName = other._lastName;
		this->_nickname = other._nickname;
		this->_darkestSecret = other._darkestSecret;
		this->_phoneNumber = other._phoneNumber;
	}
	return *this;
}

Contact::~Contact(void) {}

std::string Contact::getFirstName() const
{
	return _firstName;
}

std::string Contact::getLastName() const
{
	return _lastName;
}

std::string Contact::getNickname() const
{
	return _nickname;
}

std::string Contact::getDarkestSecret() const
{
	return _darkestSecret;
}

std::string Contact::getPhoneNumber() const
{
	return _phoneNumber;
}

void Contact::setFirstName(const std::string &firstName)
{
	_firstName = firstName;
}

void Contact::setLastName(const std::string &lastName)
{
	_lastName = lastName;
}

void Contact::setNickname(const std::string &nickname)
{
	_nickname = nickname;
}

void Contact::setDarkestSecret(const std::string &darkestSecret)
{
	_darkestSecret = darkestSecret;
}

void Contact::setPhoneNumber(const std::string &phoneNumber)
{
	_phoneNumber = phoneNumber;
}
