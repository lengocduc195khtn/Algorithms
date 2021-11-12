#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void partition(int *arr, int low, int high, int &i, int &j)
{
    if (high - low <= 1)
    {
        if (arr[high] < arr[low])
            swap(&arr[low], &arr[high]);

        i = low;
        j = high;
        return;
    }
    int pilot = arr[high];
    int mid = low;
    while (mid <= high)
    {
        if (arr[mid] < pilot)
            swap(&arr[low++], &arr[mid++]);
        else if (arr[mid] == pilot)
            mid++;
        else
            swap(&arr[mid], &arr[high--]);
    }

    i = low - 1;
    j = mid;
}

void quickSort3Way(int *arr, int low, int high)
{
    if (low >= high)
        return;
    int i, j;
    partition(arr, low, high, i, j);
    cout << "low" << low << " high " << high << endl;
    cout << i << " " << j << endl;
    for (int k = 0; k < 9; k++)
        cout << arr[k] << " ";
    cout << endl;
    cout << "left " << endl;
    quickSort3Way(arr, low, i);
    cout << "right" << endl;
    quickSort3Way(arr, j, high);
    cout << "out" << endl;
}

int main()
{
    int n = 9;
    int *arr = new int[n]{4, 9, 1, 3, 5, 9, 4, 2, 3};
    quickSort3Way(arr, 0, n - 1);

    return 0;
}