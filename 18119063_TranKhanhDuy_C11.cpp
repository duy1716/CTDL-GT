#include <iostream>
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

void BubbleSort(int A[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (A[j] > A[j + 1])
                swap(A[j], A[j + 1]); 
}

void InsertionSort(int A[], int n)
{
    int pos, x;
    for (int i = 1; i < n; i++)
    {
        x = A[i]; 
        pos = i - 1;
        while (pos >= 0 && A[pos] > x)
        {
            
            A[pos + 1] = A[pos];
            pos--;
        }
       
        A[pos + 1] = x;
    }
}

void Merge(int A[], int left, int mid, int right)
{
    int n1 = mid - left + 1; 
    int n2 = right - mid; 


    int* LeftArr = new int[n1];
    int* RightArr = new int[n2];

 
    for (int i = 0; i < n1; i++)
        LeftArr[i] = A[left + i];
    for (int i = 0; i < n2; i++)
        RightArr[i] = A[mid + 1 + i];


    int i = 0, j = 0, current = left;


    while (i < n1 && j < n2)
        if (LeftArr[i] <= RightArr[j])
            A[current++] = LeftArr[i++];
        else
            A[current++] = RightArr[j++];


    while (i < n1)
    A[current++] = LeftArr[i++];

    //j chay tu gia tri truoc do no dung
    while (j < n2)//sao nhung gia tri tu j den n2
    A[current++] = RightArr[j++];
    delete[] LeftArr, RightArr;
}


void _MergeSort(int A[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        _MergeSort(A, left, mid);
        _MergeSort(A, mid + 1, right);
        Merge(A, left, mid, right);
    }
}

void MergeSort(int A[], int n)
{
    _MergeSort(A, 0, n - 1);
}

void Partition(int A[], int left, int right)
{
    if (left >= right)
        return;

    int pivot = A[(left + right) / 2]; 
    int i = left, j = right;
    while (i < j)
    {
        while (A[i] < pivot) 
            i++;
        while (A[j] > pivot) 
            j--;

        if (i <= j)
        {
            if (i < j) 
                swap(A[i], A[j]); 
            i++;
            j--;
        }
    }
    Partition(A, left, j);
    Partition(A, i, right);
}

void QuickSort(int A[], int n)
{
    Partition(A, 0, n - 1);
}

void convertHeap(int array[], int len, int x)
{
    int largest = x;
    int left = 2 * x + 1;
    int right = 2 * x + 2;

    if (left < len && array[left] > array[largest])
        largest = left;

    if (right < len && array[right] > array[largest])
        largest = right;

    if (largest != x)
    {
        swap(array[x], array[largest]);

        convertHeap(array, len, largest);
    }
}

void heapSort(int array[], int len)
{
    for (int i = len / 2 - 1; i >= 0; i--)
        convertHeap(array, len, i);

    for (int i = len - 1; i >= 0; i--)
    {
        swap(array[0], array[i]);
        convertHeap(array, i, 0);
    }
}

void display(int array[], int len)
{
    cout << endl;
    cout << "Mang sau khi duoc sap xep tang dan: \n";
    for (int i = 0; i < len; i++)
        cout << array[i] << " | ";
    cout << endl;
    cout << "Mang sau khi duoc sap xep giam dan: \n";
    for (int i = len-1; i >= 0; i--)
        cout << array[i] << " | ";
    cout << endl;
    system("pause");
}

int main()
{
    int key;
    int a[100];
    int n;
    cout << "Nhap so phan tu trong mang: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Nhap vao phan tu a[" << i << "] : ";
        cin >> a[i];
    }
    while (true) {
        system("cls");
        cout << "1. Insertion Sort.\n";
        cout << "2. Selection Sort.\n";
        cout << "3. Bubble Sort.\n";
        cout << "4. Merge Sort.\n";
        cout << "5. Quick Sort.\n";
        cout << "6. Heap Sort.\n";
        cout << "0. Exit\n";
        cout << "Nhap tuy chon: ";
        cin >> key;
        switch (key) {
        case 1:
            InsertionSort(a, n);
            display(a, n);
            break;
        case 2:
            SelectionSort(a, n);
            display(a, n);
            break;
        case 3:
            BubbleSort(a, n);
            display(a, n);
            break;
        case 4:
            MergeSort(a, n);
            display(a, n);
            break;
        case 5:
            QuickSort(a, n);
            display(a, n);
            break;
        case 6:
            heapSort(a, n);
            display(a, n);
            break;
        case 0:
            cout << "\nExit Program";
            return 0;
        }
    }
    return 0;
}
