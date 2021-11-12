#include <iostream>
using namespace std;

void merge(int *arr, int left, int mid, int right)
{
    int nArrayLeft = mid - left + 1;
    int nArrayRight = right - mid;

    int *arrayLeft = new int[nArrayLeft];
    int *arrayRight = new int[nArrayRight];

    for (int i = 0; i < nArrayLeft; i++)
        arrayLeft[i] = arr[left + i];
    for (int i = 0; i < nArrayRight; i++)
        arrayRight[i] = arr[mid + i + 1];

    int i = 0;
    int j = 0;
    int posArray = left;

    while (i < nArrayLeft && j < nArrayRight)
    {
        if (arrayLeft[i] > arrayRight[j])
            arr[posArray++] = arrayRight[j++];
        else
            arr[posArray++] = arrayLeft[i++];
    }
    while (i < nArrayLeft)
        arr[posArray++] = arrayLeft[i++];
    while (j < nArrayRight)
        arr[posArray++] = arrayRight[j++];

    delete arrayLeft;
    delete arrayRight;
}

void mergeSort(int *arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main()
{
    int n = 6;
    int *arr = new int[n]{12, 11, 9, 6, 5, 7};
    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}