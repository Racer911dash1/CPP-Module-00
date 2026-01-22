#include "PhoneBook.hpp"

void printbook()
{
	std::ios init(NULL);
	static size_t pagecount = 1;

	init.copyfmt(std::cout);
	std::cout	<< "    ___________________   ___________________\n"
				<< ".-/|      OPTIONS      \\ /   DESCRIPTIONS    |\\-.\n"
				<< "||||                    |                    ||||\n"
				<< "||||                    |                    ||||\n"
				<< "||||         ADD        |   Add a contact    ||||\n"
				<< "||||                    |                    ||||\n"
				<< "||||                    |                    ||||\n"
				<< "||||       SEARCH       |  Display contacts  ||||\n"
				<< "||||                    |                    ||||\n"
				<< "||||                    |                    ||||\n"
				<< "||||        EXIT        |    Quit program    ||||\n"
				<< "||||                    |                    ||||\n"
				<< "||||"
				<< std::left << std::setfill('_') << std::setw(20) << pagecount << std::right
				<< "|"
				<< std::setfill('_') << std::setw(20) << pagecount + 1
				<< "||||\n"
				<< "||/====================\\|/====================\\||\n"
				<< "`---------------------~___~--------------------''\n\n";
	pagecount += 2;
	std::cout.copyfmt(init);
}

int	main()
{
	std::string input;
	Contact contact;
	PhoneBook phonebook;

	forever
	{
		if (std::cin.eof())
		{
			break ;
		}
		printbook();
		std::getline(std::cin, input);
		if (input == "EXIT" || std::cin.eof())
		{
			break ;
		}
		std::cout << "\n";
		if (input == "ADD")
		{
			if (contact.addContact() == true)
			{
				phonebook.addContact(contact);
				std::cout << GREEN << "\nContact added\n\n" << RESET;
			}
		}
		else if (input == "SEARCH")
		{
			phonebook.showList();
		}
		else
		{
			std::cout << "Invalid input, please try again with the following options\n\n";
		}
	}
}















