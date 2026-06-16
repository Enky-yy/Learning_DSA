#include <iostream>

using namespace std;


class Node{
    public:
        int value;
        Node *next;

        Node(int Value){
            this->value = Value;
            next = nullptr
        }
};


class LinkedList {
    private:
        Node* head;
        Node* tail;
        int length;

    public:
        LinkedList(int Value){
            Node* newNode = new Node(Value);
            head = newNode;
            tail = newNode;
            length =1;
        }
};

LinkedList* myLimkedList = new LinkedList(4)
