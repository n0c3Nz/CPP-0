#include "phonebook.hpp"

int msg_and_continue(const char *_str)
{
	std::cout << std::endl << "Error: " << _str << std::endl;
	std::cout << std::endl << "Pulsa ENTER para volver al menú" << std::endl;
	std::cin.clear();
	std::getchar();
	return EXIT_FAILURE;
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
		try{
			long long number = custom_stoll(_data);
			if (number < INT_MIN || number > INT_MAX) {
				std::cout << std::endl << "Error: Número demasiado largo." << std::endl;
				contact->set_name("Add");
				return EXIT_FAILURE;
			}
			else{
				int selected = static_cast<int>(number);
				contact->set_tlf(selected);
			}
		} catch (std::invalid_argument& e) {
			std::cout << std::endl << "Error: Solo se permiten números." << std::endl;
			return EXIT_FAILURE;
		}
	}
	else if (_var2fill.compare("dark_secret") == 0)
		contact->set_dark_secret(_data);
	return (EXIT_SUCCESS);
}
