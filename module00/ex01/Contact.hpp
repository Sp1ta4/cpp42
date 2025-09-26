#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

typedef struct
{
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;
} contact_t;

class Contact {
	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickname;
		std::string _darkestSecret;
		std::string _phoneNumber;

	public:
		Contact(void);
		Contact(std::string firstName, std::string lastName,
				std::string nickname, std::string phoneNumber,
				std::string darkestSecret);
		Contact(const Contact &other);
		Contact &operator=(const Contact &other);
		~Contact(void);

		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getNickname() const;
		std::string getDarkestSecret() const;
		std::string getPhoneNumber() const;

		void setFirstName(const std::string &firstName);
		void setLastName(const std::string &lastName);
		void setNickname(const std::string &nickname);
		void setDarkestSecret(const std::string &darkestSecret);
		void setPhoneNumber(const std::string &phoneNumber);
};

#endif