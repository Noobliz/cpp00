/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:52:07 by lguiet            #+#    #+#             */
/*   Updated: 2025/05/09 15:03:44 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

bool isnum(char c)
{
	if (c < '0' || c > '9')
		return false;
	return true;
}
PhoneBook::PhoneBook() : nbContacts(0), indexToPlace(0)
{
	std::cout << "hello" << std::endl;
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
Contact PhoneBook::getContact(const std::string &sindex) const
{
	int index;

	index = sindex[0] - '0';
	if (index < 0 || index >= nbContacts)
	{
		std::cerr << "index should be >= 0 and < amount of contacts" << std::endl;
		return Contact();
	}
	return contacts[index];
}

int PhoneBook::getNbContacts() const
{
	return nbContacts;
}

PhoneBook::~PhoneBook()
{
	std::cout << "ciao" << std::endl;
}
void PhoneBook::contactList() const
{
	std::cout << std::setw(10) << "index | ";
	std::cout << std::setw(10) << "first name | ";
	std::cout << std::setw(10) << "last name | ";
	std::cout << std::setw(10) << "nickname |" << std::endl;
	for (int i = 0; i < nbContacts; i++)
	{
		// setw(N) <<< qui vient de iomanip, ca sert a forcer une taille de N
		//  substr pour ce qui est sup a 10
		std::cout << std::setw(10) << i;
		std::string autrement[5];
		contacts[i].getInfos(autrement);

		std::cout << std::setw(10) << autrement[0];
		std::cout << std::setw(10) << autrement[1];
		std::cout << std::setw(10) << autrement[2] << std::endl;
	}
}

int main()
{
	PhoneBook book;
	std::string cmd;
	std::string sIndex;
	Contact newContact;
	std::string contactDisplay[5];
	std::cout << "Welcome to your phonebook" << std::endl;
	while (cmd != "EXIT")
	{
		std::cout << "enter ADD, SEARCH or EXIT" << std::endl;
		std::cout << ">> ";
		if (!std::getline(std::cin, cmd))
		{
			std::cerr << "Error reading stdin." << std::endl;
			return 1;
		}
		if (cmd == "ADD")
		{
			newContact = createContact();
			book.addContact(newContact);
		}
		if (cmd == "SEARCH")
		{
			book.contactList();
			while (true)
			{
				std::cout << "Enter your contact index (0 to " << book.getNbContacts() - 1 << "): ";
				if (!std::getline(std::cin, sIndex))
				{
					std::cout << std::endl;
					std::cerr << "getline error" << std::endl;
					return 1;
				}
				if (sIndex.length() != 1 || !isnum(sIndex[0]))
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
				std::cout << contactDisplay[i] << std::endl;
			}
		}
	}
}