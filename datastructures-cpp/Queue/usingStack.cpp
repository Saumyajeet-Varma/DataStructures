#include <bits/stdc++.h>
using namespace std;

class MyQueue1
{
private:
    stack<int> stk1;
    stack<int> stk2;

public:
    void push(int val)
    {
        while (!stk1.empty())
        {
            int stkVal = stk1.top();
            stk2.push(stkVal);
            stk1.pop();
        }

        stk1.push(val);

        while (!stk2.empty())
        {
            int stkVal = stk2.top();
            stk1.push(stkVal);
            stk2.pop();
        }
    }

    int pop()
    {
        if (stk1.empty())
        {
            cout << "Underflow";
            return;
        }

        int val = stk1.top();
        stk1.pop();

        return val;
    }

    int top()
    {
        return stk1.top();
    }

    int size()
    {
        return stk1.size();
    }

    int empty()
    {
        return stk1.empty();
    }
};

class MyQueue2
{
private:
    stack<int> stk1;
    stack<int> stk2;

public:
    void push(int val)
    {
        stk1.push(val);
    }

    int pop()
    {
        if (stk2.empty())
        {
            while (!stk1.empty())
            {
                int stkVal = stk1.top();
                stk1.pop();
                stk2.push(stkVal);
            }
        }

        int val = stk2.top();
        stk2.pop();

        return val;
    }

    int top()
    {
        if (stk2.empty())
        {
            while (!stk1.empty())
            {
                int stkVal = stk1.top();
                stk1.pop();
                stk2.push(stkVal);
            }
        }

        return stk2.top();
    }

    int size()
    {
        return stk1.size() + stk2.size();
    }

    bool empty()
    {
        return stk1.size() + stk2.size() == 0;
    }
};