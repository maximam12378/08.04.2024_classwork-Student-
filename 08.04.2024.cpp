#include <iostream>
#include <locale.h>
#include "Student.h"
using namespace std;




int main()
{
	
	Student Maksim;
	//Maksim.create_Student(); // метод вводу усіх даних через консоль
	//Maksim.show_student(); //метод друквання студенту
	
	char name[255] = "Maksym", surname[255] = "Batashan", po_batkovi[255] = "Evhenivna";
	Maksim.set_nm_srnm_pobat(name, surname, po_batkovi);
	char city[255] = "Odesa", country[255] = "Ukraine";
	Maksim.set_home(city, country);

	char edu_name[255] = "ITSTEP";
	Maksim.set_edu_nm(edu_name);

	Maksim.set_edu_place(city, country);
	
	Maksim.set_birthd(29, 11, 2006);

	char number[18] = "+380 63 942 0220";
	Maksim.set_phone_num(number);
	
	char gr_number[18] = "PV311";
	Maksim.set_group_num(gr_number);
	
	Maksim.show_student();


	
	Student Diana;
	char name2[255] = "Diana", surname2[255] = "Batashan", po_batkovi2[255] = "Evhenivna";
	Diana.set_nm_srnm_pobat(name2, surname2, po_batkovi2);

	char city2[255] = "Odesa", country2[255] = "Ukraine";
	Diana.set_home(city2, country2);

	char edu_name2[255] = "Middle School";
	Diana.set_edu_nm(edu_name2);

	Diana.set_edu_place(city2, country2);

	Diana.set_birthd(20, 12, 2010);

	char number2[18] = "+380 73 768 2280";
	Diana.set_phone_num(number2);

	char gr_number2[18] = "8-D";
	Diana.set_group_num(gr_number2);

	Diana.show_student();
}
