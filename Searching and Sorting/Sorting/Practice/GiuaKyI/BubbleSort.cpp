#include <iostream>

using namespace std;

void swap(int *a, int *b)

{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int check = 0;
        int j = n - 1;
        while (j > i)
        {
            if (arr[j] < arr[j - 1])
            {
                check = 1;
                swap(&arr[j], &arr[j - 1]);
            }
            j--;
        }
        if (check == 0)
            break;
    }
}
int main()
{
    int n = 9;
    int *arr = new int[n]{1, 5, 73, 8, 7, 83, 4, 5, 7};
    bubbleSort(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}