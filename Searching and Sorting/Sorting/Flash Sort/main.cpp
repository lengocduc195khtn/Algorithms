#include <iostream>
using namespace std;
void minMaxElement(int *arr, int n, int &min, int &max)
{
    min = arr[0];
    max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (min > arr[i])
            min = arr[i];
        if (max < arr[i])
            max = arr[i];
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void flashSort(int *arr, int n)
{
    int m = 0.43 * n;
    int *L = new int[m + 1]{0};
    int k;
    int min, max;
    L[1] = -1;
    minMaxElement(arr, n, min, max);

    // ** Xác định các phân lớp
    for (int i = 0; i < n; i++)
    {
        k = (m - 1) * (arr[i] - min) / (max - min) + 1;
        L[k]++;
    }

    for (int i = 2; i <= m; i++)
        L[i] += L[i - 1];

    // ** Phân hoạch các phân lớp

    int x;
    int count = 0;
    int i = 0;
    k = m;

    while (count < n)
    {

        if (i > L[k])
        {
            i++;
            k = (m - 1) * (arr[i] - min) / (max - min) + 1;
        }
        x = arr[i];

        // ** ** Xử lí một chu trình hoán vị

        while (i <= L[k])
        {
            k = (m - 1) * (x - min) / (max - min) + 1;
            int y = arr[L[k]];
            arr[L[k]] = x;
            L[k]--;
            x = y;
            count++;
        }
    }

    // ** Sắp xếp các phần tử trong từng phân lớp
    int key;
    for (int k = 2; k <= m; k++)
    {
        for (int i = L[k] - 1; i > L[k - 1]; i--)
        {
            if (arr[i] > arr[i + 1])
            {
                int temp = arr[i];
                int j = i;
                while (arr[j + 1] < temp)
                {
                    arr[j] = arr[j + 1];
                    j++;
                }
                arr[j] = temp;
            }
        }
    }
}

// ** Các phương pháp sắp xếp cấp cao : HeapSort, QuickSort, MergeSort chỉ thích hợp với dữ liệu lớn
// ** Với dữ liệu nhỏ của từng phân vùng thì nên sử dụng phương pháp sắp xếp cơ bản : InsertSort

int main()
{
    int n = 44;
    int *arr = new int[n]{4, 67, 2, 789, 54, 37, 4, 67, 2, 789,
                          54, 37, 456, 12, 456, 27, 123, 10, 456, 12,
                          456, 27, 123, 10, 4, 67, 2, 789, 54, 37,
                          456, 12, 456, 27, 123, 10, 24, 26, 45, 12,
                          57, 59, 42, 35};

    flashSort(arr, n);
    cout << "ARRAY : ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}