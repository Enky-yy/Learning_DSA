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

    stack<TreeNode*> st;
    st.push(root);
    
    while (!st.empty())
    {
        root = st.top();
        st.pop();
        ans.push_back(root->val);
        if(root->right != nullptr){
            st.push(root->right);
        }
        if(root->left!= nullptr){
            st.push(root->left);
        }
    }
    return ans;
    
}

int main() {
    
    return 0;
}