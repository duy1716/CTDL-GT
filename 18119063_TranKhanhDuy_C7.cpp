#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;
string filePath = ("D:/Savefile/qlsv.txt");//duong dan file
ofstream fileOutput (filePath);
struct student
{
	int roll_no;
	char name[30];
	char dfb[10];
	char gender[4];
	float math, physic, chemistry, average;
};
struct node
{
	student data;
	node* left;	
	node* right;
 };
typedef node* tree;


int cmp_roll_no(student x, student y)
{
	if (x.roll_no == y.roll_no)
		return 0;
	else if (x.roll_no > y.roll_no)
		return 1;
	else
		return -1;
}

student input()
{
	char nam[4] = "nam";
	char nu[4] = "nu";
	student x;
	do
	{
		cout << "Enter roll_no(Exit press 0):";
		cin >> x.roll_no;
		if (x.roll_no == 0)
		{
			return x;
		}
	} while ( x.roll_no < 13100000 ||  x.roll_no > 20199999);//k13-k20
	std::cin.ignore(32767, '\n');
	cout << "Enter name:";
	cin >> x.name;
	cout << "Enter date of birth:";
	cin >> x.dfb;
	do 
	{
		cout << "Enter gender:";
		cin >> x.gender;
	} while ((strcmp(x.gender, nu) !=0) && (strcmp(x.gender, nam) != 0));
	do
	{
		cout << "Enter math scores:";
		cin >> x.math;
	} while (x.math > 10 || x.math < 0);
	do
	{
	cout << "Enter physic scores:";
	cin >> x.physic;
	} while (x.physic > 10 || x.physic < 0);
	do
	{
		cout << "Enter chemistry scores:";
		cin >> x.chemistry;
	} while (x.chemistry > 10 || x.chemistry < 0);
	x.average = (x.chemistry + x.physic + x.math) / 3;
	return x;
}
void output(student x)
{
		int i=0;
		cout <<setfill('-');
		cout << setw(95) << "-" << endl;
		cout << setfill(' ');
		cout << "|" << setw(7) << left << i++;
		cout << "|" << setw(9) << left << x.roll_no;
		cout << "|" << setw(19) << left << x.name;
		cout << "|" << setw(14) << left << x.dfb;
		cout << "|" << setw(6) << left << x.gender;
		cout << "|" << setw(4) << left << x.math;
		cout << "|" << setw(6) << left << x.physic;
		cout << "|" << setw(9) << left << x.chemistry;
		cout << "|" << setw(7) << left << x.average << "|" << endl;
		cout << setfill('-');
		cout << setw(95) << "-" << endl;
}
void outputfile(student x)
{
	
	int i = 0;
	fileOutput << setfill('-');
	fileOutput << setw(95) << "-" << endl;
	fileOutput << setfill(' ');
	fileOutput << "|" << setw(7) << left << i++;
	fileOutput << "|" << setw(9) << left << x.roll_no;
	fileOutput << "|" << setw(19) << left << x.name;
	fileOutput << "|" << setw(14) << left << x.dfb;
	fileOutput << "|" << setw(6) << left << x.gender;
	fileOutput << "|" << setw(4) << left << x.math;
	fileOutput << "|" << setw(6) << left << x.physic;
	fileOutput << "|" << setw(9) << left << x.chemistry;
	fileOutput << "|" << setw(7) << left << x.average << "|" << endl;
	fileOutput << setfill('-');
	fileOutput << setw(95) << "-" << endl;
}
int addnode(tree& T, student x)
{
	if (T != NULL)//co phan tu
	{
		if (cmp_roll_no(T->data, x) == 0)
			return -1;//node da co
		if (cmp_roll_no(T->data, x) > 0)
			return addnode(T->left, x);
		else if (cmp_roll_no(T->data, x) <0)
			return addnode(T->right, x);
	}
	T = (node*)malloc(sizeof(node));
	if (T == NULL)
		return 0;
	T->data = x;
	T->left = T->right = NULL;
	return 1;
}
void creattree(tree& T)// nhap cay
{
	student x;
	while (1)
	{
		cout << "--Nhap Thong Tin Sinh Vien Can Them--" << endl << endl;
		x = input();
		if (x.roll_no == 0) break;
		int check = addnode(T, x);
		if (check == -1)
			cout << "\n---Ma Sinh Vien Da Co---\n" << endl;
		else if (check == 0)
			cout << "---Bo Nho Day---\n" << endl;
		else cout << "\n---Them Thanh Cong---\n\n";
	}

}
void inorder(tree T)
{
	//cay con phan tu
	if (T != NULL)
	{
		inorder(T->left);
		output(T->data);
		inorder(T->right);
	}
}

void writeDataToFile(tree T)
{
	if (T != NULL)
	{
		writeDataToFile(T->left);
		outputfile(T->data);
		writeDataToFile(T->right);
	}
}
void readDataFromFile(string file)
{
	ifstream fileInput(file);

	if (fileInput.fail())
	{
		cout << "Cannot open file at " << file <<endl;
		return;
	}

	while (!fileInput.eof())
	{
		char line[255];
		fileInput.getline(line, 255);
		std::cout << line << std::endl;
	}
}

void main()
{
	int s;
	tree T = NULL;
	
	cout << "\n\n================Menu================" << endl;
	cout << "1. Nhap du lieu." << endl;
	cout << "2. Xuat du lieu." << endl;
	cout << "3. Luu du lieu vao file txt." << endl;
	cout << "4. Doc file txt." << endl;
	cout << "0. Ket thuc." << endl;
	cout << "====================================" << endl;
	while (1)
	{
		cout << "Nhap lua chon(0-4):";
		cin >> s;
		if (s < 0 || s>4)
		{
			cout << "Lua chon khong hop le" << endl;
		}
		else if (s == 1)
		{
			creattree(T);
		}
		else if (s == 2)
		{
			cout << "\n =======Input list====== \n";
			cout << setw(5) << left << "|Student";
			cout << setw(10) << left << "|Roll no";
			cout << setw(20) << left << "|Name";
			cout << setw(15) << left << "|Date of birth";
			cout << setw(5) << left << "|Gender";
			cout << setw(5) << left << "|Math";
			cout << setw(5) << left << "|Physic";
			cout << setw(5) << left << "|Chemistry";
			cout << setw(5) << left << "|Average|\n";
			inorder(T);
		}
		else if (s == 3)
		{
			fileOutput << "\n =======Input list====== \n";
			fileOutput << setw(5) << left << "|Student";
			fileOutput << setw(10) << left << "|Roll no";
			fileOutput << setw(20) << left << "|Name";
			fileOutput << setw(15) << left << "|Date of birth";
			fileOutput << setw(5) << left << "|Gender";
			fileOutput << setw(5) << left << "|Math";
			fileOutput << setw(5) << left << "|Physic";
			fileOutput << setw(5) << left << "|Chemistry";
			fileOutput << setw(5) << left << "|Average|\n";
			writeDataToFile(T);
		}
		else if (s == 4)
		{
			cout << "Doc du lieu tu file txt" << endl;
			readDataFromFile(filePath);
		}
		else
		{
			break;
		}
	}
	system("pause");
}