#include "phonebook.hpp"

PhoneBook::PhoneBook(Contact _contact)
{
	for (int i = 0; i < 8; i++) {
		contact[i] = new Contact(_contact);
	}
}