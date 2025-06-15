#include <bits/stdc++.h>
using namespace std;

class MyStack
{
private:
    int *arr;
    int top;
    int maxSize;

public:
    MyStack()
    {
        top = -1;
        maxSize = 100;
        arr = new int[maxSize];
    }

    MyStack(int maxSize)
    {
        top = -1;
        maxSize = maxSize;
        arr = new int[maxSize];
    }

    void push(int val)
    {
        if (top == maxSize - 1)
        {
            cout << "Overflow";
            return;
        }

        top++;
        arr[top] = val;
    }

    int pop()
    {
        if (top == -1)
        {
            cout << "Underflow";
            return;
        }

        int val = arr[top];
        top--;

        return val;
    }

    int top()
    {
        if (top == -1)
        {
            cout << "Stack is empty";
            return;
        }

        return arr[top];
    }

    int size()
    {
        return top + 1;
    }

    bool empty()
    {
        return top == -1;
    }
};