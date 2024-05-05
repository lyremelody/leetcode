#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *ln = new ListNode(0);
        ListNode *current = ln;
        int val(0);

        while (current != NULL)
        {
            if (l1 != NULL)
            {
                val += l1->val;
                l1 = l1->next;
            }

            if (l2 != NULL)
            {
                val += l2->val;
                l2 = l2->next;
            }

            current->val = val % 10;
            val = val / 10;

            if ((l1 != NULL) || (l2 != NULL) || (val > 0))
                current->next = new ListNode(val);

            current = current->next;
        }

        return ln;
    }
};

int main()
{
    ListNode *l1 = new ListNode[3];
    l1[0];
    ListNode *l2 = [ 5, 6, 4 ];
    Solution s;
    s.reverse(123);
    s.reverse(-123);
    return 0;
}
