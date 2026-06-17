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

Node<int> *addTwoLL(Node<int> *head1, Node<int> *head2)
{

    Node<int> *dummy = new Node<int>(-1);
    Node<int> *tail = dummy;

    int carry = 0;

    while (head1 || head2 || carry)
    {
        int sum = carry;

        if (head1)
        {
            sum += head1->data;
            head1 = head1->next;
        }

        if (head2)
        {
            sum += head2->data;
            head2 = head2->next;
        }

        carry = sum / 10;

        tail->next = new Node<int>(sum % 10);
        tail = tail->next;
    }

    return dummy->next;
}

int main()
{
    vector<int> arr1 = {1, 2, 3, 4, 5, 6};
    vector<int> arr2 = {1, 2, 3, 4, 5, 6};

    Node<int> *head1 = convert2Arr(arr1);
    Node<int> *head2 = convert2Arr(arr2);
    traversalLL(head1);
    cout << endl;
    traversalLL(head2);
    cout << endl;

    Node<int> * answer = addTwoLL(head1, head2);
    traversalLL(answer);
    return 0;
}