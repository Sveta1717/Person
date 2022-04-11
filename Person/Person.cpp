// Person.cpp : "Напишите программу, которая показывает на экране консоли меню, состоящее из двух пунктов.
// При выборе пункта 1 в двоичный файл записывается (либо дописывается в конец) один объект классового типа Person.
// При выборе пункта 2 - на экране отображается содержимое полей всех объектов из этого файла

#include <iostream>
#include <fstream> 
#include <windows.h>
#include <string.h>
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

	Person() : Person("Свiтлана", "русий", 160, 55.3) {}	

	void SetName(string name)
	{
		this->name = name;
	}

	void SetColor_hair(string color_hair)
	{
		this->color_hair = color_hair;
	}

	void SetHeight(int height)
	{
		this->height = height;
	}

	void SetWeight(double weight)
	{
		this->weight = weight;
	}

	string GetName() //const
	{
		return name;
	}

	string GetColor_hair() const
	{
		return color_hair;
	}

	int GetHeight() const
	{
		return height;
	}

	double GetWeight() const
	{
		return weight;
	}
};

class WorkWithMenu
{
public:		
	static void ShowMenu(Person& p)
	{
		int n;
		cout << "1. Write\n2. Read\n";
		cin >> n;

		if (n == 1)
		{
			ofstream out("person.txt", ios::binary | ios::out | ios::trunc);
			if (!out.is_open())
			{
				cout << "File Error!\n";
				return;
			}
			else
			{
				cout << "Файл успiшно створено!\n";
				out << p.GetName() << "\n";
				out << p.GetColor_hair() << "\n";
				out << p.GetHeight() << "\n";
				out << p.GetWeight() << "\n";
			}
			out.close();
		}

		else
		{
			ifstream in("person.txt", ios::binary);
			
			if (!in)
			{
				cout << "Вiдкриття файлу неможливе!\n";
			}

			else
			{
				Person copy;
				
				string temp_name;
				string temp_hair;
				int temp_height;
				double temp_weight;				

				in >> temp_name;
				in >> temp_hair;
				in >> temp_height;
				in >> temp_weight;

				cout << "Iм'я:  " << copy.GetName() << "\n" << "Колiр волосся:  " << copy.GetColor_hair() << "\n"
				     << "Рiст: " << copy.GetHeight() << "\n" << "Вага:  " << copy.GetWeight() << "\n";

			}
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

	WorkWithMenu::ShowMenu(p);

	cout << "\n\n";
}
