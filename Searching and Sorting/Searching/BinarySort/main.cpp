#include <iostream>
using namespace std;

int binarySearchRecursive(int *arr, int low, int high, int n)
{
    if (low <= high)
    {
        int pilot = (high + low) / 2;

        if (arr[pilot] == n)
            return pilot;

        if (arr[pilot] < n)
            return binarySearchRecursive(arr, pilot + 1, high, n);

        return binarySearchRecursive(arr, low, pilot - 1, n);
    }
    return -1;
}

int binarySearch(int *arr, int low, int high, int x)
{
    int mid;
    while (low < high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid;
    }
    return -1;
}

int main()
{
    int n = 5;
    int *arr = new int[n]{2, 3, 4, 10, 40};
    int res = binarySearch(arr, 0, 4, 10);
    cout << res;
    return 0;
}