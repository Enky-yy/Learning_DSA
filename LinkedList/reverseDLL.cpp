#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev = nullptr;

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        prev = nullptr;
    }
    Node(int data1, Node* next1 , Node* prev1){
        data = data1;
        next = next1;
        prev = prev1;
    }
};

void traversalLL(Node *LL)
{

    Node *address = LL;
    while (address != nullptr)
    {
        cout << address->data << ' ';
        address = address->next;
    }
}

Node * convertFromArr(vector <int> arr){
    Node* head = new Node(arr[0]);
    Node* prev = head ;
    for (int i = 1; i < arr.size(); i++)
    {
        Node * temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

Node * reverseDLL(Node * head){
    Node * cur = head;
    Node * temp = nullptr;

    while ( cur)
    {
        swap(cur->next, cur->prev);
        temp = cur;
        cur = cur->prev;
    }

    return temp;
}

int main() {
    Node * x = new Node(4);
    vector <int> arr = {1,2,3,4,5,6};
    Node* head = convertFromArr(arr);
    traversalLL(head);
    cout<< head->next->prev->next->prev->data<<endl;
    Node * k = reverseDLL(head);
    traversalLL(k);
    return 0;
}