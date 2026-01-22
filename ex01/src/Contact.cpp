#include "Contact.hpp"

const std::string& Contact::getFirstName()
{
	return first_name_;
}
const std::string& Contact::getLastName()
{
	return last_name_;
}
const std::string& Contact::getNickname()
{
	return nickname_;
}
const std::string& Contact::getPhoneNumber()
{
	return phone_number_;
}
const std::string& Contact::getDarkestSecret()
{
	return darkest_secret_;
}

/**
 * @return `false` if any attribute is empty, `true` otherwise.
 */
bool Contact::isComplete() const
{
	if (first_name_.empty()
		|| last_name_.empty()
		|| nickname_.empty()
		|| phone_number_.empty()
		|| darkest_secret_.empty())
	{
		return false;
	}
	return true;
}

void Contact::readInput(const std::string& prompt, std::string& buffer)
{
	if (std::cin.eof())
	{
		return ;
	}
	forever
	{
		std::cout << prompt << ": ";
		std::getline(std::cin, buffer);
		if (buffer.empty() == false || std::cin.eof())
		{
			break ;
		}
		else if (buffer.empty() == true)
		{
			std::cout << prompt << " cannot be empty\n";
		}
	}
}

/**
 * @return `true` if all characters are a digit, `false` otherwise.
 */
bool Contact::onlyDigit(const std::string& buffer) const
{
	for (unsigned char chr : buffer)
	{
		if (std::isdigit(chr) == false)
		{
			std::cout << "May only contain digits\n";
			return (false);
		}
	}
	return (true);
}

/**
 * @return `true` if all characters are an alphabetical character, `false` otherwise.
 */
bool Contact::onlyAlpha(const std::string& buffer) const
{
	for (unsigned char chr : buffer)
	{
		if (std::isalpha(chr) == false)
		{
			std::cout << "May only contain alphabetical characters\n";
			return (false);
		}
	}
	return (true);
}

bool Contact::addContact()
{
	forever
	{
		readInput("First name", first_name_);
		if (onlyAlpha(first_name_) == true)
		{
			break ;
		}
	}
	forever
	{
		readInput("Last name", last_name_);
		if (onlyAlpha(last_name_) == true)
		{
			break ;
		}
	}
	readInput("Nickname", nickname_);
	forever
	{
		readInput("Phone Number", phone_number_);
		if (onlyDigit(phone_number_) == true)
		{
			break ;
		}
	}
	readInput("Darkest Secret", darkest_secret_);
	return (isComplete());
}
