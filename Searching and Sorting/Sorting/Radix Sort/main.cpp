#include <iostream>
#include <math.h>
using namespace std;

int maxElement(int *arr, int n)
{
    int max = 0;
    for (int i = 0; i < n; i++)
        if (max < arr[i])
            max = arr[i];
    return max;
}

int getDigits(int n, int pos)
{

    int temp = pow(10, pos - 1);
    temp = n / temp;
    return temp % 10;
}

// ** Least significant digits (LSD)
// ** Nên dùng danh sách liên kết
// ** d là số lượng số có số chữ số lớn nhất
// ** 335 72 498 12 99 115 thì d = 3

// ** Sử dụng sắp xếp đếm để hỗ trợ
void LSDcountSort_1(int *arr, int n, int pos)
{
    int *arrTemp = new int[n];
    int *arrCount = new int[10];
    int *arrRes = new int[n];

    for (int i = 0; i < 10; i++)
        arrCount[i] = 0;

    for (int i = 0; i < n; i++)
    {
        arrTemp[i] = getDigits(arr[i], pos);
    }

    for (int i = 0; i < n; i++)
        arrCount[arrTemp[i]]++;

    for (int i = 1; i < 10; i++)
        arrCount[i] += arrCount[i - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        //arrRes[--arrCount[arrTemp[i] - 0]] = arr[i];
        arrRes[arrCount[arrTemp[i] - 0] - 1] = arr[i];
        arrCount[arrTemp[i] - 0]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = arrRes[i];

    delete[] arrTemp;
    delete[] arrCount;
    delete[] arrRes;
}

void LSDRadixSort_countSort_1(int *arr, int n)
{
    int max = maxElement(arr, n);

    int d = 1;

    while (max > 0)
    {
        LSDcountSort_1(arr, n, d);
        max = max / 10;
        d++;
    }
}

void LSDcountSort_2(int *arr, int n, int pos)
{
    int *arrCount = new int[10]{0};
    int *arrRes = new int[n];

    for (int i = 0; i < n; i++)
        arrCount[(arr[i] / pos) % 10]++;

    for (int i = 1; i < 10; i++)
        arrCount[i] += arrCount[i - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        arrRes[arrCount[(arr[i] / pos) % 10] - 1] = arr[i];
        arrCount[(arr[i] / pos) % 10]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = arrRes[i];
}

void LSDRadixSort_countSort_2(int *arr, int n)
{
    int max = maxElement(arr, n);

    for (int i = 1; max / i > 0; i = i * 10)
        LSDcountSort_2(arr, n, i);
}

// ** Phương pháp sử dụng danh sách liên kết

struct Node
{
    int data;
    Node *next;
};

Node *createNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void insert(Node *&head, int n)
{
    if (head == NULL)
    {
        head = createNode(n);
        return;
    }

    Node *t = head;
    while (t->next != NULL)
        t = t->next;
    t->next = createNode(n);
}

int del(Node *&head)
{
    if (head == NULL)
        return 0;
    Node *temp = head;
    // storing the value of head before updating
    int val = head->data;

    // updation of head to next node
    head = head->next;
    temp->next = NULL;

    delete temp;
    return val;
}

int getnDigits(int n)
{
    int i = 0;
    while (n > 1)
    {
        n = n / 10;
        i++;
    }
    return i;
}

void linkedListSort(int *arr, int n)
{
    int max = maxElement(arr, n);
    cout << max << endl;

    int d = getnDigits(max);

    cout << d << endl;
    int k = 0;
    Node **bins = new Node *[10];

    for (int i = 0; i < 10; i++)
        bins[i] = NULL;
    while (k < d)
    {
        for (int j = 0; j < n; j++)
            insert(bins[(arr[j] / (int)pow(10, k)) % 10], arr[j]);

        int x = 0, y = 0;

        while (x < 10)
        {
            while (bins[x] != NULL)
            {
                arr[y++] = del(bins[x]);
            }
            x++;
        }
        k++;
    }
}

// ** Sắp xếp hoàn toàn bằng linked list từ dữ liệu linkedlist đầu vào

// ** Most significant digits (MSD)
// ** Nên chuyển sang bit nhị phân để xếp
// ** Hoặc sử dụng đệ qui mảng 0*** 1*** 2*** ....
// **                          00** 01** 02** ....
// ** Hoặc sử dụng bảng lô L[n][10] (cập nhật trên mảng ban đầu, không cấp phát thêm)
// ** Hoặc sử dụng linked list
// ** Học lập trình bit c++
int main()
{
    int n = 6;
    //335, 72, 498, 12, 99, 115
    int *arr = new int[n]{35, 312, 21, 5, 327, 82};
    linkedListSort(arr, n);
    cout << "ARRAY RES: " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}