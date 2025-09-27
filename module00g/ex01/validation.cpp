#include "validation.hpp"

bool validateFields(const contact_t &contact)
{
	if (contact.firstName.empty() || contact.lastName.empty() ||
		contact.nickname.empty() || contact.phoneNumber.empty() ||
		contact.darkestSecret.empty())
	{
		std::cerr << "\033[31mError: all fields must be filled!\033[0m" << std::endl;
		return false;
	}
	if (!validateName(contact))
	{
		std::cerr << "\033[31mError: first name and last name must contain only letters.\033[0m" << std::endl;
		return false;
	}
	if (!validatePhoneNumber(contact.phoneNumber))
	{
		std::cerr << "\033[31mError: phone number must contain only digits (and '+' at the beginning).\033[0m" << std::endl;
		return false;
	}
	return true;
}

bool validatePhoneNumber(const std::string &phoneNumber)
{
	if (phoneNumber[0] == '+')
		return phoneNumber.length() > 1 && isAllNDigits(phoneNumber, 1);
	return isAllNDigits(phoneNumber);
}

bool validateName(const contact_t &contact)
{
	return isAllAlpha(contact.firstName) && isAllAlpha(contact.lastName);
}

bool isAllAlpha(const std::string &s)
{
	if (s.empty())
		return false;

	for (size_t i = 0; i < s.size(); i++)
	{
		char c = static_cast<unsigned char>(s[i]);
		if (!std::isalpha(c) && c != ' ')
			return false;
	}
	return true;
}

bool isAllNDigits(const std::string &s, size_t i)
{
	while (i < s.size())
	{
		if (!std::isdigit(static_cast<unsigned char>(s[i])))
			return false;
		i++;
	}
	return !s.empty();
}
