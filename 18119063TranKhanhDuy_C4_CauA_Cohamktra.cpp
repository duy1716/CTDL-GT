//Static array
#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#define MAX 50

using namespace std;

struct student
{
	int roll_no;
	string name, dfb, gender;
	float math, physic, chemistry, average;
};

int input(student list[], int n)
{
	if (n > MAX)
	{
		return 0;
	}
	else
	{
		for (int i = 0;i < n;i++)
		{
			cout << "\nStudent:" << i + 1 << endl;
			cout << "Enter roll no:";
			cin >> list[i].roll_no;
			std::cin.ignore(32767, '\n');
			cout << "Enter name:";
			getline(cin, list[i].name);
			//cin >> List.stud[i].name;
			cout << "Enter date of birth:";
			cin >> list[i].dfb;
			
			cout << "Enter gender:";
			cin >> list[i].gender;
			
			cout << "Enter math scores:";
			cin >> list[i].math;
			
			cout << "Enter physic scores:";
			cin >> list[i].physic;
		     
			
			cout << "Enter chemistry scores:";
			cin >> list[i].chemistry;
			
			list[i].average = (list[i].chemistry + list[i].physic + list[i].math) / 3;
			}
		return 1;
	}
}

int check(student list[], int n)
{
	int dd, mm, yy;
	
		for (int i = 0;i < n;i++) 
		{	//27/11/2000
			dd = atoi(list[i].dfb.substr(0, 2).c_str());
			mm = atoi(list[i].dfb.substr(3, 4).c_str());//chuyen tu string sang int
			yy = atoi(list[i].dfb.substr(6, 9).c_str());
			if (list[i].roll_no > 20199999 || list[i].roll_no < 12100000)
			{
				cout << "Sai MSSS (sinh vien tu K13-K20)." << endl;
				return 1;//sai
			}
			else if (list[i].gender != "Nam" || list[i].gender != "Nu")
			{
				cout << "Sai gioi tinh (Nam hoac Nu)." << endl;
				return 1;//sai
			}
			else if (list[i].math > 10 || list[i].math < 0)
			{
				cout << "Sai diem Toan (diem tu 1-10)." << endl;
				return 1;//sai
			}
			else if (list[i].physic > 10 || list[i].physic < 0)
			{
				cout << "Sai diem Ly (diem tu 1-10)." << endl;
				return 1;//sai
			}
			else if (list[i].chemistry > 10 || list[i].chemistry < 0)
			{
				cout << "Sai diem Hoa (diem tu 1-10)." << endl;
				return 1;//sai
			}
			else if (yy > 2021)
			{
				cout << "Sai nam (<2021)." << endl;
				return 1;
			}
			else if (yy%4==0)//kiem tra nam nhuan
			{
				if (mm > 12 || mm < 1)//kiem tra thang
				{
					cout << "Sai thang (1-12)." << endl;
					return 1;//sai
				}
				else if (mm==2)
				{
					if (dd > 29 || dd < 1)
					{
						cout << "Sai ngay(1-29)" << endl;
						return 1;
					}
					else return 2;
				}
				else if (mm == 1||mm==3|| mm == 5 || mm == 7|| mm == 8|| mm == 10||mm==12)/**/
				{
					if (dd > 31 || dd < 1)
					{
						cout << "Sai ngay(1-31)" << endl;
						return 1;
					}
					else return 2;
				}
				else if (mm == 4 || mm == 6 || mm == 9 || mm == 11 )/**/
				{
					if (dd > 30 || dd < 1)
					{
						cout << "Sai ngay(1-30)" << endl;
						return 1;
					}
					else return 2;
				}
				else return 2;
			}
			else if (yy % 4 != 0)//kiem tra nam ko nhuan
			{
				if (mm > 12 || mm < 1)//kiem tra thang
				{
					cout << "Sai thang (1-12)." << endl;
					return 1;//sai
				}
				else if (mm == 2)
				{
					if (dd > 28 || dd < 1)
					{
						cout << "Sai ngay(1-29)" << endl;
						return 1;
					}
					else return 2;
				}
				else if (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12)/**/
				{
					if (dd > 31 || dd < 1)
					{
						cout << "Sai ngay(1-31)" << endl;
						return 1;
					}
					else return 2;
				}
				else if (mm == 4 || mm == 6 || mm == 9 || mm == 11)/**/
				{
					if (dd > 30 || dd < 1)
					{
						cout << "Sai ngay(1-30)" << endl;
						return 1;
					}
					else return 2;
				}
				else return 2;
			}
			
			else return 2;
		}
}
void output(student list[], int f, int t)
{
	cout << setw(5) << left << "|Student";
	cout << setw(10) << left << "|Roll no";
	cout << setw(20) << left << "|Name";
	cout << setw(15) << left << "|Date of birth";
	cout << setw(5) << left << "|Gender";
	cout << setw(5) << left << "|Math";
	cout << setw(5) << left << "|Physic";
	cout << setw(5) << left << "|Chemistry";
	cout << setw(5) << left << "|Average|\n";


	for (int i = f - 1; i < t; i++)
	{
		cout << setfill('-');
		cout << setw(95) << "-" << endl;
		cout << setfill(' ');
		cout << "|" << setw(7) << left << i + 1;
		cout << "|" << setw(9) << left << list[i].roll_no;
		cout << "|" << setw(19) << left << list[i].name;
		cout << "|" << setw(14) << left << list[i].dfb;
		cout << "|" << setw(6) << left << list[i].gender;
		cout << "|" << setw(4) << left << list[i].math;
		cout << "|" << setw(6) << left << list[i].physic;
		cout << "|" << setw(9) << left << list[i].chemistry;
		cout << "|" << setw(7) << left <<list[i].average << "|" << endl;
	}
	cout << setfill('-');
	cout << setw(95) << "-" << endl;

}

int main()
{
	student stu[MAX];
	int n;
	do
	{
		cout << "So luong SV can nhap (1-50): ";
		cin >> n;
		input(stu, n);		
	} 
	while (check(stu, n)==1);
	cout << "\n =======Input list====== \n";
	output(stu, 1, n);
	system("pause");
    return 0;
}
