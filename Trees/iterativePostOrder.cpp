#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data)
    {
        val = (data);
        left = nullptr;
        right = nullptr;
    }
};

vector<int> preorder(TreeNode * root){
    vector<int> ans;
    if(root==nullptr) return ans;

    stack<TreeNode*> st1, st2;
    st1.push(root);
    
    while (!st1.empty())
    {
        root = st1.top();
        st1.pop();
        st2.push(root);
        if(root->left != nullptr){
            st1.push(root->left);
        }
        if(root->right!= nullptr){
            st1.push(root->right);
        }
        
    }
    while (!st2.empty())
    {
        root = st2.top();
        st2.pop();
        ans.push_back(root->val);
    }
    
    return ans;
    
}

// using only one stack
vector<int> preorder(TreeNode * root){
    vector<int> ans;
    if(root==nullptr) return ans;

    stack<TreeNode*> st1, st2;
    st1.push(root);
    
    while (!st1.empty())
    {
        root = st1.top();
        st1.pop();
        ans.push_back(root->val);
        if(root->left != nullptr){
            st1.push(root->left);
        }
        if(root->right!= nullptr){
            st1.push(root->right);
        }
        
    }
    reverse(ans.begin(), ans.end());
    return ans;
    
}

int main() {
    
    return 0;
}