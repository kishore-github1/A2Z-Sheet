#include <bits/stdc++.h>
using namespace std;

ListNode *reverseList(ListNode *head)
{
    ListNode *newhead = null, next;
    while (head != null)
    {
        next = head->next;
        head->next = newhead;
        newhead = head;
        head = next;
    }
    return head;
}

int main()
{

    return 0;
}