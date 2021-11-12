#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition_high(int *arr, int low, int high)
{
    int pilot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
        if (arr[j] < pilot)
        {
            i++;
            swap(&arr[j], &arr[i]);
        }
    swap(&arr[high], &arr[i + 1]);
    return i + 1;
}

void quickSort(int *arr, int low, int high)
{
    if (low < high)
    {
        int pilot = partition_high(arr, low, high);

        quickSort(arr, low, pilot - 1);
        quickSort(arr, pilot + 1, high);
    }
}

int main()
{
    int n = 8;
    int *arr = new int[n]{100, 10, 80, 30, 90, 40, 50, 70};
    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}