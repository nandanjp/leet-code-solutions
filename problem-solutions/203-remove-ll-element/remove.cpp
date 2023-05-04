#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val{}, next{} {}
    ListNode(int x) : val{x}, next{} {}
    ListNode(int x, ListNode *next) : val{x}, next{next} {}
};

ListNode *removeElements(ListNode *head, int val)
{
    ListNode *curr = head, *remove = nullptr;

    while (head && head->val == val)
    {
        remove = head;
        head = head->next;
        delete remove;
    }
    if (!head)
        return head;

    curr = head;
    while (curr && curr->next)
    {
        if (curr->next->val == val)
        {
            remove = curr->next;
            curr->next = curr->next->next;
            delete remove;
            continue;
        }
        curr = curr->next;
    }
    return head;
}

int main()
{

    std::cout << std::endl;
    return 0;
}