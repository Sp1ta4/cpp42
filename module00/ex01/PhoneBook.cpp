#include "PhoneBook.hpp"

static void printHeader();
static void printContact(int index, const std::string &first, const std::string &last, const std::string &nick);
static std::string formatField(const std::string &s);
static int getCorrectIndexInput(std::string &input, size_t size);

	PhoneBook::PhoneBook(void) : _newContactIndex(0), _isFull(false), _size(0)
{
}

PhoneBook::PhoneBook(const PhoneBook &other)
{
	*this = other;
}

PhoneBook &PhoneBook::operator=(const PhoneBook &other)
{
	if (this != &other)
	{
		this->_newContactIndex = other._newContactIndex;
		this->_isFull = other._isFull;
		for (int i = 0; i < 8; i++)
		{
			this->_contacts[i] = other._contacts[i];
		}
	}
	return *this;
}

PhoneBook::~PhoneBook(void) {}

void PhoneBook::addContact(void)
{
	contact_t newContact;

	std::cout << "Write your firstname:" << std::endl;
	std::getline(std::cin >> std::ws, newContact.firstName);
	std::cout << "Write your lastname:" << std::endl;
	std::getline(std::cin >> std::ws, newContact.lastName);
	std::cout << "Write your nickname:" << std::endl;
	std::getline(std::cin >> std::ws, newContact.nickname);
	std::cout << "Write your darkestSecret:" << std::endl;
	std::getline(std::cin >> std::ws, newContact.darkestSecret);
	std::cout << "Write your phoneNumber:" << std::endl;
	std::getline(std::cin >> std::ws, newContact.phoneNumber);

	if (!validateFields(newContact))
		return;

	this->_contacts[this->_newContactIndex] = Contact(
		newContact.firstName,
		newContact.lastName,
		newContact.nickname,
		newContact.darkestSecret,
		newContact.phoneNumber);

	this->_newContactIndex = (this->_newContactIndex + 1) % 8;
	if (!this->_isFull)
	{
		this->_size++;
		if (this->_size == 8)
			this->_isFull = true;
	}
	std::cout << "\033[32mContact successfully added.\033[0m" << std::endl;
}

void PhoneBook::searchContact(void)
{
	std::string line;

	if (this->_size == 0)
	{
		std::cout << "\033[33mNo contacts in your phonebook.\033[0m" << std::endl;
		return;
	}
	this->_printContactsList();
	while (true)
	{
		if (isEOF())
			break;
		std::cout << "Input your chosen contact index:" << std::endl;
		std::getline(std::cin >> std::ws, line);

		int i = getCorrectIndexInput(line, this->size());

		if (i == -1)
		{
			std::cout << "\033[31mInvalid input or contact with this index is not found!\n\033[0mPlease enter a correct index." << std::endl;
			continue;
		}
		this->_printContactInfo(this->_contacts[i]);
		break;
	}
}

void PhoneBook::_printContactsList(void)
{
	printHeader();
	for (size_t i = 0; i < this->_size; i++)
	{
		printContact(i, this->_contacts[i].getFirstName(), this->_contacts[i].getLastName(), this->_contacts[i].getNickname());
	}
}

size_t PhoneBook::size(void) const
{
	return (this->_size);
}

void PhoneBook::_printContactInfo(Contact contact)
{
	std::cout << "Firstname: " << contact.getFirstName() << std::endl;
	std::cout << "Lastname: " << contact.getLastName() << std::endl;
	std::cout << "Nickname: " << contact.getNickname() << std::endl;
	std::cout << "Phone number: " << contact.getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << contact.getDarkestSecret() << std::endl;
}

static int getCorrectIndexInput(std::string &input, size_t size)
{
	if (input.size() == 1 && std::isdigit(input[0]))
	{
		int i = input[0] - '0';
		if (i >= 0 && i < static_cast<int>(size))
			return (i);
	}
	return (-1);
}

static void printHeader()
{
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|"
			  << std::setw(10) << "index"
			  << "|" << std::setw(10) << "firstname"
			  << "|" << std::setw(10) << "lastname"
			  << "|" << std::setw(10) << "nickname"
			  << "|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
}

static void printContact(int index, const std::string &first, const std::string &last, const std::string &nick)
{
	std::cout << "|"
			  << std::setw(10) << index
			  << "|" << std::setw(10) << formatField(first)
			  << "|" << std::setw(10) << formatField(last)
			  << "|" << std::setw(10) << formatField(nick)
			  << "|" << std::endl;
}

static std::string formatField(const std::string &s)
{
	if (s.size() > 10)
		return (s.substr(0, 9) + ".");
	return (s);
}
