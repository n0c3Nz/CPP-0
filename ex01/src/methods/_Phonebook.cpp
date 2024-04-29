#include "phonebook.hpp"

void PhoneBook::exit()
{
	std::cout << std::endl << "Saliendo del programa." << std::endl;
	std::exit(0);
}

void PhoneBook::search(std::string _name){
	int			i = 0;
	int			found = 0;
	int			selected;
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
		std::cout << std::endl << "Pulsa ENTER para volver al menú" << std::endl;
		std::cin.clear();
		std::getchar();
		return ;
	}
	if (_name.length() == 0){
		std::cout << std::endl << "Error: Nombre vacío." << std::endl;
		std::cout << std::endl << "Pulsa ENTER para volver al menú" << std::endl;
		std::cin.clear();
		std::getchar();
		return ;
	}
	while (i < 8)
	{
		if (contact[i]->get_name().compare(_name) == 0)
			found++;
		i++;
	}
	if (found == 0)
	{
		std::cout << std::endl << "No se encontró a ningún contacto con ese nombre." << std::endl;
		std::cout << std::endl << "Pulsa ENTER para volver al menú" << std::endl;
		std::cin.clear();
		std::getchar();
		return ;
	}
	else
		print_header();
	i = 0;
	int j = 1;
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
	std::cout << std::endl << "Selecciona un contacto [1 - " << j - 1 << "]: ";
	std::getline(std::cin, input);
	if (input.length() == 0 || !is_digits(input))
	{
		std::cout << std::endl << "Error: Campo vacío." << std::endl;
		std::cout << std::endl << "Pulsa ENTER para volver al menú" << std::endl;
		std::cin.clear();
		std::getchar();
		return ;
	}
	selected = std::stoi(input);
	std::cin.clear();
	if (selected < 1 || selected > 8 || selected > j - 1)
	{
		std::cout << std::endl << "Error: Índice no válido." << std::endl;
		std::cout << std::endl << "Pulsa ENTER para volver al menú" << std::endl;
		std::cin.clear();
		std::getchar();
		return ;
	}
	i = 0;
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
	std::cout << std::endl << "Pulsa ENTER para volver al menú" << std::endl;
	std::cin.clear();
	std::getchar();
}

void PhoneBook::add()
{
	static int		nr_2_replace;
	int i = 0;
	while ((i < 8) && contact[i]->get_name() != "Add")
		i++;
	if (i == 8)
	{
		std::cout << std::endl << "Error: No hay espacio para añadir más contactos." << std::endl;
		if (do_all_questions(contact[nr_2_replace]))
			return ;
		nr_2_replace++;
		if (nr_2_replace == 8)
			nr_2_replace = 0;
		return ;
	}
	else
		do_all_questions(contact[i]);
	std::cout << std::endl << "Pulsa ENTER para volver al menú" << std::endl;
	std::cin.clear();
	std::getchar();
}