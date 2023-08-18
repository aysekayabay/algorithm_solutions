
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    { // my solution
        int carry = 0;
        ListNode *head = new ListNode(0);
        ListNode *tmp = head;
        while (l1 != nullptr && l2 != nullptr)
        {
            int sum = l1->val + l2->val + carry;
            carry = sum / 10;
            ListNode *newNode = new ListNode(sum % 10);
            tmp->next = newNode;
            tmp = tmp->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1 != nullptr)
        {
            int sum = l1->val + carry;
            carry = sum / 10;
            ListNode *newNode = new ListNode(sum % 10);
            tmp->next = newNode;
            tmp = tmp->next;
            l1 = l1->next;
        }

        while (l2 != nullptr)
        {
            int sum = l2->val + carry;
            carry = sum / 10;
            ListNode *newNode = new ListNode(sum % 10);
            tmp->next = newNode;
            tmp = tmp->next;
            l2 = l2->next;
        }
        if (carry > 0)
        {
            ListNode *newNode = new ListNode(carry);
            tmp->next = newNode;
            tmp = tmp->next;
        }

        head = head->next;
        return head;
    }

    ListNode *addTwoNumbersV2(ListNode *l1, ListNode *l2) // loved this solution (recursion)
    {
        if (!l1)
        {
            if (l2)
                return l2; // Return the remaining digits
            return NULL;
        }

        if (l2)
            l1->val += l2->val; // Add the two digits

        if (l1->val >= 10) // Carry the one to the next digit
        {
            if (l1->next)
                l1->next->val++;
            else
            {
                l1->next = new ListNode(1);
            }
            l1->val -= 10;
        }
        if (l2) // Repeat the process for the remaining digits
            l1->next = addTwoNumbersV2(l1->next, l2->next);
        else
            l1->next = addTwoNumbersV2(l1->next, NULL);

        return l1;
    }
};