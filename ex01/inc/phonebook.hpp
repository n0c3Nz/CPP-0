#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include <iostream> 
#include <iomanip>
#include <cstdlib>
#include <cstdio>
//Clase


class Contact{
	private://Atributos que son solo accesibles desde la clase
		std::string		name;
		std::string		lastname;
		std::string		nickname;
		int				tlf;
		std::string		dark_secret;
	public://Member functions, funciones que pueden acceder a los atributos privates
		Contact(std::string _name, std::string _lastname, std::string _nickname, int _tlf, std::string _dark_secret);//Método constructor
		std::string     get_name();
		void			set_name(std::string);
		std::string     get_last_name();
		void			set_last_name(std::string);
		std::string     get_nick_name();
		void	     	set_nick_name(std::string);
		int				get_tlf();
		void			set_tlf(int);
		std::string		get_dark_secret();
		void	     	set_dark_secret(std::string);
};

class PhoneBook{
	private:
		Contact	*contact[7];

	public:
		PhoneBook(Contact _contact);
		void	add();
		void	search(std::string);
		void	exit();
};

void	print_header(void);
void	print_data(std::string _data);
void	print_contact(Contact _contact);
/*nuevas*/
int		do_questions(Contact *contact, std::string _var2fill);
int		do_all_questions(Contact *contact);
int		add_data(Contact *contact, std::string _data, std::string _var2fill);
bool	is_digits(const std::string &str);
#endif