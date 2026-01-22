#include "PhoneBook.hpp"

std::string truncate(const std::string& str, size_t width)
{
	if (str.length() > width)
	{
		return str.substr(0, width - 1) + ".";
	}
	return str;
}

void PhoneBook::displayContact()
{
	std::string input;
	int			digit;

	forever
	{
		getline(std::cin, input);
		if (std::cin.eof())
		{
			return ;
		}
		else if (input.length() != 1 || input.find_first_not_of("12345678") != input.npos)
		{
			std::cout << "Pick a digit between 1 and 8\n";
			continue;
		}
		digit = std::stoi(input);
		if (digit > contact_count_)
		{
			std::cout << "Contact does not exist\n";
		}
		else
		{
			break ;
		}
	}
	std::cout << "\nFirst name: " << contacts_[digit - 1].getFirstName() << "\n";
	std::cout << "Last name: " << contacts_[digit - 1].getLastName() << "\n";
	std::cout << "Nickname: " << contacts_[digit - 1].getNickname() << "\n";
	std::cout << "Phone Number: " << contacts_[digit - 1].getPhoneNumber() << "\n";
	std::cout << "Darkest Secret: " << contacts_[digit - 1].getDarkestSecret() << "\n";
}

void PhoneBook::showList()
{
	if (contact_count_ == 0)
	{
		std::cout << RED << "No contacts to display\n\n" << RESET;
		return ;
	}
	std::cout << CYAN;
	std::cout << std::setw(COLUMN_WIDTH) << "index" << "|";
	std::cout << std::setw(COLUMN_WIDTH) << "first name" << "|";
	std::cout << std::setw(COLUMN_WIDTH) << "last name"<< "|";
	std::cout << std::setw(COLUMN_WIDTH) << "nickname"<< "|\n";
	std::cout << RESET;
	for (int i = 0; i < contact_count_; i++)
	{
		std::cout << std::setw(COLUMN_WIDTH) << i + 1 << "|";
		std::cout << std::setw(COLUMN_WIDTH) << truncate(contacts_[i].getFirstName(), COLUMN_WIDTH) << "|";
		std::cout << std::setw(COLUMN_WIDTH) << truncate(contacts_[i].getLastName(), COLUMN_WIDTH) << "|";
		std::cout << std::setw(COLUMN_WIDTH) << truncate(contacts_[i].getNickname(), COLUMN_WIDTH) << "|\n";
	}
	displayContact();
}

void PhoneBook::addContact(const Contact& contact)
{
	contacts_[contact_idx_] = contact;
	contact_idx_ = (contact_idx_ + 1) % MAX_CONTACTS;
	if (contact_count_ < MAX_CONTACTS)
	{
		contact_count_ += 1;
	}
}
