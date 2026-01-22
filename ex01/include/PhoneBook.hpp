#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iomanip>

# include "Contact.hpp"
# include "colors.hpp"

# define MAX_CONTACTS 8
# define COLUMN_WIDTH 10

class PhoneBook
{
	public:
		void addContact(const Contact& contact);
		void showList();

	private:
		int contact_idx_ = 0;
		int contact_count_ = 0;
		Contact contacts_[MAX_CONTACTS];

		void displayContact();
};

#endif
