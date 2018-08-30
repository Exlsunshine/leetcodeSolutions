#include <stdio.h>
#include <iostream>

using namespace std;

/*
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *head = new ListNode(1);
        ListNode *result = head;
        int carryIn = 0;
        while (l1 != NULL && l2 != NULL)
        {
            int val = (l1->val + l2->val + carryIn) % 10;
            carryIn = (l1->val + l2->val + carryIn) / 10;

            head->next = new ListNode(val);
            head = head->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1 != NULL)
        {
            int val = (l1->val + carryIn) % 10;
            carryIn = (l1->val + carryIn) / 10;

            head->next = new ListNode(val);
            head = head->next;
            l1 = l1->next;
        }

        while (l2 != NULL)
        {
            int val = (l2->val + carryIn) % 10;
            carryIn = (l2->val + carryIn) / 10;

            head->next = new ListNode(val);
            head = head->next;
            l2 = l2->next;
        }

        if (carryIn > 0)
            head->next = new ListNode(carryIn);

        return result->next;
    }
};

int main(int argc, char const *argv[])
{
    ListNode *l1 = new ListNode(2);
    ListNode *l2 = new ListNode(4);
    l1->next = l2;
    ListNode *l3 = new ListNode(3);
    l2->next = l3;

    ListNode *r1 = new ListNode(5);
    ListNode *r2 = new ListNode(6);
    r1->next = r2;
    ListNode *r3 = new ListNode(9);
    r2->next = r3;

    Solution s;
    ListNode *sum = s.addTwoNumbers(l1, r1);

    while (sum != NULL)
    {
        cout << sum->val << " ";
        sum = sum->next;
    }

    return 0;
}
