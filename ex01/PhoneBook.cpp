
#include "PhoneBook.hpp"

bool	isnum(char c)
{
	if (c < '0' || c > '9')
		return false;
	return true;
}
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
Contact PhoneBook::getContact(const std::string &sindex)const
{
	int index;

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
void contactList()
{
	std::cout<<"index | ";
	std::cout<<"first name | ";
	std::cout<<"last name | ";
	std::cout<<"nickname |"<<std::endl;

}

int	main()
{
	PhoneBook book;
	std::string cmd;
	std::string	sIndex;
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
			//contactList();
			while (true)
			{
				std::cout << "Enter your contact index (0 to " << book.getNbContacts() - 1 << "): ";
				if (!std::getline(std::cin, sIndex) || sIndex.length() != 1 || !isnum(sIndex[0]))
				{
					std::cerr << "Invalid input. Try again." << std::endl;
					continue;
				}
				break;
			}
			newContact = book.getContact(sIndex);
			newContact.getInfos(contactDisplay);
			for (int i = 0; i < 5; i++)
			{
				std::cout<<contactDisplay[i]<<std::endl;
			}
		}

	}
}