#include <iostream>
using namespace std;
struct Node
{
	int data;
	Node* next;
};

struct LinkedList
{
	Node* head;
	Node* tail;
};
Node* CreateNode(int init_data)
{
	Node* node = new Node;
	node->data = init_data;
	node->next = NULL;
	return node;
}

void CreateList(LinkedList& l)
{
	l.head = NULL;
	l.tail = NULL;
}

void AddHead(LinkedList& l, Node* node)
{
	if (l.head == NULL)
	{
		l.head = node;
		l.tail = node;
	}
	else
	{
		node->next = l.head;
		l.head = node;
	}
}

void AddTail(LinkedList& l, Node* node)
{
	if (l.head == NULL)
	{
		l.head = node;
		l.tail = node;
	}
	else
	{
		l.tail->next = node;
		l.tail = node;
	}
}

void InsertAfterQ(LinkedList& l, Node* p, Node* q)
{
	if (q != NULL)
	{
		p->next = q->next;
		q->next = p->next;
		if (l.tail == q)
			l.tail = p;
	}
	else
		AddHead(l, p);
}

int RemoveHead(LinkedList& l, int& x)
{
	if (l.head != NULL)
	{
		Node* node = l.head;
		x = node->data;
		l.head = node->next;
		delete node;
		if (l.head == NULL)
			l.tail = NULL;
		return 1;
	}
	return 0;
}

int RemoveAfterQ(LinkedList& l, Node* q, int& x)
{
	if (q != NULL)
	{
		Node* p = q->next;
		if (p != NULL)
		{
			if (l.tail == p)
				l.tail = q;
			q->next = p->next;
			x = p->data;
			delete p;
			return 1;
		}
		return 0;
	}
	return 0;
}

Node* GetNode(LinkedList l, int index)
{
	Node* node = l.head;
	int i = 0;
	while (node != NULL && i != index)
	{
		node = node->next;
		i++;
	}
	if (i == index && node != NULL)
		return node;
	return NULL;
}

void PrintList(LinkedList l)
{
	cout << "Danh sach nhap vao: ";
	if (l.head != NULL)
	{
		Node* node = l.head;
		while (node != NULL)
		{
			cout << node->data << ' ';
			node = node->next;
		}
	}
	system("pause");
}

Node* Search(LinkedList l, int x)
{
	Node* node = l.head;
	while (node != NULL && node->data != x)
		node = node->next;
	if (node != NULL)
		return node;
	return NULL;
}
void SearchMax(LinkedList l)
{
	Node* node;
	int max = l.head->data;
	for(node=l.head->next;node!=NULL;node=node->next) 
		if(node->data > max) 
			max=node->data; 
	cout << "Phan tu lon nhat: " << max <<endl;
	system("pause");
}
void SearchMin(LinkedList l)
{
	Node* node;
	int pos=0;
	int min = l.head->data;
	for(node=l.head->next;node!=NULL;node=node->next) {
		if(node->data < min) 
			min=node->data;	
			pos++;
		}
	cout << "Phan tu nho nhat vi tri: " << pos <<endl;
	system("pause");
}
int Length(LinkedList l)
{
	int count = 0;
	Node* node = l.head;
	while (node != NULL)
	{
		count++;
		node = node->next;
	}
	return count;
	system("pause");
}

void DestroyList(LinkedList& l)
{
	int x;
	Node* node = l.head;
	while (node != NULL)
	{
		RemoveHead(l, x);
		node = l.head;
	}
	l.tail = NULL;
}
bool laSoNguyenTo(int n)
{
    // Neu n < 2 thi khong phai la SNT
    if (n < 2){
        return false;
    }       
     
    for (int i = 2; i < (n - 1); i++){
        if (n % i == 0){
            return false;
        }   
    }
     
    return true;
}
int main()
{
	int s;
	LinkedList list;
	CreateList(list);
	Node* node;
	while (1)
	{
		system("cls");
		cout << "\n\n================Menu================" << endl;
		cout << "1. Nhap du lieu." << endl;
		cout << "2. Xuat danh sach va tim phan tu lon nhat." << endl;
		cout << "3. Dem so nguyen to" << endl;
		cout << "4. Them phan tu nguyen." << endl;
		cout << "5. Xoa phan tu nho nhat." << endl;
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
			int i;
			system("cls");
			do{
				
				cout << "Nhap so nguyen to: " << endl;
				cin >> i;
				node = CreateNode(i);
				AddHead(list, node);
				if (laSoNguyenTo(i) == false )
					RemoveHead(list, i);
			}while (laSoNguyenTo(i) == false );
		}
		else if (s==2)
		{
			system("cls");
			
			PrintList(list);
			SearchMax(list);
			
		}
			else if (s==3)
		{
		int len = Length(list);
		cout << "So phan tu: " << len << endl;
		system("pause");
		}
			else if (s==4)
		{
		int i;
		do{
				
				cout << "Nhap so nguyen to: " << endl;
				cin >> i;

			}while (laSoNguyenTo(i) == false );
		Node* searchInList = Search(list, 2);
		
		Node* nodex = CreateNode(i);
		InsertAfterQ(list, nodex, searchInList);
		//node = CreateNode(i);
		//AddHead(list, node);
		cout << "List after insert: ";
		PrintList(list);
		cout << endl;	
		}
			else if (s==5)
		{
		SearchMin(list);
		}
		else 
		break;
	}

    return 0;
	// Add sample data to list
	
	
}
