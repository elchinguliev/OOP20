#include<iostream>
#include<fstream>
#include<string>
#include<stack>
using namespace std;



class Contact {
public:
	string name;
	string surname;
	string phonenumber;

	void CreateContact() {

		cout << "Name : " << endl;
		cin >> name;
		cout << "Surname : " << endl;
		cin >> surname;
		cout << "Phone number : " << endl;
		cin >> phonenumber;
	}
	void ShowContact() {
		cout << "Name " << name << endl;
		cout << "Surname : " << surname << endl;
		cout << "Phone number : " << phonenumber << endl;
	}
	void WriteOnFile() {
		char ch;
		ofstream f1;
		f1.open("contact.txt", ios::app);
		do
		{
			CreateContact();
			f1.write(reinterpret_cast<char*>(this), sizeof(*this));
			cout << "Do u have next data ? y / n " << endl;
			cin >> ch;
		} while (ch=='y');
		cout << "Contact added succesfully " << endl;
		f1.close();
	}

	void ReadFromFile() {
		ifstream f2;
		f2.open("contact.txt", ios::binary);
		cout << "CONTACT : " << endl;
		while (!f2.eof())
		{
			if (f2.read(reinterpret_cast<char*>(this), sizeof(*this)))
			{
				ShowContact();
			}
		}f2.close();
	}
	void SearchOnFile() {
		ifstream f3;
		string searchedname;;
		cout << "Enter name : " << endl;
		cin >> searchedname;
		f3.open("contact.txt", ios::binary);
		while (!f3.eof())
		{
			if (f3.read(reinterpret_cast<char*>(this), sizeof(*this)))
			{
				if (name ==searchedname)
				{
					ShowContact();
					cout << searchedname << " founded" << endl;
				}
				else
				{
					cout << "No contact founded " << endl;
				}
				
			}
			
		}
		
		f3.close();
	}

	void DeleteFromFile() {
		ofstream f4;
		ifstream f5;
		string deletedname;;
		
		f5.open("contact.txt", ios::binary);
		f4.open("New.txt", ios::binary);
		cout << "Enter name which u want delete : " << endl;
		cin >> deletedname;
		while (!f5.eof())
		{
			if (f5.read(reinterpret_cast<char*>(this), sizeof(*this)))
			{
				if (name != deletedname)
				{
					f4.write(reinterpret_cast<char*>(this), sizeof(*this));
					f5.close();
					f4.close();
					remove("contact.txt");
					cout << "contact deleted !!!";
				}
				else
				{
					cout << "contact not founded" << endl;
					break;
				}
			}
			

		}
	
		
		
	
	}
	
};
void main() {
	Contact c1;
	int choice;
	cout << "Add contact [1]" << endl;
	cout << "List of all contact [2]" << endl;
	cout << "Delete contact [3]" << endl;
	cout << "Search contact [4]" << endl;
	cout << "Enter your choice : " << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		system("cls");
		c1.WriteOnFile();
		break;
	case 2:
		system("cls");
		c1.ShowContact();
		break;
	case 3:
		system("cls");
		c1.DeleteFromFile();
		break;
	case 4:
		system("cls");
		c1.SearchOnFile();
		break;
	case 0:
		system("cls");
		cout << "Thanks " << endl;
		exit(0);
		break;
		
		
	}
	}




