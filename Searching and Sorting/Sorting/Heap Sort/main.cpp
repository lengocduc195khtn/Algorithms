// ** Độ phức tạp : n.log(n)
// ** Được tác giả sáng tạo ra cùng với cấu trúc Heap.
// ** Cách đưa ra vấn đề và giải quyết vấn đề thông minh.
// ** Tuy vậy do khá dài nên sinh viên cảm thấy khó khăn.

// ** Pros: Ưu thế vượt trội so với Selection sort

// ** Phân tích ý tưởng:
// ! Nhược điểm :
// ! Về không gian : 2n-1 đơn vị nhớ (bước xử lí)
// !                    + n (đơn vị lưu trữ kết quả sau khi sắp xếp).
// ! Càng về cuối, càng có nhiều những phép so sánh vô ích.
// ! Dễ tưỡng tượng, nhưng khó thực hiện.
// ?? Ưu điểm : n.log(n).

// ** Định nghĩa Heap:  Mảng một chiều n số h1, h2, h3,...
// **                   với h(i)<=h(2i+1) với i lẻ,
// **                   với h(i)<=h(2i+2) với i chẵn.
// **       Ví dụ :     2 5 4 6 8 9 7

// ** Xây dựng heap : Nào thế nào để biến đổi mảng arr bao đầu thành 1 heap?

#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// ** Sắp xếp trong heap nhỏ thứ pos
void sort(int *arr, int n, int pos)
{
    if ((2 * pos + 2 < n) && (arr[2 * pos + 1] > arr[2 * pos + 2]))
    {
        if (arr[pos] > arr[2 * pos + 2])
        {
            swap(&arr[pos], &arr[2 * pos + 2]);
            if (4 * pos + 5 < n)
                sort(arr, n, 2 * pos + 2);
        }
    }
    else
    {
        if (arr[pos] > arr[2 * pos + 1])
        {
            swap(&arr[pos], &arr[2 * pos + 1]);
            if (4 * pos + 3 < n)
                sort(arr, n, 2 * pos + 1);
        }
    }
}

int take(int *arr, int n)
{
    int temp = arr[0];
    arr[0] = INT_MAX;
    sort(arr, n, 0);
    return temp;
}

int *heapSort(int *arr, int n)
{
    int nHeap = (n) / 2 - 1;
    cout << nHeap << endl;
    int j;
    for (int i = nHeap; i >= 0; i--)
    {
        sort(arr, n, i);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    int *newArr = new int[n];
    for (int i = 0; i < n; i++)
    {
        newArr[i] = take(arr, n);
    }
    return newArr;
}

void sortAdvance(int *arr, int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if ((l < n) && (arr[largest] < arr[l]))
        largest = l;
    if ((r < n) && (arr[largest] < arr[r]))
        largest = r;

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        sortAdvance(arr, n, largest);
    }
}

void heapSortAdvance(int *arr, int n)
{
    for (int i = (n / 2) - 1; i >= 0; i--)
        sortAdvance(arr, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        swap(&arr[i], &arr[0]);
        sortAdvance(arr, i, 0);
    }
}

int main()
{
    int n = 8;
    int *arr = new int[n]{24, 4, 345, 21, 8, 2, 45, 1};
    heapSortAdvance(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}