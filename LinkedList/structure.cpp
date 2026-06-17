#include <iostream>
#include <bits/stdc++.h>

using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<int> *next;

public:
    Node(T data1, Node<int> *next1)
    {
        data = data1;
        next = next1;
    }

public:
    Node(T data1)
    {
        data = data1;
        next = nullptr;
    }
};

Node<int> *convert2Arr(vector<int> &arr)
{
    Node<int> *head = new Node(arr[0]);
    Node<int> *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node<int> *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void traversalLL(Node<int> *LL)
{

    Node<int> *address = LL;
    while (address != nullptr)
    {
        cout << address->data << ' ';
        address = address->next;
    }
}

int lengthLL(Node<int> *LL)
{
    int cnts = 0;
    Node<int> *address = LL;
    while (address != nullptr)
    {
        cnts++;
        address = address->next;
    }
    return cnts;
}

bool checkIfPresent(Node<int> *LL, int target)
{
    Node<int> *address = LL;
    while (address != nullptr)
    {
        if (address->data == target)
        {
            return true;
        }
        address = address->next;
    }
    return false;
}

Node<int> *removeElement(Node<int> *LL, int target)
{
    if (!LL)
        return LL;

    Node<int> *ans= LL;
    if (LL->data == target)
    {
        Node<int> *temp= LL;
        LL=LL->next;
        delete temp;
        return LL;
        
    }

    while (ans && ans->next)
    {
        if (ans->next->data == target)
        {
            Node<int> *exc = ans->next;
            ans->next = ans->next->next;
            delete exc;
        }
        else
        {
            ans = ans->next;
        }
    }
    return LL;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};

    Node<int> *y = new Node<int>(arr[0], nullptr);
    Node<int> *x = new Node<int>(arr[1], nullptr);

    cout << y << endl;
    cout << x << endl;

    Node<int> *head = convert2Arr(arr);
    cout << head->next->data << endl;

    traversalLL(head);
    cout << '\n'
         << lengthLL(head) << endl;

    if (checkIfPresent(head, 3))
    {
        cout << "Found" << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }

    Node<int> *k = removeElement(head, 3);
    traversalLL(k);

    return 0;
}