#include <iostream>
using namespace std;

#define MAX 1000
bool has[MAX + 1][2];

void insert(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            has[abs(arr[i])][1] = 1;
        }
        else
            has[arr[i]][0] = 1;
    }
}

bool search(int X)
{
    if (X >= 0)
    {
        if (has[X][0] == 1)
            return 1;
        else
            return 0;
    }

    X = abs(X);

    if (has[X][1] == 1)
        return 1;
    else
        return 0;
}

int main()
{
    int n = 6;
    int *a = new int[n]{-1, 9, -5, -8, -5, -2};

    insert(a, n);

    int X = -5;

    if (search(X))
    {
        cout << "Present";
    }
    else
        cout << "Not present";
    return 0;
}