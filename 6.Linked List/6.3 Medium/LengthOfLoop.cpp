#include <bits/stdc++.h>
using namespace std;

int lengthOfLoop(Node *head)
{
    if (!head || !head->next)
        return 0;
    Node *slow = head, *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            int count = 1;
            slow = slow->next;
            while (slow != fast)
            {
                slow = slow->next;
                count++;
            }
            return count;
        }
    }
    return 0;
}

int main()
{

    return 0;
}