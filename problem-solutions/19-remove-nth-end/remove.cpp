#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val{}, next{nullptr} {}
    ListNode(int x) : val{x}, next{nullptr} {}
    ListNode(int x, ListNode *next) : val{x}, next{next} {}
};

ListNode *removeNthFromEnd1(ListNode *head, int n)
{
    int sz = 0;
    ListNode *node = head, *deleteNode = nullptr;
    while (node)
        ++sz, node = node->next;

    if (sz == n)
    {
        deleteNode = node;
        head = head->next;
        delete deleteNode;
        return head;
    }

    node = head;
    sz = sz - n - 1;
    for (int i = 0; i < sz; ++i)
        node = node->next;

    deleteNode = node->next;
    node->next = deleteNode->next;
    delete deleteNode;
    return head;
}

ListNode *removeNthFromEnd2(ListNode *head, int n)
{
    ListNode *first = head, *second = head, *deleteNode = nullptr;
    for (int i = 0; i < n; ++i)
        first = first->next;
    if (!first)
    {
        deleteNode = head;
        head = head->next;
        delete deleteNode;
        return head;
    }

    while (first->next)
    {
        first = first->next;
        second = second->next;
    }

    deleteNode = second->next;
    second->next = deleteNode->next;
    delete deleteNode;
    return head;
}

int main()
{

    std::cout << std::endl;
    return 0;
}