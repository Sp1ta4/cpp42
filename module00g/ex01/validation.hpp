#ifndef VALIDATION_HPP
# define VALIDATION_HPP

# include <string>
# include <iostream>
# include "Contact.hpp"

bool validateFields(const contact_t &contact);
bool validatePhoneNumber(const std::string &phoneNumber);
bool validateName(const contact_t &contact);
bool isAllAlpha(const std::string &s);
bool isAllNDigits(const std::string &s, size_t i = 0);

#endif
