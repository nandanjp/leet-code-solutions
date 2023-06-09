#include <iostream>
#include <iomanip>

using namespace std;

class LinkedList
{
private:
    struct ListNode
    {
        ListNode *next;
        int val;

        ListNode() = default;
        ListNode(int val) : next{}, val{val} {}
        ~ListNode() = default;
    };

    ListNode *head;

public:
    LinkedList() : head{} {}
    LinkedList(int val) : head{new ListNode{val}} {}
    ~LinkedList()
    {
        ListNode *curr = this->head, *prev;
        while (curr)
        {
            prev = curr;
            curr = curr->next;
            delete prev;
        }
    }

    void insert(int val)
    {
        ListNode *newNode = new ListNode{val};
        if (!this->head)
        {
            this->head = newNode;
            return;
        }

        ListNode *curr = this->head;
        while (curr->next)
            curr = curr->next;
        curr->next = newNode;
    }
    void print() const
    {
        ListNode *curr = this->head;
        std::cout << "[";
        while (curr)
        {
            std::cout << curr->val << (curr->next ? ", " : "");
            curr = curr->next;
        }
        std::cout << "]" << std::endl;
    }

    ListNode *getIntersectionNode(const LinkedList &other)
    {
        int m = 0, n = 0;

        ListNode *curr = this->head;
        while (curr)
            ++m, curr = curr->next;

        curr = other.head;
        while (curr)
            ++n, curr = curr->next;

        ListNode *headA = this->head, *headB = other.head;
        for (int i = 0; i < (m - n); ++i)
            headA = headA->next;
        for (int i = 0; i < (n - m); ++i)
            headB = headB->next;

        while (headA && headB)
        {
            if (headA == headB)
                return headA;

            headA = headA->next;
            headB = headB->next;
        }
        return nullptr;
    }
};

int main()
{
    LinkedList li{};
    for (int i = 10; i < 100; ++i)
        li.insert(i);
    li.print();

    std::cout << std::endl;
    return 0;
}