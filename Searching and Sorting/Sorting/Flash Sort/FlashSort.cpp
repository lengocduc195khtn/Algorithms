#include <iostream>
#include <time.h>
#include <cstring>
using namespace std;

void FlashSort(int a[], int n)
{
    int m = (int)(0.43 * n);
    int *L = new int[m + 1];
    memset(L, 0, (m + 1) * 4);
    int k;
    int min = a[1];
    int max = a[1];
    for (int i = 1; i <= n; i++)
    {
        if (a[i] < min)
        {
            min = a[i];
        }
        else if (a[i] > max)
        {
            max = a[i];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        k = (m - 1) * (a[i] - min) / (max - min) + 1;
        L[k]++;
    }
    for (int i = 2; i <= m; i++)
    {
        L[i] += L[i - 1];
    }
    int i = 1;
    int x;
    int count = 0;
    k = n;
    while (count < n)
    {
        if (i > L[k])
        {
            i++;
            k = (m - 1) * (a[i] - min) / (max - min) + 1;
        }
        x = a[i];
        while (i <= L[k])
        {
            k = (m - 1) * (x - min) / (max - min) + 1;
            int temp = a[L[k]];
            a[L[k]] = x;
            x = temp;
            L[k]--;
        }
        count++;
    }
    for (int k = 2; k <= m; k++)
    {
        for (int i = L[k] - 1; i > L[k - 1]; i--)
        {
            if (a[i] > a[i + 1])
            {
                int temp = a[i];
                int j = i;
                while (temp > a[j + 1])
                {
                    a[j] = a[j + 1];
                    j++;
                }
                a[j] = temp;
            }
        }
    }
}
int main()
{
    int a[100];
    srand(time(0));

    for (int i = 1; i <= 50; i++)
    {
        a[i] = rand() % 50;
        cout << a[i] << " ";
    }

    cout << endl;
    FlashSort(a, 50);
    for (int i = 1; i <= 50; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}