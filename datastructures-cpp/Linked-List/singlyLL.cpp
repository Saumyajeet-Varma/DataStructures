#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class InsertNode
{
public:
    ListNode *insertHead(ListNode *head, int val)
    {
        ListNode *newHead = new ListNode(val, head);
        return newHead;
    }

    ListNode *insertTail(ListNode *head, int val)
    {
        ListNode *newTail = new ListNode(val);

        if (!head)
        {
            return newTail;
        }

        ListNode *tail = head;

        while (tail->next)
        {
            tail = tail->next;
        }

        tail->next = newTail;

        return head;
    }

    ListNode *insertAtKthPosition(ListNode *head, int val, int k)
    {
        if (k == 1)
        {
            insertHead(head, val);
        }

        int count = 1;
        ListNode *curr = head;

        while (curr)
        {
            count++;

            if (count == k)
            {
                break;
            }

            curr = curr->next;
        }

        ListNode *newNode = new ListNode(val, curr->next);

        curr->next = newNode;

        return head;
    }

    void insertAfterNode(ListNode *node, int val)
    {
        ListNode *newNode = new ListNode(val, node->next);
        node->next = newNode;
    }
};

class DeleteNode
{
    ListNode *deleteHead(ListNode *head)
    {
        if (!head || !head->next)
        {
            return nullptr;
        }

        ListNode *newHead = head->next;

        delete head;

        return newHead;
    }

    ListNode *deleteTail(ListNode *head)
    {
        if (!head || !head->next)
        {
            delete head;
            return nullptr;
        }

        ListNode *newTail = head;

        while (newTail->next->next)
        {
            newTail = newTail->next;
        }

        delete newTail->next;

        newTail->next = nullptr;

        return head;
    }

    ListNode *deleteAtKthPosition(ListNode *head, int k)
    {
        if (k == 1)
        {
            deleteHead(head);
        }

        int count = 1;
        ListNode *curr = head;

        while (curr)
        {
            count++;

            if (count == k)
            {
                break;
            }

            curr = curr->next;
        }

        ListNode *temp = curr->next;
        curr->next = curr->next->next;

        delete temp;

        return head;
    }

    void deleteAfterNode(ListNode *node)
    {
        ListNode *temp = node->next;
        node->next = node->next->next;

        delete temp;
    }
};

class Operations
{
public:
    void printLL(ListNode *head)
    {
        ListNode *curr = head;

        while (curr)
        {
            cout << curr->val << '\t';
            curr = curr->next;
        }
    }

    ListNode *convertArrayToList(vector<int> arr)
    {
        int n = arr.size();

        if (n == 0)
        {
            return nullptr;
        }

        ListNode *head = new ListNode(arr[0]);
        ListNode *tail = head;

        for (int i = 1; i < n; i++)
        {
            ListNode *newNode = new ListNode(arr[i]);
            tail->next = newNode;
            tail = newNode;
        }

        return tail;
    }

    int lengthOfLL(ListNode *head)
    {
        int len = 0;
        ListNode *curr = head;

        while (curr)
        {
            len++;
            curr = curr->next;
        }

        return len;
    }
};