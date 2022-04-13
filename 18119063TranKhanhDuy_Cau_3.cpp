#include <iostream>
#include <stack>
using namespace std;

struct item_Tower
{
	int num;
	char sour, mid, dest;
	void assign(int n, char a, char b, char c) 
	{
		num = n;			
		sour = a;
		mid = b;
		dest = c;
	}
};

void HN_Tower(int n, char a, char b, char c)
{
	stack<item_Tower> s;
	item_Tower t;
	int d = 0;
	t.assign(n, a, b, c);
	s.push(t);
	while (!s.empty())
	{
		item_Tower temp = s.top();
		s.pop();
		if (temp.num == 1)
			cout << "\n" << ++d << " ." << temp.sour << "------->" << temp.dest;
		else
		{
			t.assign(temp.num - 1, temp.mid, temp.sour, temp.dest);
			s.push(t);
			t.assign(1, temp.sour, temp.mid, temp.dest);
			s.push(t);
			t.assign(temp.num - 1, temp.sour, temp.dest, temp.mid);
			s.push(t);
		}
	}
}

int main()
{
	int n;
	char a='A', b='B', c='C';
	cout << "Nhap so vong: ";
	cin >> n;
	cout << "Thu tu cac buoc can di chuyen: \n";
	HN_Tower(n, a, b, c);
	return 0;
	system("pause");
}