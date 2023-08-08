#include <bits/stdc++.h>
using namespace std;

ListNode *detectCycle(ListNode *head)
{
    ListNode *slow = head, *fast = head, *entry = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast=fast->next->next;
        if(slow==fast){
            while(entry!=slow){
                entry=entry->next;
                slow=slow->next;
            }
            return entry;
        }
    }
    return NULL;
}

int main()
{

    return 0;
}