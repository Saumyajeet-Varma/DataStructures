#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode() : val(0), next(nullptr), prev(nullptr) {}
    ListNode(int x) : val(x), next(nullptr), prev(nullptr) {}
    ListNode(int x, ListNode *prev, ListNode *next) : val(x), next(next), prev(prev) {}
};

class InsertNode
{
    ListNode *insertHead(ListNode *head, int val)
    {
        ListNode *newHead = new ListNode(val, head, nullptr);
        head->prev = newHead;

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
        newTail->prev = tail;

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

        ListNode *nextNode = curr->next;
        ListNode *newNode = new ListNode(val, nextNode, curr);

        nextNode->prev = newNode;
        curr->next = newNode;

        return head;
    }

    void insertAfterNode(ListNode *node, int val)
    {
        ListNode *nextNode = node->next;
        ListNode *newNode = new ListNode(val, nextNode, node);

        nextNode->prev = newNode;
        node->next = newNode;
    }

    void insertBeforeNode(ListNode *node, int val)
    {
        ListNode *prevNode = node->prev;
        ListNode *newNode = new ListNode(val, node, prevNode);

        prevNode->next = newNode;
        node->prev = newNode;
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

        newHead->prev = nullptr;
        head->next = nullptr;

        delete head;

        return newHead;
    }

    ListNode *deleteTail(ListNode *head)
    {
        if (!head || !head->next)
        {
            return nullptr;
        }

        ListNode *newTail = head;

        while (newTail->next->next)
        {
            newTail = newTail->next;
        }

        ListNode *tail = newTail->next;

        newTail->next = nullptr;
        tail->prev = nullptr;

        delete tail;

        return newTail;
    }

    ListNode *deleteAtKthPosition(ListNode *head, int k)
    {
        if (k == 1)
        {
            return deleteHead(head);
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
        ListNode *nextNode = temp->next;

        curr->next = nextNode;
        nextNode->prev = curr;

        temp->next = nullptr;
        temp->prev = nullptr;

        delete temp;

        return head;
    }

    void deleteAfterNode(ListNode *node)
    {
        ListNode *delNode = node->next;

        node->next = delNode->next;
        delNode->next->prev = node;

        delNode->next = nullptr;
        delNode->prev = nullptr;

        delete delNode;
    }

    void deleteBeforeNode(ListNode *node)
    {
        ListNode *delNode = node->prev;

        node->prev = delNode->prev;
        delNode->prev->next = node;

        delNode->next = nullptr;
        delNode->prev = nullptr;

        delete delNode;
    }
};

class Operations
{
public:
    void printDLL(ListNode *head)
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

    int lengthOfDLL(ListNode *head)
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