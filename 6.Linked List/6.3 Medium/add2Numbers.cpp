#include <bits/stdc++.h>
using namespace std;

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    if (!l2)
        return l1;
    if (!l1)
        return l2;

    int carry = 0;
    ListNode *start = new ListNode();
    ListNode *temp = start;
    while (l1 != NULL || l2 != NULL || carry)
    {
        int sum = 0;
        if (l1 != NULL)
        {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2 != NULL)
        {
            sum += l2->val;
            l2 = l2->next;
        }

        sum += carry;

        carry = sum / 10;
        ListNode *newnode = new ListNode(sum % 10);
        temp->next = newnode;
        temp = temp->next;
    }
    return start->next;
}

int main()
{

    return 0;
}