#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <windows.h>
#define MAX 50

using namespace std;

struct student
{
	char MSSV[10], hoten[30];
	int gioitinh;
	char diachi[50];
	float dtb;
};

int Nhap1SV(student list[], int n)
{
	system("cls");
	cout << "Nhap MSSV:";
	cin >> list[n].MSSV;
	std::cin.ignore(32767, '\n');
	cout << "Nhap ten:";
	fgets(list[n].hoten, sizeof(list[n].hoten), stdin);
    do
    {
	cout << "Nhap gioi tinh (1: Nu; 0: Nam):";
	cin >> list[n].gioitinh;
	}
	while(list[n].gioitinh!=0 && list[n].gioitinh !=1);
	std::cin.ignore(32767, '\n');
	cout << "Nhap dia chi:";
	fgets(list[n].diachi, sizeof(list[n].diachi), stdin);
	cout << "Nhap diem TB:";
	cin >> list[n].dtb;
	return 1;		
}

void XuatDSSV(student list[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Sinh vien " << i+1 <<endl;
		cout << "|MSSV     |: " << list[i].MSSV<< endl;;
		cout << "|Ho Ten   |: " << list[i].hoten;
		cout << "|Gioi Tinh|: "  << list[i].gioitinh<< endl;;
		cout << "|Dia Chi  |: " << list[i].diachi;
		cout << "|Diem TB  |: " <<list[i].dtb << endl;
	}
	system("pause");
}

int TimSV(student list[], int n, char x[])
{
	for(int i=0; i<n; i++)
		if(strcmp(list[i].MSSV,x)==0)
		return i; //Tìm thay
	return -1; //Không tìm thay
}

void XoaSV(student list[], int &n, char x[])
{
	int vt=TimSV(list, n, x); //Tìm vi tri
	if(vt==-1)
		cout << "Khong tim thay Sinh Vien.";
	else
	{
		for(int i=vt; i<=n-2; i++)
			list[i]=list[i+1];
		cout << "Da xoa sinh vien co MSSV: "<< x <<endl;
		system("pause");
		n--; //Giam so luong phan tu
	}			
}
void SapTheoDTB(student list[], int n) 
{
    student tmp;
    for (int i = 0;i < n;i++) 
	{
        for (int j = i + 1; j < n;j++) 
		{
            if (list[i].dtb > list[j].dtb) 
			{
                tmp = list[i];
                list[i] = list[j];
                list[j] = tmp;
            }
        }
    }
}
void SapTheoHoTen(student list[], int n) 
{
    int min;
    for (int i = 0; i < n - 1; i++)
    {
        min = i; 
        for (int j = i + 1; j < n; j++)
            //if ([j] < A[min]) 
            if (strcmp(list[j].hoten,list[min].hoten)<0)
                min = j; 
        if (min != i) 
            swap(list[i], list[min]);
    }
}
int main()
{
	student stu[MAX];
	int n=0,s;
	char x[10];

	while (1)
	{
		system("cls");
		cout << "\n\n================Menu================" << endl;
		cout << "1. Nhap du lieu sinh vien." << endl;
		cout << "2. Xuat danh sach sinh vien." << endl;
		cout << "3. Xoa sinh vien" << endl;
		cout << "4. Sap xep theo ÐTB." << endl;
		cout << "5. Sap xep theo Ho va ten." << endl;
		cout << "0. Ket thuc." << endl;
		cout << "====================================" << endl;
		cout << "Nhap lua chon(0-5):";
		cin >> s;
		if (s < 0 || s>5)
		{
			cout << "Lua chon khong hop le" << endl;
		}
		else if (s==1)
		{
			system("cls");
			Nhap1SV(stu,n);
			n++;
		}
		else if (s==2)
		{
			system("cls");
			XuatDSSV(stu,n);
		}
			else if (s==3)
		{
			std::cin.ignore(32767, '\n');
			cout << "Nhap MSSV muon xoa: ";
			cin>>x;
			XoaSV(stu, n ,x);
		}
			else if (s==4)
		{
			SapTheoDTB(stu, n);
			XuatDSSV(stu,n);
		}
			else if (s==5)
		{
			SapTheoHoTen(stu, n);
			XuatDSSV(stu,n);
		}
	}

    return 0;
}
