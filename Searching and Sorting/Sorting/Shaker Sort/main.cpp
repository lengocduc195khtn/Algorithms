#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void shakerSort(int *arr, int n)
{
    int left = 0;
    int right = n - 1;
    int k;

    while (left < right)
    {
        for (int i = right; i > left; i--)
            if (arr[i] < arr[i - 1])
            {
                k = i;
                swap(&arr[i], &arr[i - 1]);
            }

        left = k;

        for (int i = left; i <= right; i++)
            if (arr[i] < arr[i - 1])
            {
                k = i - 1;
                swap(&arr[i], &arr[i - 1]);
            }

        right = k;
    }
}

int main()
{
    int n = 5;
    int *arr = new int[n]{2, 4, 6, 10, 8};
    shakerSort(arr, n);

    return 0;
}