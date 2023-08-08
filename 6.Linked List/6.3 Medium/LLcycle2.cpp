#include <bits/stdc++.h>
using namespace std;

ListNode *detectCycle(ListNode *head)
{
    unordered_set<ListNode*> m;
    while (head != NULL)
    {
        if (m.find(head) != m.end())
            return head;
        m.insert(head);
        head = head->next;
    }
    return NULL;
}

int main()
{

    return 0;
}