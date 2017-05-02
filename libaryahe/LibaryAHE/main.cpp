// LibaryAHE.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

#include <cstdlib>

#include "library.h"

using namespace std;

void Menu(const Library &lib)
{
	system("cls");

	cout << "Liczba ksizek w bibliotece: " << lib.GetSize() << endl << endl;

	cout << "1. Wyswietl biblioteke" << endl;
	cout << "2. Wyswietl szczegilowe informacje o ksiazce" << endl;
	cout << "3. Dodaj ksiazke" << endl;
	cout << "4. Usun ksiazke" << endl;
	cout << "--------------------------------------------" << endl;
	cout << "0. Koniec" << endl << endl;
	cout << "Twoj wybor: ";
}


int main()
{
	Library lib;

	lib.AddBook(Book("Kowalski Jan", "Czerwony kapturek", 1999, 4, "Ziutek Books", 150, ""));
	lib.AddBook(Book("Nowak Jan", "Jas i Malgosia", 1999, 11, "Ziutek Books", 234, "Bardzo ciekawa bajka"));

	//	lib.Display();
	//	
	//	lib[1].DisplayShort();
	//	
	//	system("pause");
	//	
	char ch;
	bool end = 0;

	while (!end)
	{
		cout << "Liczba ksizek w bibliotece: " << lib.GetSize() << endl;
		Menu(lib);

		cin >> ch;
		cin.clear();
		cin.ignore(10000, '\n');

		switch (ch)
		{
		case '1':
			lib.Display();
			system("pause");
			break;
		case '2':
			cout << "Ktora ksiazka: ";
			int book_number;
			cin >> book_number;
			lib[book_number - 1].Display();
			system("pause");
			break;
		case '3':
		{
			char author[100];
			cout << "Autor: ";
			cin.getline(author, 100);
			char title[300];
			cout << "Tytul: ";
			cin.getline(title, 300);
			unsigned int year;
			cout << "Rok: ";
			cin >> year;

			lib.AddBook(Book(author, title, year, 1, "PWN", 100, "Opis"));
		}
		break;
		case '0':
			end = 1;
			break;
		}
	}

	return 0;
}



