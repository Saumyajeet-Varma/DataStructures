#include <bits/stdc++.h>
using namespace std;

class Stack
{
private:
    queue<int> que;

public:
    void push(int val)
    {
        int n = que.size();

        que.push(val);

        for (int i = 0; i < n; i++)
        {
            int queVal = que.front();
            que.push(queVal);
            que.pop();
        }
    }

    int pop()
    {
        int val = que.front();
        que.pop();

        return val;
    }

    int top()
    {
        return que.front();
    }

    int size()
    {
        return que.size();
    }

    bool empty()
    {
        return que.empty();
    }
};