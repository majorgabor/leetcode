#include <cmath>
#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    int over = 0, sum = 0;
    ListNode *node = new ListNode();
    ListNode *head = node;
    for (;;)
    {
        sum = over;
        if (l1)
        {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2)
        {
            sum += l2->val;
            l2 = l2->next;
        }
        node->val = sum % 10;
        over = std::floor(sum / 10);
        if (l1 || l2 || over > 0)
        {
            node->next = new ListNode();
            node = node->next;
        }
        else
        {
            break;
        }
    }
    return head;
}

std::ostream &operator<<(std::ostream &out, const ListNode *head)
{
    out << '[';    
    for (;;)
    {
        if (head->next)
        {
            out << head->val << ", ";
            head = head->next;
        }
        else
        {
            out << head->val << ']';
            break;   
        }
    }
    return out;
}

void deleteListNode(ListNode *head)
{
    if (head->next)
    {
        deleteListNode(head->next);
    }
    delete head;
}

int main()
{
    ListNode *l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode *l2 = new ListNode(5, new ListNode(6, new ListNode(4)));
    ListNode *result = addTwoNumbers(l1, l2);
    std::cout << "l1: " << l1 << " l2: " << l2 << " -> output: " << result << std::endl;
    deleteListNode(l1);
    deleteListNode(l2);
    deleteListNode(result);

    l1 = new ListNode(0);
    l2 = new ListNode(0);
    result = addTwoNumbers(l1, l2);
    std::cout << "l1: " << l1 << " l2: " << l2 << " -> output: " << result << std::endl;
    deleteListNode(l1);
    deleteListNode(l2);
    deleteListNode(result);

    l1 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9)))))));
    l2 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9))));
    result = addTwoNumbers(l1, l2);
    std::cout << "l1: " << l1 << " l2: " << l2 << " -> output: " << result << std::endl;
    deleteListNode(l1);
    deleteListNode(l2);
    deleteListNode(result);
}