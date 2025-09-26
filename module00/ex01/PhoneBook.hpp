#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <string.h>
# include <iomanip>
# include <limits.h>
# include <sstream>
# include "validation.hpp"
# include "main.hpp"

class PhoneBook
{
	private:
		Contact			_contacts[8];
		unsigned int	_newContactIndex;
		bool			_isFull;
		size_t			_size;
		void 			_printContactsList(void);
		void			_printContactInfo(Contact contact);

	public : PhoneBook(void);
		PhoneBook(const PhoneBook &other);
		PhoneBook &operator=(const PhoneBook &other);
		~PhoneBook(void);
		size_t size(void) const;
		void addContact(void);
		void searchContact(void);
};

#endif