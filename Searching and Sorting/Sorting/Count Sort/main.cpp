#include <iostream>
using namespace std;

bool min(int a, int b)
{
    return a > b;
}

bool max(int a, int b)
{
    return a < b;
}

int maxMinElement(int *arr, int n, bool (*maxMin)(int a, int b))
{
    int res = arr[0];
    for (int i = 1; i < n; i++)
        if (maxMin(res, arr[i]))
            res = arr[i];
    return res;
}

int *countSort(int *arr, int n)
{
    int minArr = maxMinElement(arr, n, min);
    int maxArr = maxMinElement(arr, n, max);

    int nRes = maxArr - minArr + 1;

    int *arrCount = new int[nRes];
    int *arrRes = new int[nRes];
    for (int i = 0; i < nRes; i++)
    {
        arrCount[i] = 0;
        arrRes[i] = 0;
    }

    for (int i = 0; i < n; i++)
        arrCount[arr[i] - minArr]++;

    for (int i = 1; i < nRes; i++)
        arrCount[i] += arrCount[i - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        arrRes[arrCount[arr[i] - minArr] - 1] = arr[i];
        arrCount[arr[i] - minArr]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = arrRes[i];

    delete[] arrCount;
    delete[] arrRes;

    return arr;
}

int main()
{
    int n = 7;
    //43, 5, 2, 7, 8, 3
    int *arr = new int[n]{1, 4, 1, 2, 7, 5, 2};
    arr = countSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}