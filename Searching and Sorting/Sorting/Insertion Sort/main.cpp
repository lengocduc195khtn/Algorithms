#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertionSort_Array(int *arr, int n)
{
    int key;
    int j;

    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while ((j >= 0) && (arr[j] > key))
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

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

struct LinkedList
{
public:
    Node *head;
    Node *sorted;
};

Node *convert(int *arr, int n)
{
    Node *head = createNode(arr[0]);

    for (int i = 1; i < n; i++)
        head->next = createNode(arr[i]);

    return head;
}

void insertionSort_LinkedList(Node *head)
{
}

int main()
{
    int n = 8;
    int *arr = new int[n]{4, 3, 2, 10, 12, 1, 5, 6};

    Node *head = convert(arr, n);

    insertionSort_LinkedList(head);

    return 0;
}