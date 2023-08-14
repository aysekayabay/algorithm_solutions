#include <iostream>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return false;
        }

        ListNode *tort, *hare;
        tort = head;
        hare = head->next;

        while (hare != nullptr)
        {

            if (tort == hare)
            {
                return true;
            }
            hare = hare->next;
            if (hare != nullptr)
            {
                hare = hare->next;
            }
            tort = tort->next;
        }
        return false;
    }
};