#include "phonebook.hpp"

bool is_digits(const std::string &str)
{
    return str.find_first_not_of("0123456789") == std::string::npos;
}

int do_questions(Contact *contact, std::string _var2fill)
{
	std::string		_data;
	std::cout << "Introduce el " << _var2fill << " del contacto: ";
	std::getline(std::cin, _data);
	return (add_data(contact, _data, _var2fill));
}
int do_all_questions(Contact *contact)
{
	if (do_questions(contact, "name"))
		return (EXIT_FAILURE);
	if (do_questions(contact, "lastname"))
		return (EXIT_FAILURE);
	if (do_questions(contact, "nickname"))
		return (EXIT_FAILURE);
	if (do_questions(contact, "tlf"))
		return (EXIT_FAILURE);
	if (do_questions(contact, "dark_secret"))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int add_data(Contact *contact, std::string _data, std::string _var2fill)
{
	if (_data.length() <= 0){
		std::cout << std::endl << "Error: Campo vacío." << std::endl;
		contact->set_name("Add");
		return(EXIT_FAILURE);
	}
	if (_var2fill.compare("name") == 0 )
		contact->set_name(_data);
	else if (_var2fill.compare("lastname") == 0)
		contact->set_last_name(_data);
	else if (_var2fill.compare("nickname") == 0)
		contact->set_nick_name(_data);
	else if (_var2fill.compare("tlf") == 0)
	{
		if (!is_digits(_data))
		{
			std::cout << std::endl << "Error: Solo se permiten números." << std::endl;
			contact->set_name("Add");
			return (EXIT_FAILURE);
		}
		contact->set_tlf(std::stoi((_data)));
	}
	else if (_var2fill.compare("dark_secret") == 0)
		contact->set_dark_secret(_data);
	return (EXIT_SUCCESS);
}
