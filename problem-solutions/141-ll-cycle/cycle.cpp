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
    static bool hasCycle(ListNode *head)
    {
        if (!head)
            return false;
        if (head->next == nullptr)
            return false;

        ListNode *fast = head->next, *slow = head;
        while (fast)
        {
            if (fast == slow)
                return true;
            fast = fast->next;
            if (!fast)
                return false;

            fast = fast->next;
            slow = slow->next;
        }
        return false;
    }

    bool hasCycle()
    {
        if (!this->head)
            return false;
        if (this->head->next == nullptr)
            return false;

        ListNode *fast = this->head->next, *slow = this->head;
        while (fast)
        {
            if (fast == slow)
                return true;
            fast = fast->next;
            if (!fast)
                return false;

            fast = fast->next;
            slow = slow->next;
        }
        return false;
    }
};

int main()
{
    LinkedList li{};
    for (int i = 10; i < 100; ++i)
        li.insert(i);
    li.print();

    std::cout << std::boolalpha << "li has cycle: " << li.hasCycle() << std::endl;

    std::cout << std::endl;
    return 0;
}