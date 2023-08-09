#include <bits/stdc++.h>
using namespace std;

ListNode *deleteMiddle(ListNode *head)
{
    ListNode *start = new ListNode(0);
    start->next = head;
    ListNode *ultraSlow = start, *slow = head, *fast = head;
    while (fast && fast->next)
    {
        ultraSlow = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    ultraSlow->next = ultraSlow->next->next;
    return start->next;
}

int main()
{

    return 0;
}