#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

# include "defines.hpp"

class Contact
{
	public:
		const std::string& getFirstName();
		const std::string& getLastName();
		const std::string& getNickname();
		const std::string& getPhoneNumber();
		const std::string& getDarkestSecret();

		bool isComplete() const;
		bool addContact();

	private:
		std::string first_name_;
		std::string last_name_;
		std::string nickname_;
		std::string phone_number_;
		std::string darkest_secret_;

		void readInput(const std::string& prompt, std::string& buffer);
		bool onlyDigit(const std::string& buffer) const;
		bool onlyAlpha(const std::string& buffer) const;
};

#endif
