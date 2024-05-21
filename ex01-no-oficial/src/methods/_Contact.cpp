#include "phonebook.hpp"

std::string Contact::get_name(){
	return (name);
}

void Contact::set_name(std::string _name){
	name.assign(_name);
}

std::string Contact::get_last_name(){
	return (lastname);
}

void	Contact::set_last_name(std::string _lastname){
	lastname.assign(_lastname);
}

std::string Contact::get_nick_name(){
	return (nickname);
}

void	Contact::set_nick_name(std::string _nickname){
	nickname.assign(_nickname);
}

void	Contact::set_tlf(int _tlf){
	tlf = _tlf;
}

int Contact::get_tlf(){
	return (tlf);
}

std::string Contact::get_dark_secret(){
	return (dark_secret);
}

void	Contact::set_dark_secret(std::string _dark_secret){
	dark_secret.assign(_dark_secret);
}
