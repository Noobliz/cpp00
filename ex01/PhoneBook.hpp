
#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"

class	PhoneBook
{
	private:
	Contact contacts[8];
	int	nbContacts;
	int	indexToPlace;

	public:
	PhoneBook();

	void	addContact(const Contact &newContact);
	Contact	getContact(const std::string &index)const;
	int	getNbContacts()const;
	//void PhoneBook::contactList();
	~PhoneBook();
};
#endif