
#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <iostream>
#include <iomanip>

class Contact
{
private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkSecret;

public:
	void setInfos(std::string infos[5]);
	void getInfos(std::string contact[5]) const;
};

Contact createContact();
#endif