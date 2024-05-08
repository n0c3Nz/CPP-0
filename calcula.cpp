#include <iostream>

//Un búcle infinito que me pide un número y el % de descuento, me da el resultado y me pide el siguiente.
int main(void)
{
	float precio, descuento, precioFinal;
	while (true)
	{
		system("clear");
		std::cout << "Introduce el precio: ";
		std::cin >> precio;
		if (std::cin.fail() || precio < 0) {
			std::cout << "Error: Precio inválido." << std::endl;
			std::cin.clear();
			std::cin.ignore();
			break;
		}
		std::cout << "Introduce el descuento: ";
		std::cin >> descuento;
		if (std::cin.fail() || descuento < 0 || descuento > 100) {
			std::cout << "Error: Descuento inválido." << std::endl;
			std::cin.clear();
			std::cin.ignore();
			break;
		}

		precioFinal = precio - precio * descuento / 100;
		std::cout << "El precio final es: " << precioFinal << " €" << std::endl;
		std::cout << "Pulsa una tecla para continuar..." << std::endl;//Para que no se cierre la ventana
		std::cin.ignore();
		std::cin.get();
	}
	return 0;
}
