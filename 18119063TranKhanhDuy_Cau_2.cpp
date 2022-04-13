#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

template <class KieuDuLieuTongQuat>
class Stack
{
private:
	struct Node
	{
		KieuDuLieuTongQuat Value;
		Node* pNext;
	};
	Node* pHead;
	void Huy()
	{
		Node* p = pHead;
		while (pHead)
		{
			p = pHead;
			pHead = p->pNext;
			delete p;
		}
	}
	Node* CreateNode(KieuDuLieuTongQuat x)
	{
		Node* p = new Node;
		if (!p) exit(1);
		p->Value = x;
		p->pNext = NULL;
		return p;
	}
public:
	Stack();
	~Stack()
	{
		Huy();
	}
	bool Empty()
	{
		return (pHead == NULL);
	}
	int Size()
	{
		Node* p = pHead;
		KieuDuLieuTongQuat i = 0;
		while (p)
		{
			p = p->pNext;
			i++;
		}
		return i;
	}
	KieuDuLieuTongQuat Top()
	{
		if (pHead)
			return pHead->Value;
		return -1;
	}
	void Push(KieuDuLieuTongQuat x)
	{
		Node* p = CreateNode(x);
		if (!pHead)
			pHead = p;
		else
		{
			p->pNext = pHead;
			pHead = p;
		}
	}
	void Pop()
	{
		if (pHead)
		{
			Node* p = pHead;
			pHead = p->pNext;
			delete p;
		}
	}
};

template <class KieuDuLieuTongQuat>
Stack<KieuDuLieuTongQuat>::Stack()
{
	pHead = NULL;
}

bool LaTH(char c)
{
	return (c >= '0' && c <= '9');
}
bool LaTT(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^');
}
int UT(char c)
{

	if (c == '+' || c == '-') return 1;
	if (c == '*' || c == '/' || c == '%') return 2;
	if (c == '^') return 3;
	return 0;
}


string ChuyenTrungToSangHauTo(string TT)
{
	string HT = "";
	Stack<char> S;
	int len = TT.size();
	for (int i = 0; i < len; i++)
	{
		if (LaTH(TT[i]))
		{
			while (LaTH(TT[i]))
				HT += TT[i++];
			HT += ' ';
		}
		if (TT[i] == '(')
			S.Push(TT[i]);
		if (TT[i] == ')')
		{
			while (S.Top() != '(')
			{
				HT += S.Top();
				S.Pop();
			}
			S.Pop();
		}
		if (LaTT(TT[i]))
		{
			while (!S.Empty() && UT(S.Top()) >= UT(TT[i]))
			{
				HT += S.Top();
				S.Pop();
			}
			S.Push(TT[i]);
		}
	}
	while (!S.Empty())
	{
		HT += S.Top();
		S.Pop();
	}
	return HT;
}
float TinhHauTo(string HT)
{
	Stack<float> S;
	float x = 0, a, b, c;
	int len = HT.size();
	for (int i = 0; i < len; i++)
	{
		if (LaTH(HT[i]))
		{
			while (LaTH(HT[i]))
				x = x * 10 + HT[i++] - 48;
			S.Push(x);
			x = 0;
		}
		if (LaTT(HT[i]))
		{
			a = S.Top();
			S.Pop();
			b = S.Top();
			S.Pop();
			if (HT[i] == '-') c = b - a;
			if (HT[i] == '*') c = b * a;
			if (HT[i] == '/') c = b / a;
			if (HT[i] == '+') c = b + a;
			if (HT[i] == '%') c = int(b) % int(a);
			if (HT[i] == '^') c = pow(b, a);
			S.Push(c);
		}
	}
	cout << c;
	return S.Top();
}
void main()
{
	string a;
	cout << "Nhap bieu thuc: ";
	getline(cin, a);
	a = ChuyenTrungToSangHauTo(a);
	ChuyenTrungToSangHauTo(a);
	cout << "Gia tri bieu thuc= ";
	TinhHauTo(a);
	cout << endl;
	system("pause");
}