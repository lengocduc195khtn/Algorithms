#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void push(Node *&head, int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = head;
    head = temp;
}

Node *pop(Node *&head)
{
    Node *p = head;
    head = p->next;
    p->next = NULL;
    return p;
}

void add(Node *&head, Node *p)
{
    if (head != NULL)
    {
        Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = p;
        temp = p->next;
        delete temp;
    }
    else
        head = p;
}

void radixSortMatrix(Node *arr, int n)
{
    Node **array = new Node *[10];
    for (int i = 0; i < 10; i++)
        array[i] = NULL;
    int *nElem = new int[10]{0};

    int d = 412;

    for (int i = 1; i < d; i = i * 10)
    {
        for (int j = 0; j < n; j++)
        {
            Node *p = pop(arr);
            add(array[(p->data / d) % 10], p);
            nElem[(p->data / d) % 10]++;
        }

        for (int j = 0; j < 10; j++)
        {
            if (nElem[j] != 0)
                add(arr, array[j]);
        }
    }
}

int main()
{
    Node *head = NULL;
    int n = 6;
    int *arr = new int[n]{35, 412, 21, 5, 327, 82};
    for (int i = 0; i < n; i++)
        push(head, arr[i]);
    radixSortMatrix(head, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}