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

Node<int>* kthInsertion(Node<int>* head, int key, int target) {
    Node<int>* newNode = new Node<int>(target);

    if (key == 0) {
        newNode->next = head;
        return newNode;
    }

    Node<int>* temp = head;
    int cnt = 0;

    while (temp != nullptr && cnt < key - 1) {
        temp = temp->next;
        cnt++;
    }

    if (temp == nullptr) {
        delete newNode;
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};

    Node<int> *head = convert2Arr(arr);
    Node<int> * k = kthInsertion(head , 3, 6);
    traversalLL(k);
    return 0;
}