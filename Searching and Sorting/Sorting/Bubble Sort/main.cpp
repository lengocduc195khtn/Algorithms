#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int *arr, int n)
{
    // ** Chi phí không gian O(0)
    // ** Chi phí thời gian O(n^2)
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
            if (arr[i] > arr[j])
                swap(&arr[i], &arr[j]);
    }
}

void improveBubbleSort(int *arr, int n)
{
    // ** Chi phí không gian O(0)
    // ** Chi phí thời gian O(n^2)
    for (int i = 0; i < n; i++)
    {
        bool check = true;
        for (int j = i; j < n; j++)
            if (arr[i] > arr[j])
            {
                swap(&arr[i], &arr[j]);
                check = false;
            }
        if (check == true)
            break;
    }
}

void recursiveBubbleSort(int *arr, int n)
{
    if (n == 1)
        return;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] == arr[i + 1])
            swap(arr[i], arr[i + 1]);
    }
    recursiveBubbleSort(arr, n - 1);
}

int main()
{
    int n = 5;
    int *arr = new int[n]{43, 2, 75, 52, 1};

    bubbleSort(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}