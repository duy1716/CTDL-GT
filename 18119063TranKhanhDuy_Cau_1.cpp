#include <iostream>
#include <stack> 
using namespace std;

int main()
{
    stack <int> S2;
    stack <char> S16;
    int so2,so16,du16,du2,n;
    cout << "Nhap so can chuyen: ";
    cin >> n;
    so2=n;
    so16 = n;
    while (so2)
    {
        du2 = so2 % 2;
        S2.push(du2);
        so2 /= 2;
    }
    cout << "So " << n << " trong he 2 la: " << so2;
    while (!S2.empty())
    {
        cout << S2.top();
        S2.pop();
    }
    cout << endl;
    while (so16)
    {
        du16 = so16 % 16;
       if (du16>9)
       {
           S16.push(du16 + 55);
       }
       else
       {
           S16.push(du16 + 48);
       }
       
        so16 /= 16;
    }
    cout << "So " << n << " trong he 16 la: " << so16;
    while (!S16.empty())
    {
        cout << S16.top();
        S16.pop();
    }
    cout << endl;
    system("pause");
    return 0;
}