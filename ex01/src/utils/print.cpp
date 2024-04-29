#include "phonebook.hpp"

void print_data(std::string _data)
{
	if (_data.length() > 10)
		std::cout << std::setw(9) << _data.substr(0, 8) << ".";
	else
		std::cout << std::setw(10) << _data;
	std::cout << "|";
}

void print_header(void)
{
	std::cout << "|" << std::setw(10) << std::right << "Index" << "|";
	std::cout << std::setw(10) << std::right << "Name" << "|";
	std::cout << std::setw(10) << std::right << "Last Name" << "|";
	std::cout << std::setw(10) << std::right << "Nickname" << "|";
	std::cout << std::endl;
}
void	print_contact(Contact _contact)
{
	if (_contact.get_name().compare("Add") == 0)
		return ;
	std::cout << std::setw(10) << std::right << "Name:" << std::setw(15) << std::right << _contact.get_name() << std::endl;
	std::cout << std::setw(10) << std::right << "Last Name:" << std::setw(15) << std::right << _contact.get_last_name() << std::endl;
	std::cout << std::setw(10) << std::right << "Nickname:" << std::setw(15) << std::right << _contact.get_nick_name() << std::endl;
	std::cout << std::setw(10) << std::right << "Tlf number:" << std::setw(14) << std::right << _contact.get_tlf() << std::endl;
	std::cout << std::setw(10) << std::right << "Dark Secret: " << std::setw(12) << std::right << _contact.get_dark_secret() << std::endl;
}