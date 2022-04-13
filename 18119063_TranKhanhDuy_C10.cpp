#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#define MAX 100
using namespace std;
int a[MAX];
int m = 0;
int hashTable[20]; 
int hashTableSize = 20;
void chuyenKieu(char* s)
{
	int res = 0,j=0;

		for (int i = 0; i < strlen(s); i++)
		{
			if (s[i] != ' ')
			{
				res = res * 10 + (s[i] - '0');
			}
			else if (s[i] == ' ')
			{
				a[j] = res;
				j++;
				s[i] = s[i + 1];
				res = 0;
			}
			else 
				break;
		}
}
void readDataFromFile(string file)
{
	char* line = new char[MAX];
	
	ifstream fileInput(file);
	if (fileInput.fail())
	{
		cout << "Cannot open file at " << file << endl;
		return;
	}
	
	while (!fileInput.eof())
	{
		fileInput.getline(line, MAX-1);
		cout << line << endl;
	}

	chuyenKieu(line);
	for (int i = 0; i < strlen(line);i++)
	{
		if ((a[i] == 0) && (a[i + 1] == 0))
			m++;
	}
	cout << m<< endl;
	m = strlen(line) - m;
}
void SelectionSort()
{
	int min;
	for (int i = 0; i <  m; i++)
	{
		min = i;
		for (int j = i + 1; j < m; j++)
			if (a[j] < a[min])
				min = j;
		if (min != i)
			swap(a[i], a[min]);
	}
}
void linear(int q)
{
	int i;
	for (i = 0;i < m;i++)
	{
		if (a[i] == q)
		{
			cout << "Tim thay gia tri " << q << " tai phan tu " << i << endl;
			system("pause");
		}
	}
}
void binary(int first, int size, int q)
{
	int mid=first+size/2;
	if (q == a[mid])
	{
		cout << "Tim thay gia tri " << q << " tai phan tu " << mid << endl;
		system("pause");
	}
	else if(q < a[mid])
		binary(first,size/ 2,q);
	else
		binary(mid+1, (size-1) / 2, q);
}

int hashFunc(int num)
{
	return (num % hashTableSize);
}

void insert_hash(int key) 
{
	int index = hashFunc(key);
	while (hashTable[index] != 0)
		index = (index + 1) % hashTableSize;
	hashTable[index] = key;
}

void search_hash(int x)
{
	int index = hashFunc(x);
	cout << "Bang bam:" << endl;
	for (int i = 0;i < 20;i++)
		cout << hashTable[i] << " | ";
	cout << endl;
	while (hashTable[index] != x and hashTable[index] != 0)
		index = (index + 1) % hashTableSize;
	if (hashTable[index] == x)
	{
		cout << "Tim thay gia tri " << x <<" tai vi tri thu " << index << " trong bang bam" << endl;
		system("pause");
	}
	else
	{
		cout << "Khong tim thay phan tu!\n";
		system("pause");
	}
}
int main()
{
	//string filePath = "D:/Savefile/my_document.txt";
	string filePath = "input.txt";//duong dan file
	readDataFromFile(filePath);
	SelectionSort();
	for (int i = 0; i <m;i++)
		cout << "Phan tu" << " [" << i << "]: " << a[i] << endl;
	int h,c;
	for (int i = 0;i < m;i++)
	{
		insert_hash(a[i]);
	}
	while (1)
	{
		system("cls");
		cout << "1.Tim kiem tuyen tinh" << endl;
		cout << "2.Tim kiem nhi phan" << endl;
		cout << "3.Bang bam" << endl;
		cout << "0.Exit" << endl;
		cout << "Nhap lua chon" << endl;
		cin >> h;
		if (h == 1)
		{
			cout << "Nhap phan tu can tim" << endl;
			cin >> c;
			linear(c);
		}
		else if (h == 2)
		{
			cout << "Nhap phan tu can tim" << endl;
			cin >> c;
			binary(0,m,c);
		}
		else if (h == 3)
		{
			cout << "Nhap phan tu can tim" << endl;
			cin >> c;
			search_hash(c);
		}
		else
			break;
	}
	return 0;
}