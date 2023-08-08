#include <bits/stdc++.h>
using namespace std;

bool hasCycle(ListNode *head)
{
    ListNode *slow = head,*fast = head;

    while(fast && fast->next){
        slow=slow->next,
        fast=fast->next->next;
        if(fast==slow) return true;
    }
    return false;   
}

int main()
{

    return 0;
}