#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void split(Node *headRef, Node **backRef)
{
    Node *fast = headRef->next;
    Node *slow = headRef;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }

    *backRef = slow->next;
    slow->next = NULL;
    slow = slow->next;
    delete fast, slow;
}

Node *merge(Node *a, Node *b)
{
    if (a == NULL)
        return (b);
    if (b == NULL)
        return (a);

    Node *result = NULL;

    if (a->data >= b->data)
    {
        result = b;
        result->next = merge(a, b->next);
    }
    else
    {
        result = a;
        result->next = merge(a->next, b);
    }

    return result;
}

void mergeSort(Node **headRef)
{

    if (*headRef == NULL || (*headRef)->next == NULL)
        return;

    Node *b;

    split(*headRef, &b);
    mergeSort(headRef);
    mergeSort(&b);
    *headRef = merge(*headRef, b);

    while (b != NULL)
        b = b->next;
    delete b;
}

void push(Node **head, int data)
{
    Node *p = new Node;
    p->data = data;
    p->next = *head;
    *head = p;
}

void print(Node *head)
{
    Node *p = head;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
    delete p;
}

int main()
{
    Node *head = NULL;
    push(&head, 45);
    push(&head, 5);
    push(&head, 75);
    push(&head, 41);
    push(&head, 24);
    push(&head, 81);
    push(&head, 3);
    push(&head, 64);
    print(head);
    mergeSort(&head);
    print(head);
    return 0;
}