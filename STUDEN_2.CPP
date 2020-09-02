
#include <iostream.h>
#include <conio.h>
#include <fstream.h>
#include <stdio.h>
#include <stdlib.h>
#include <process.h>

\*
        Mukta Choudhury
        
*\


	class student
{
	int rollno;
	char fname[10];
	char lname[10];
public:
	void putdata()
	{
		cout << "Enter the Roll no :";
		cin >> rollno;
		cout << "Enter the First name:";
		cin >> fname;
		cout << "Enter the last name :";
		cin >> lname;
	}
	void updatedata()
	{
		cout << "Enter the First name:";
		cin >> fname;
		cout << "Enter the last name :";
		cin >> lname;
	}
	void getdata()
	{
		cout << "\n roll no:" << rollno << endl;
		cout << "\n first name:" << fname << endl;
		cout << "\n last name:" << lname << endl;
	}
	int getrno()
	{
		return rollno;
	}
	void Menu();
	void Add();
	void Display();
	void Search();
	void Modify();
	void Delete();
}s1;

void student::Menu()
{
	clrscr();
	int choice;
	while (1)
	{
		cout << "********MENU********" << endl;
		cout << "\n 1. add :" << endl;
		cout << "\n 2.display :" << endl;
		cout << "\n 3.search:" << endl;
		cout << "\n 4.modify:" << endl;
		cout << "\n 5.delete:" << endl;
		cout << "\n 6.exit:" << endl;
		cout << "enter your choice:" << endl;
		cin >> choice;

		switch (choice)
		{
			case 1:
			{
				Add();
				cout << "display the main menu" << endl;
				break;
			}
			case 2:
			{
				Display();
				cout << "display the main menu" << endl;
				break;
			}
			case 3:
			{
				Search();
				cout << "display the main menu" << endl;
				break;
			}
			case 4:
			{
				Modify();
				cout << "display the main menu" << endl;
				break;
			}
			case 5:
			{
				Delete();
				cout << "display the main menu" << endl;
				break;
			}
			case 6:
			{
				cout << "exiting" << endl;
				return;
			}
			default:
			{
				cout << "wrong choice......!!";
				break;
			}
		}
	}
}
void student::Add()
{
	char ch = 'y';
	fstream f;
	f.open("stud.dat", ios::app);
	while (ch == 'y' || ch == 'Y')
	{
		s1.putdata();
		f.write((char*)&s1, sizeof(s1));
		cout << "Want to continue....";
		cin >> ch;
	}
	f.close();
}
void student::Display()
{
	fstream f;
	f.open("stud.dat", ios::in | ios::binary);
	if (!f.eof())
	{
		int seekPosition = 0;

		while (!f.eof())
		{
			f.read((char*)&s1, sizeof(s1));
			seekPosition = seekPosition + sizeof(s1);
			f.seekg(seekPosition);

			if (seekPosition > f.tellg())
			{
				break;
			}

			s1.getdata();
			cout << "press any key....for next record" << endl;
			getch();
		}
	}
	f.close();
}
void student::Search()
{
	int rno;
	fstream f;
	cout << "enter the roll no to be searched for:";
	cin >> rno;
	f.open("stud.dat", ios::in | ios::binary);
	if (f.eof())
	{
		cout << "file not found";
	}
	else
	{
		int seekPosition = 0;

		while (!f.eof())
		{
			f.read((char*)&s1, sizeof(s1));
			seekPosition = seekPosition + sizeof(s1);
			f.seekg(seekPosition);

			if (seekPosition > f.tellg())
			{
				cout << "Record for the roll no. does not exist" << endl;
				cout << "press any key...." << endl;
				getch();
				break;
			}

			if (s1.getrno() == rno)
			{
				s1.getdata();
				cout << "press any key...." << endl;
				getch();
				break;
			}
		}
		f.close();
	}
}
void student::Modify()
{
	int rno;
	long pos;
	fstream f;
	cout << "enter the roll no to be searched for:";
	cin >> rno;
	f.open("stud.dat", ios::in | ios::out | ios::binary);
	if (f.eof())
	{
		cout << "file not found";
	}
	else
	{
		int seekPosition = 0;

		while (!f.eof())
		{
			f.read((char*)&s1, sizeof(s1));
			seekPosition = seekPosition + sizeof(s1);
			f.seekg(seekPosition);

			if (seekPosition > f.tellg())
			{
				cout << "Record for the roll no. does not exist" << endl;
				cout << "press any key...." << endl;
				getch();
				break;
			}

			if (s1.getrno() == rno)
			{
				pos = f.tellg();
				cout << "enter the new record:" << endl;
				s1.updatedata();
				f.seekp(pos - sizeof(s1));
				f.write((char*)&s1, sizeof(s1));
				cout << "press any key...." << endl;
				getch();
				break;
			}
		}
		f.close();
	}
}
void student::Delete()
{
	int rno;
	cout << "enter the roll no to be deleted:";
	cin >> rno;
	fstream fdup;
	fstream forig;
	fdup.open("new.dat", ios::out);
	forig.open("stud.dat", ios::in);
	if (forig.eof())
	{
		cout << "file not found";
		exit(0);
	}
	else
	{
		int seekPosition = 0;

		while (!forig.eof())
		{
			forig.read((char*)&s1, sizeof(s1));
			seekPosition = seekPosition + sizeof(s1);
			forig.seekg(seekPosition);

			if (seekPosition > forig.tellg())
			{
				cout << "press any key...." << endl;
				getch();
				break;
			}

			if (s1.getrno() != rno)
			{
				fdup.write((char*)&s1, sizeof(s1));
			}
		}
	}

	forig.close();
	fdup.close();
	remove("stud.dat");
	rename("new.dat", "stud.dat");
}
student obj;
void main()
{
	clrscr();
	obj.Menu();
}