//Dynamic Array
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct student
{
	int roll_no;
	string name, dfb, gender;
	float math, physic, chemistry, average;
};

int input(student list[], int n)
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
		cout << "|" << setw(7) << left << list[i].average << "|" << endl;
	}
	cout << setfill('-');
	cout << setw(95) << "-" << endl;

}

int main2()
{
	int n;
	cout << "So luong SV can nhap: ";
	cin >> n;
	student* stu;
	stu = new student[n];
	input(stu, n);
	cout << "\n =======Input list====== \n";
	output(stu, 1, n);
	delete[] stu;
	system("pause");
	return 0;
}
