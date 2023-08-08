#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(ListNode *head)
{
    ListNode *slow = head, *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    if (fast)
        slow = slow->next;
    ListNode *temp = slow, *next, *newhead = NULL;

    while (temp != NULL)
    {
        next = temp->next;
        temp->next = newhead;
        newhead = temp;
        temp = next;
    }
    while (newhead)
    {
        if (head->val !=newhead->val)
            return false;
        head = head->next;
        newhead = newhead->next;
    }
    return true;
}

int main()
{

    return 0;
}