#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
  public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;

        ListNode *head = new ListNode(0);
        ListNode *h1 = l1, *h2 = l2, *h = head;
        while (h1 != NULL && h2 != NULL)
        {
            if (h1->val < h2->val)
            {
                head->next = h1;
                head = head->next;
                h1 = h1->next;
            }
            else
            {
                head->next = h2;
                head = head->next;
                h2 = h2->next;
            }
        }

        while (h1 != NULL)
        {
            head->next = h1;
            head = head->next;
            h1 = h1->next;
        }

        while (h2 != NULL)
        {
            head->next = h2;
            head = head->next;
            h2 = h2->next;
        }

        return h->next;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}
