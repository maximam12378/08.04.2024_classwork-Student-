#pragma once
#include <iostream>
#include <locale.h>
using namespace std;

//Я додатково створив окремий клас для додаткового параметру "Id студента", мені здалося шо це не буде зайвим в цій программі😁😁😁

class Id
{
	int stud_counter;
public:
	Id()									//Коли запускається програма, я одразу створюю об'єкт цього класу(нижче⤵) || Дефолтний контруктор в свою черго призначає змінній лічільника значення [0]
	{
		stud_counter = 0;
	}
	int create_stud_counter()				//Кожен раз коли створюється новий студет цей метод додає [1] до лічильника, та повертає його значення  || Далі у класі студенту це унікальне значення призначається як ID студента
	{
		stud_counter += 1;
		return stud_counter;
	}
};
Id id;//--------ОБ'ЄКТ ТУТ!!!------------------ОБ'ЄКТ ТУТ!!!------------------ОБ'ЄКТ ТУТ!!!------------------ОБ'ЄКТ ТУТ!!!-----------------------------------


//class Change_info_concretely
//{
//public:
//
//	void change_(char* destination_, char* surname)
//	{
//		strcpy_s(destination_, sizeof(destination_), surname);
//	}
//};

class Change_info_concretely
{
public:

};

class Student
{

	const char Empty[6] = "Empty";



	int stud_id; // айді студента(порядковий номер)
	int day, month, year; //дата народження

	char stud_nm[255], stud_srnm[255], stud_po_batkovi[255]; //ПІБ студента      // В англійській мові нема відповідника до того що ми кличемо "По батькові", і в цілому не використовується. Тому я гадаю що можна назвати цю змінну таким чином.
	char stud_city[50], stud_country[50];
	char edu_nm[255], edu_city[50], edu_country[50]; // Назва навчального закладу та розташування ліцею(місто,країна)
	char phone_num[50]; // номер телефону                
	char group_num[18];
	void change_info(char* destination_, char* name)
	{
		strcpy_s(destination_, sizeof(destination_), name);
	}
	
public:
	//_________________________Конструктори_________________________
	Student() // Дефолт конструктор
	{
		stud_id = id.create_stud_counter();

		strcpy_s(this->stud_srnm, sizeof(this->stud_srnm), this->Empty);
		strcpy_s(this->stud_nm, sizeof(this->stud_nm), this->Empty);
		strcpy_s(this->stud_po_batkovi, sizeof(this->stud_po_batkovi), this->Empty);
	}

	Student(char* name, char* surname, char* po_batkovi)
	{
		stud_id = id.create_stud_counter();
		strcpy_s(this->stud_srnm, sizeof(this->stud_srnm), surname);
		strcpy_s(this->stud_nm, sizeof(this->stud_nm), name);
		strcpy_s(this->stud_po_batkovi, sizeof(this->stud_po_batkovi), po_batkovi);
	}
	//______________________________________________________________

	void show_student()
	{
		cout << endl;
		cout << "ID:" << this->stud_id << endl << "ПІБ: \033[4m" << this->stud_srnm << " " << this->stud_nm << " " << this->stud_po_batkovi << "\033[0m" << endl;
		cout << "Birthday: \033[4m" << this->day << "." << this->month << "." << this->year << "\033[0m" << endl;
		cout << "Home: \033[4m" << this->stud_city << "\033[0m, \033[4m" << this->stud_country << "\033[0m" << endl;
		cout << "Educational establishment: \033[4m" << this->edu_nm << "\033[0m, \033[4m" << this->stud_city << "\033[0m, \033[4m" << this->stud_country << "\033[0m" << endl;
		cout << "Group number: \033[4m" << group_num << "\033[0m" << endl; 
		cout << "Perdonal phone number: \033[4m" << this->phone_num << "\033[0m" << endl;
	}

	void create_Student()  // метод для вводу усіх даних власноруч з консолі
	{
		cout << "Enter your Name|Surname|Po batkovi\n";
		set_nm_srnm_pobat();
		set_birthd();
		set_home();
		set_edu_nm();
		set_edu_place();
		char phone_number_temp[] = "+380639420220";
		set_phone_num(phone_number_temp);
		


		cout << "Enter your \033[4mgroup number: \033[0m";
		char* group_number_temp = new char[18];
		cin.getline(group_number_temp, sizeof(group_number_temp));
		set_group_num(group_number_temp);
	}

	//________________________Cеттери________________________(Призначення одразу кількох полей одного аспекту, таких як ПІБ)

	void set_nm_srnm_pobat() // Метод для вводу зміни ім'я прізвища та по батькові(введення через консоль)
	{
		char name[255];
		char srnm[255];
		char pobat[255];


		cout << "Enter name:";  cin >> name;
		cout << "Enter surname:";  cin >> srnm;
		cout << "Enter po bat'kovi:";  cin >> pobat; //😂😂😂
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		strcpy_s(this->stud_srnm, sizeof(this->stud_srnm), srnm);
		strcpy_s(this->stud_nm, sizeof(this->stud_nm), name);
		strcpy_s(this->stud_po_batkovi, sizeof(this->stud_po_batkovi), pobat);
	}
	void set_nm_srnm_pobat(char* name, char* srnm, char* pobat) // Метод для вводу зміни ім'я прізвища та по батькові(передача даних в параметрах)
	{
		strcpy_s(this->stud_srnm, sizeof(this->stud_srnm), srnm);
		strcpy_s(this->stud_nm, sizeof(this->stud_nm), name);
		strcpy_s(this->stud_po_batkovi, sizeof(this->stud_po_batkovi), pobat);
	}

	void set_birthd()
	{
		int day, month, year;

		cout << "\033[4mFolow instructions below this label\033[0m\n";

		cout << "Enter the \033[4mday\033[0m of your birthday: ";
		cin >> day;

		cout << "Enter the \033[4mmonth\033[0m of your birthday: ";
		cin >> month;

		cout << "Enter the \033[4myear\033[0m of your birthday: ";
		cin >> year;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		this->day = day;
		this->month = month;
		this->year = year;
	}
	void set_birthd(int day, int month, int year)
	{
		this->day = day;
		this->month = month;
		this->year = year;
	}

	void set_home()		//Метод для призначення місця проживання студента
	{
		char city[50], country[50];


		cout << "\nEnter \033[4mname\033[0m of the \033[4mcity\033[0m(student home): ";
		cin.getline(city, (sizeof(city) - 1));

		cout << "Enter \033[4mname\033[0m of the \033[4mcountry\033[0m(student home): ";
		cin.getline(country, (sizeof(country) - 1));


		strcpy_s(this->stud_city, sizeof(this->stud_city), city);
		strcpy_s(this->stud_country, sizeof(this->stud_country), country);
	}
	void set_home(char* city, char* country)		//Метод для призначення місця проживання студента
	{
		strcpy_s(this->stud_city, sizeof(this->stud_city), city);
		strcpy_s(this->stud_country, sizeof(this->stud_country), country);
	}

	void set_edu_nm()
	{
		char name[255];


		cout << "\nEnter \033[4mname\033[0m of the \033[4meducational establishment\033[0m: ";
		cin.getline(name, (sizeof(name) - 1));


		strcpy_s(this->edu_nm, sizeof(this->edu_nm), name);
	}

	void set_edu_nm(char* name)
	{
		strcpy_s(this->edu_nm, sizeof(this->edu_nm), name);
	}

	void set_edu_place()
	{
		char city[50], country[50];


		cout << "\nEnter \033[4mname\033[0m of the \033[4mcity\033[0m(educational establishment): ";
		cin.getline(city, (sizeof(city) - 1));
		cout << "Enter \033[4mname\033[0m of the \033[4mcountry\033[0m(educational establishment): ";
		cin.getline(country, (sizeof(country) - 1));
		/*cin.ignore(numeric_limits<streamsize>::max(), '\n');*/


		strcpy_s(this->edu_city, sizeof(this->edu_city), city);
		strcpy_s(this->edu_country, sizeof(this->edu_country), country);
	}

	void set_edu_place(char* city, char* country)
	{
		strcpy_s(this->edu_city, sizeof(this->edu_city), city);
		strcpy_s(this->edu_country, sizeof(this->edu_country), country);
	}

	//_______________________________________________________


	//________________________Сеттери________________________(кожне поле окремо)

	void set_id(int* id)
	{
		this->stud_id = *id;
	}
	
	void set_day(int* day)
	{
		this->day = *day;
	}
	void set_month(int* month)
	{
		this->month = *month;
	}
	void set_year(int* year)
	{
		this->year = *year;
	}
	
	void set_stud_name(char* name)
	{
		strcpy_s(this->stud_nm, sizeof(this->stud_nm), name);
	}
	void set_stud_surname(char* surname)
	{
		strcpy_s(this->stud_srnm, sizeof(this->stud_srnm), surname);
	}
	void set_stud_po_batkovi(char* po_batkovi)
	{
		strcpy_s(this->stud_po_batkovi, sizeof(this->stud_po_batkovi), po_batkovi);
	}


	void set_stud_city(char* city_name)
	{
		strcpy_s(this->stud_city, sizeof(this->stud_city), city_name);
	}
	void set_stud_country(char* country_name)
	{
		strcpy_s(this->stud_country, sizeof(this->stud_country), country_name);
	}


	void set_edu_name(char* edu_name)
	{
		strcpy_s(this->edu_nm, sizeof(this->edu_nm), edu_name);
	}
	void set_edu_city(char* city_name)
	{
		strcpy_s(this->edu_city, sizeof(this->edu_city), city_name);
	}
	void set_edu_country(char* country_name)
	{
		strcpy_s(this->edu_country, sizeof(this->edu_country), country_name);
	}


	void set_phone_num(char* phone_num)
	{
		strcpy_s(this->phone_num, sizeof(this->phone_num), phone_num);
	}

	void set_group_num(char* group_num)
	{
		strcpy_s(this->group_num, sizeof(this->group_num), group_num);
	}
	//________________________Геттери________________________
	
	
	int* get_id()
	{
		return &this->stud_id;
	}

	int* get_day()
	{
		return &this->day;
	}
	int* get_month()
	{
		return &this->month;
	}
	int* get_year()
	{
		return &this->year;
	}

	char* get_stud_name()
	{
		return this->stud_nm;
	}
	char* get_stud_surname()
	{
		return this->stud_srnm;
	}
	char* get_stud_po_batkovi()
	{
		return this->stud_po_batkovi;
	}


	char* get_stud_city()
	{
		return this->stud_city;
	}
	char* get_stud_country()
	{
		return this->stud_country;
	}


	char* get_edu_name()
	{
		return this->edu_nm;
	}
	char* get_edu_city()
	{
		return this->edu_city;
	}
	char* get_edu_country()
	{
		return this->edu_country;
	}


	char* get_phone_num()
	{
		return this->phone_num;
	}


	char* get_group_num()
	{
		return this->group_num;
	}
};