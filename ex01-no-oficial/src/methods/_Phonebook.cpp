#include "phonebook.hpp"

void PhoneBook::exit()
{
	std::cout << std::endl << "Saliendo del programa." << std::endl;
	std::exit(0);
}

void PhoneBook::search(std::string _name){
	int			i = 0;
	int			found = 0;
	std::string	input;
	
	if (std::strcmp(_name.c_str(), "Add") == 0)
		return ;
	if (std::strcmp(_name.c_str(), "All") == 0)
	{
		if (contact[0]->get_name().compare("Add") == 0)
			return ;
		print_header();
		while (i < 8)
		{
			if (contact[i]->get_name().compare("Add") != 0)
			{
				std::cout << "|" << std::setw(10) << std::right;
				std::cout << i + 1 << "|";
				print_data(contact[i]->get_name());
				print_data(contact[i]->get_last_name());
				print_data(contact[i]->get_nick_name());
				std::cout << std::endl;
			}
			i++;
		}
	}
	if (_name.length() == 0){
		msg_and_continue("Nombre vacío.");
		return ;
	}
	int j = 1;
	i = 0;
	if (std::strcmp(_name.c_str(), "All") != 0)
	{
		while (i < 8)
		{
			if (contact[i]->get_name().compare(_name) == 0)
				found++;
			i++;
		}
		if (found == 0)
		{
			msg_and_continue("No se encontró a ningún contacto con ese nombre.");
			return ;
		}
		else
			print_header();
		i = 0;
		while (i < 8)
		{
			if (contact[i]->get_name().compare(_name) == 0)
			{
				std::cout << "|" << std::setw(10) << std::right;
				std::cout << j << "|";
				print_data(contact[i]->get_name());
				print_data(contact[i]->get_last_name());
				print_data(contact[i]->get_nick_name());
				std::cout << std::endl;
				j++;
			}
			i++;
		}
	}
	else
	{
		while (i < 8)
		{
			if (contact[i]->get_name().compare("Add") != 0)
				j++;
			i++;
		}
	}
	try {
		std::cout << std::endl << "Selecciona un contacto [1 - " << j - 1 << "]: ";
		std::getline(std::cin, input);
		long long number = custom_stoll(input);
		if (number < INT_MIN || number > INT_MAX) {
			msg_and_continue("Número demasiado largo.");
			return ;
		}
		else {
			int selected = static_cast<int>(number);
			if (selected < 1 || selected > 8 || selected > j - 1)
			{
				msg_and_continue("Número fuera de rango.");
				return ;
			}
			i = 0;
			if (std::strcmp(_name.c_str(), "All") != 0)
			{
				while (i < 8)
				{
					if (contact[i]->get_name().compare(_name) == 0 && selected - 1 == 0){
						print_contact(*contact[i]);
						break ;
					}
					else if (contact[i]->get_name().compare(_name) == 0 && selected - 1 > 0)
						selected--;
					i++;
				}
			}
			else
				print_contact(*contact[selected - 1]);
			std::cout << std::endl << "Pulsa ENTER para volver al menú" << std::endl;
			std::cin.clear();
			std::getchar();
		}
	} catch (std::invalid_argument& e) {
		msg_and_continue("Argumento inválido.");
		return ;
	}
}

void PhoneBook::add()
{
	static int		nr_2_replace;
	int i = 0;
	while ((i < 8) && contact[i]->get_name() != "Add")// Busca la primera posición vacía
		i++;
	if (i == 8)// Si la agenda está llena
	{
		if (do_all_questions(contact[nr_2_replace]))
			return ;
		nr_2_replace++;
		if (nr_2_replace == 8)// Si se ha llegado al final de la agenda volvemos al inicio
			nr_2_replace = 0;
		return ;
	}
	else
		do_all_questions(contact[i]);
	std::cout << std::endl << "Pulsa ENTER para volver al menú" << std::endl;
	std::cin.clear();
	std::getchar();
}