#include "phonebook.hpp"

int main(void)
{
	Contact Add("Add", "Add", "Add", 0, "none");
	PhoneBook phonebook(Add);
	std::string name;

	while (1)
	{
		system("clear");
		if (std::cin.eof()) {
		// CTRL+D fue presionado
			std::cout << std::endl << "CTRL+D fue presionado.";
			std::cin.clear();
			phonebook.exit();
			break ;
    	}
		std::cout << std::endl << "Bienvenido a tu agenda personal" << std::endl;
		std::cout << std::endl << "-------------------------------" << std::endl;
		std::cout << std::endl << "1. Añadir contacto" << std::endl;
		std::cout << "2. Buscar contacto" << std::endl;
		std::cout << "3. Salir" << std::endl;
		int selected;
		std::cout << std::endl << "Selecciona una opción: ";
		std::cin >> selected;
		std::cin.clear();
		std::cin.ignore();
		std::string name;
		switch (selected)
		{
		case 1:
			phonebook.add();
			break ;
		case 2:
			std::cout << "Introduce el nombre del contacto: ";
			std::getline(std::cin, name);
			std::cin.clear();
			phonebook.search(name);
			break ;
		case 3:
			phonebook.exit();
			break;
		default:
			std::cout << "Opción no válida" << std::endl;
		}
	}
	return 0;
}
