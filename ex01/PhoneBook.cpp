
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : nbContacts(0), indexToPlace(0) {
	std::cout<<"hello"<<std::endl;
}

void PhoneBook::addContact(const Contact &newContact)
{
	contacts[indexToPlace] = newContact;
	if (indexToPlace < 7)
		indexToPlace++;
	else
		indexToPlace = 0;
	if (nbContacts < 8)
		nbContacts++;
}

Contact PhoneBook::getContact(std::string sindex)const
{
	int index;

	if (sindex.length() > 1 || !isalnum(sindex[0]))
	{
		std::cerr<<"index should be >= 0 and < amount of contacts"<<std::endl;
		return Contact();
	}
	index = sindex[0] - '0';
	if (index < 0 || index >= nbContacts)
	{
		std::cerr<<"index should be >= 0 and < amount of contacts"<<std::endl;
		return Contact();
	}
	return contacts[index];
}

int PhoneBook::getNbContacts()const
{
	return nbContacts;
}

PhoneBook::~PhoneBook()
{
	std::cout<<"ciao"<<std::endl;
}


int	main()
{
	PhoneBook book;
	std::string cmd;
	std::string	sindex;
	Contact	newContact;
	std::string contactDisplay[5];
	std::cout<<"Welcome to your phonebook"<<std::endl;
	while (cmd != "EXIT")
	{
		std::cout<<"enter ADD, SEARCH or EXIT"<<std::endl;
		std::cout<<">> ";
		if(!std::getline(std::cin, cmd))
		{
			std::cerr<<"Error reading stdin."<<std::endl;
			return 1;
		}
		if (cmd == "ADD")
		{
			newContact = createContact();
			book.addContact(newContact);
		}
		if (cmd == "SEARCH")
		{
			std::cout<<"enter your contact index (from 0 to 7): ";
			if(!std::getline(std::cin, sindex))
			{
				std::cerr<<"Error reading stdin."<<std::endl;
				return 1;
			}
			newContact = book.getContact(sindex);
			newContact.getInfos(contactDisplay);
			for (int i = 0; i < 5; i++)
			{
				std::cout<<contactDisplay[i]<<std::endl;
			}
		}

	}
}