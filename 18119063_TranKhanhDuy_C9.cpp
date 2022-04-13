#include <iostream>
#include <stack>
using namespace std;

void SelectionSort(int A[], int n)
{
    int min;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
            if (A[j] < A[min])
                min = j;
        if (min != i)
            swap(A[i], A[min]);
    }
}

void display(int array[], int len)
{  
    int lenmax = 0, lenght=0,to,from;
    int m = len;
    int b[100],j=0;
    cout << endl;
    cout << "Mang sau khi duoc sap xep tang dan: \n";
    for (int i = 0; i < len; i++)
        cout << array[i] << " | ";
    cout << endl;
    for (int i = 0; i < len;i++)
    {
        if (array[i] != array[i + 1])
        {
            b[j++] = array[i];
            
        }
        else
            m = m - 1;
    }
    for (int i = 0; i < m;i++)
    {
        cout << b[i] << " | ";
    }
    for (int i = 0; i < m; i++)
    {
        
            if (b[i + 1] == b[i] + 1)
            lenght = lenght + 1;
            if (b[i + 1] != (b[i] + 1))
            {
                if (lenght  > lenmax)
                {
                lenmax = lenght ;
                lenght = 0;
                to = i;
                }
            }
        
    }
   from = to - lenmax;
   cout <<"Do dai chuoi con dai nhat: " << lenmax <<endl;
   cout << "Day con tang dai nhat:" << endl;
    for (int i = from; i <= to;i++)
    {
        cout << b[i] << " | ";
    }
    cout << endl;
    system("pause");
}

int main()
{
    int key;
    //int a[22]= { 14, 1, 17, 2, 16, 17, 3, 15, 4, 1, 5, 18, 13, 6, 7, 19, 8, 12, 1, 9, 10, 8 };
   int a[100];
    int n;
    cout << "Nhap so phan tu trong mang: ";
    cin >> n;
    for (int i = 0; i < n; i++) 
    {
        cout << "Nhap vao phan tu a[" << i << "] : ";
        cin >> a[i];
    }
    SelectionSort(a, n);
    display(a, n);
    
    return 0;
}

