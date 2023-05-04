#include <iostream>

using namespace std;

class MyStack
{
private:
    class StackNode
    {
    public:
        StackNode *next, *prev;
        int val;
        StackNode() = default;
        StackNode(int val) : next{}, prev{}, val{val} {}
        ~StackNode() = default;
    };
    StackNode *first, *last;

public:
    MyStack() = default;

    void push(int x)
    {
        StackNode *newNode = new StackNode{x};
        newNode->prev = last;
        if (!first)
        {
            first = last = newNode;
            return;
        }

        last->next = newNode;
        last = last->next;
    }

    int pop()
    {
        if (this->empty())
            return -1;

        StackNode *deleteNode;
        int val;

        deleteNode = last;
        last = last->prev;
        if (!last)
            first = last;
        else
            last->next = nullptr;

        val = deleteNode->val;
        delete deleteNode;
        return val;
    }

    int top()
    {
        if (!last)
            return -1;
        return last->val;
    }

    bool empty()
    {
        return first == last && first == nullptr;
    }
};