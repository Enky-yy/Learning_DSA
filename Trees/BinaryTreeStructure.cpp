#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node * right;

    Node(int val){
        data=val;
        left = right = nullptr;
    }

};


int main() {
    Node *root = new Node(4);
    root->left = new Node(5);
    root->right = new Node(6);
    return 0;
}