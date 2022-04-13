//Linked list
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

struct student {
	int roll_no;
	string name, dfb, gender;
	float math, physic, chemistry, average;
};

struct node
{
	student* data;
	node* next, * prev;
};

int input(student* stud)
{
		cout << "\nStudent:" << endl;
		cout << "Enter roll no:";
		cin >> stud->roll_no;
		std::cin.ignore(32767, '\n');
		cout << "Enter name:";
		getline(cin, stud->name);
		cout << "Enter date of birth:";
		cin >> stud->dfb;
		cout << "Enter gender:";
		cin >> stud->gender;
		cout << "Enter math scores:";
		cin >> stud->math;
		cout << "Enter physic scores:";
		cin >> stud->physic;
		cout << "Enter chemistry scores:";
		cin >> stud->chemistry;
		stud->average = (stud->chemistry + stud->physic + stud->math) / 3;
	
	return 1;
}
struct List
{
	node* pHead;
};

void new_list(List& L)
{
	L.pHead = NULL;
}
node* new_node()
{
	student* stud = new student;
	input(stud);
	node* p = new node;
	p->next = NULL;
	p->data = stud;
	return p;
}

node add(List& L, node* p)
{
	if (L.pHead == NULL)
	{
		L.pHead = p;
	}
	else
	{
		node* q = L.pHead;
		while (q->next != NULL)

			q = q->next;
		q->next = p;

	}
	return *p;
}

void output(List L)
{
	int n=0;
	cout << setw(5) << left << "|Student";
	cout << setw(10) << left << "|Roll no";
	cout << setw(20) << left << "|Name";
	cout << setw(15) << left << "|Date of birth";
	cout << setw(5) << left << "|Gender";
	cout << setw(5) << left << "|Math";
	cout << setw(5) << left << "|Physic";
	cout << setw(5) << left << "|Chemistry";
	cout << setw(5) << left << "|Average|\n";


	for (node* i = L.pHead; i != NULL; i = i->next)
	{
		cout << setfill('-');
		cout << setw(95) << "-" << endl;
		cout << setfill(' ');
		cout << "|" << setw(7) << left << n+1;
		cout << "|" << setw(9) << left << i->data->roll_no;
		cout << "|" << setw(19) << left << i->data->name;
		cout << "|" << setw(14) << left << i->data->dfb;
		cout << "|" << setw(6) << left << i->data->gender;
		cout << "|" << setw(4) << left << i->data->math;
		cout << "|" << setw(6) << left << i->data->physic;
		cout << "|" << setw(9) << left << i->data->chemistry;
		cout << "|" << setw(7) << left << i->data->average << "|" << endl;
	}
	cout << setfill('-');
	cout << setw(95) << "-" << endl;

}

void Menu(List& l)
{
	int n;
	cout << "======MENU=========" << endl;
	cout << "1. Nhap sinh vien. " << endl;
	cout << "2. In danh sach." << endl;
	cout << "0. Thoat" << endl;
	while (1)
	{
		cout << "Nhap tuy chon : ";
		cin >> n;
		if (n == 1)
		{
			cout << endl;
			cout << "Moi Ban nhap thong tin 1 sinh vien:" << endl;
			node* p = new_node();
			add(l, p);
		}
		if (n == 2)
		{
			cout << "Danh Sach Sinh Vien:" << endl;
			output(l);
		}
		if (n == 0)
		{
			break;
		}
	}
}
int main()
{
	
	
	List L;
	new_list(L);
	Menu(L);
}