#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeList(ListNode *l1, ListNode *l2)
{
    
}

ListNode *sortList(ListNode *head)
{
    if (!head || !head->next)
        return head;

    ListNode *slow = head, *fast = head, *temp = NULL;
    while (fast && fast->next)
    {
        temp = slow;
        slow = slow->next, fast = fast->next->next;
    }
    temp->next = NULL;

    ListNode *l1 = sortList(head);
    ListNode *l2 = sortList(slow);

    return mergeList(l1, l2);
}

int main()
{

    return 0;
}