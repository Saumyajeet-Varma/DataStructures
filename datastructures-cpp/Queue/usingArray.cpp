#include <bits/stdc++.h>
using namespace std;

class MyQueue
{
private:
    int *arr;
    int start;
    int end;
    int currSize;
    int maxSize;

public:
    MyQueue()
    {
        start = -1;
        end = -1;
        currSize = 0;
        maxSize = 100;
        arr = new int[maxSize];
    }

    MyQueue(int maxSize)
    {
        start = -1;
        end = -1;
        currSize = 0;
        maxSize = maxSize;
        arr = new int[maxSize];
    }

    void push(int val)
    {
        if (currSize == maxSize)
        {
            cout << "Overflow";
            return;
        }

        if (end == -1)
        {
            start = 0;
            end = 0;
        }
        else
        {
            end = (end + 1) % maxSize;
        }

        arr[end] = val;
        currSize++;
    }

    int pop()
    {
        if (start == -1)
        {
            cout << "Underflow";
            return;
        }

        int val = arr[start];

        if (currSize == 1)
        {
            start = -1;
            end = -1;
        }
        else
        {
            start = (start + 1) % maxSize;
        }

        currSize--;

        return val;
    }

    int front()
    {
        if (start == -1)
        {
            cout << "Queue is Empty";
            return;
        }

        return arr[start];
    }

    int size()
    {
        return currSize;
    }

    bool empty()
    {
        return currSize == 0;
    }
};