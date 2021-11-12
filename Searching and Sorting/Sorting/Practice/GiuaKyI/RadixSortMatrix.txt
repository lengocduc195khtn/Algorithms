#include <iostream>
using namespace std;

int digit(int n)
{
    int d = 0;
    while (n > 0)
    {
        n / 10;
        d++;
    }
    return d;
}

int maxElement(int *arr, int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (max < arr[i])
            max = arr[i];
    return max;
}

int radixSortMatrix(int *arr, int n)
{
    int **L = new int *[10];
    for (int i = 0; i < 10; i++)
        L[i] = new int[n];

    int *nElem = new int[10]{0};

    int max = maxElement(arr, n);

    for (int i = 1; i < max; i = i * 10)
    {
        for (int j = 0; j < n; j++)
        {
            int temp = (arr[j] / i) % 10;

            // Xét 35 thì temp = 5
            // L[5][nElemt[5]]=L[5][0] = arr[j] = 35
            L[temp][nElem[temp]] = arr[j];
            // nElemt[5]=1; -> Số phần tử đuôi 5 là 1
            nElem[temp]++;
        }

        for (int i = 0; i < 10; i++)
        {
            cout << "L " << i << " :";
            for (int j = nElem[i]; j > 0; j--)
                cout << L[i][j - 1] << " ";
            cout << endl;
        }

        int k = 0;

        for (int i = 0; i < 10; i++)
        {
            int j = 0;
            if (nElem[i] > 0)
            {
                while (j < nElem[i])
                {
                    arr[k] = L[i][j];
                    j++;
                    k++;
                }
                nElem[i] = 0;
            }
        }
    }

    for (int i = 0; i < 10; i++)
        delete[] L[i];
    delete[] nElem;
    delete[] L;
}

int main()
{
    int n = 6;
    int *arr = new int[n]{35, 412, 21, 5, 327, 82};
    radixSortMatrix(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}