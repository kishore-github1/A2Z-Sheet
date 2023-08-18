#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};
void printLinkedList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node *Reverse(Node *head)
{
    Node *newhead = NULL, *next;
    while (head != NULL)
    {
        next = head->next;
        head->next = newhead;
        newhead = head;
        head = next;
    }
    return newhead;
}

Node *addOne(Node *head)
{

    head = Reverse(head);
    int carry = 1;

    Node *temp;
    Node *ans = head;
    int sum = 0;
    while (head != NULL)
    {
        sum = head->data + carry;
        carry = sum == 10 ? 1 : 0;
        sum %= 10;
        head->data = sum;
        temp = head;
        head = head->next;
    }
    if (carry != 0)
        temp->next = new Node(1);

    return Reverse(ans);
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    cout << "Original linked list: ";
    printLinkedList(head);

    Node *result = addOne(head);

    cout << "Linked list after adding one: ";
    printLinkedList(result);

    return 0;
}
