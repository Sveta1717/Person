// Person.cpp : "Напишите программу, которая показывает на экране консоли меню, состоящее из двух пунктов.
// При выборе пункта 1 в двоичный файл записывается (либо дописывается в конец) один объект классового типа Person.
// При выборе пункта 2 - на экране отображается содержимое полей всех объектов из этого файла

#include <iostream>
#include <fstream> 
#include <windows.h>
using namespace std;

class Person
{
private:
	string name;
	string color_hair;
	int height;
	double weight;

public:
	Person(string name, string color_hair, int height, double weight)
	{
		this->name = name;
		this->color_hair = color_hair;
		this->height = height;
		this->weight = weight;		
	}

	Person(): Person("Свiтлана", "русий", 160, 55.3) {}
	
	void Menu()
	{
	int n;
		cout << "1. Write\n2. Read\n";
		cin >> n;
		ofstream out("person.txt", ios::binary | ios::out | ios::trunc);

		if (n == 1)
		{			
			if (!out.is_open())
			{
				cout << "File Error!\n";
				return;
			}

			else
			{
				cout << "Файл успiшно створено!\n";
				out << "Iм'я:  " << name << "\n";
				out << "Колiр волосся:  " << color_hair << "\n";
				out << "Рiст: " << height << "\n";
				out << "Вага:  " << weight;
			}
			out.close();			
		}

		else
		{
			ifstream in("person.txt", ios::binary | ios::in);

			if (!in)
			{
				cout << "Вiдкриття файлу неможливе!\n";
			}

			else
			{				
			in.seekg(0, ios::beg); 
			Person p;
			in.read((char*)&p, sizeof(Person)); 
			cout << "Iм'я:  " << p.name << "\n" << "Колiр волосся:  " << p.color_hair << "\n"
				<< "Рiст: " << p.height << "\n" << "Вага:  " << p.weight << "\n";			
			}

			out.close();
			in.close();
		}
	}
};

int main()
{
	setlocale(0, "");
	system("title Person");
	system("color 0B");
	Person p;

	p.Menu();	

	cout << "\n\n";
}

