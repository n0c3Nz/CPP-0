#include "phonebook.hpp"

Contact::Contact(std::string _name, std::string _lastname, std::string _nickname, int _tlf, std::string _dark_secret)
{
	tlf = _tlf;
	name = _name;
	lastname = _lastname;
	nickname = _nickname;
	dark_secret = _dark_secret;
}

Contact::~Contact()
{
}