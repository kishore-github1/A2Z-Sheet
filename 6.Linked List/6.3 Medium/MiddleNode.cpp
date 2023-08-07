#include <bits/stdc++.h>
using namespace std;

ListNode *middleNode(ListNode *head)
{
    ListNode *slow = head, *fast = head;

    while (fast->next && fast)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;

}
int main()
{

    return 0;
}