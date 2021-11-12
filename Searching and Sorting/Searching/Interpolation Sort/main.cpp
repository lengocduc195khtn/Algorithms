#include <iostream>
using namespace std;

int interpolationSearch(int *arr, int x, int low, int high)
{
    double pos;
    int posX;

    while ((low <= high) && (arr[low] <= x) && (arr[high] >= x))
    {
        if (high == low)
        {
            if (arr[low] == x)
                return low;
            return -1;
        }
        posX = (x - arr[low]) * (double)(high - low) / (arr[high] - arr[low]) + low;

        if (arr[posX] == x)
            return posX;
        else if (arr[posX] < x)
            low = posX + 1;
        else
            high = posX - 1;
    }
    return -1;
}

int main()
{
    int n = 15;
    int *arr = new int[n]{10, 12, 13, 16, 18, 19, 20, 21,
                          22, 23, 24, 33, 35, 42, 47};
    cout << interpolationSearch(arr, 17, 0, 14);
    return 0;
}