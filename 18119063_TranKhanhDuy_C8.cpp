#include <iostream>
using namespace std;


struct node
{
	int data;
	struct node* left;
	struct node* right;
};
typedef struct node NODE;
typedef NODE* tree;

void creattree(tree& t)
{
	t = NULL;
}

void addnode(tree& t, int x)
{
	if (t == NULL)
	{
		NODE* p = new NODE;
		p->data = x;
		p->left = NULL;
		p->right = NULL;
		t = p;
	}
	else
	{
		if (x < t->data)
		{
			addnode(t->left, x);
		}
		else if (x > t->data)
		{
			addnode(t->right, x);
		}
	}
}

void inorder(tree t)
{
	if (t != NULL)
	{
		cout << t->data << " | ";
		inorder(t->left);
		inorder(t->right);
	}
}
NODE* search(tree t, int x)
{
	if (t == NULL)
		return NULL;
	else
	{
		if (x < t->data)//nho hon nut goc --> sang trai
			search(t->left, x);
		else if (x > t->data)//lon hon nut goc --> sang phai	
			search(t->right, x);
		else//bang thi tra ve gia tri
			return t;

	}
}
void nodetemp(tree& X, tree& Y)
{
	if (Y->left != NULL)
	{
		nodetemp(X, Y->left);
	}
	else//bang NULL
	{
		X->data = Y->data;//cap nhat nut can xoa la nut tam
		X = Y;//nut xoa
		Y = Y->right;
	}
}
void deletenode(tree &t, int data)
{
	if (t == NULL)//cay rong
		return;
	else
	{
		if (data < t->data)
			deletenode(t->left, data);
	
		else if (data > t->data)
			deletenode(t->right, data);
		else//tim ra node can xoa
		{
			NODE* X = t;//node thay the
			if (t->left == NULL)//nhanh trai = NULL cay con phai
				t = t->right;   //duyet sang phai cap nhat moi lien ket
			else if (t->right == NULL)
				t = t->left;
			else //node co 2 con
			{
				NODE* Y = t->right;//node thay the node can xoa
				nodetemp(X, Y);
			}
			delete X;
		}
	}
}
void Menu(tree& t)
{
	int s, x;
	cout << "\n\n================Menu================" << endl;
	cout << "0. Ket thuc." << endl;
	cout << "1. Nhap du lieu." << endl;
	cout << "2. Xuat du lieu." << endl;
	cout << "3. Tim kiem" << endl;
	cout << "4. Xoa node" << endl;
	
	cout << "====================================" << endl;
	while (true)
	{
		cout << "Nhap lua chon: ";
		cin >> s;
		if (s < 0 || s>4)
		{
			cout << "\n Lua chon khong hop le";
		}
		else if (s == 1)
		{
			cout << "\n Nhap so nguyen x:";
			cin >> x;
			addnode(t, x);
		}
		else if (s == 2)
		{
			cout << "\n\t\tThong tin cay" << endl;
			inorder(t);
			system("pause");
		}
		else if (s == 3)
		{
			int x;
			cout << "\n Nhap phan tu can tim:" << endl;
			cin >> x;
			NODE* p = search(t, x);
			if (p == NULL)
			{
				cout << "\nPhan tu" << x << "khong ton tai trong cay" << endl;
			}
			else
			{
				cout << "\nPhan tu " << x << " co ton tai trong cay" << endl;
			}
			system("pause");
		}
		else if (s == 4)
		{
			int x;
			cout << "\nNhap gia tri can xoa: " << endl;
			cin >> x;
			deletenode(t, x);
		}
		else
			break;
	}
}
int main()
{
	tree t;
	creattree(t);
	Menu(t);
	system("pause");
	return 1;
}