#include <bits/stdc++.h>
using namespace std;

ListNode *oddEvenList(ListNode *head)
{
    if(!head || !head->next) return head;
    
    ListNode *odd = head,*even = head->next,*evenhead=head->next;
    while (even && even->next){
        odd -> next = odd->next->next;
        even -> next = even->next->next;
        odd = odd->next;
        even = even ->next;
    }
    odd->next = evenhead;
    return head;
}

int main()
{

    return 0;
}