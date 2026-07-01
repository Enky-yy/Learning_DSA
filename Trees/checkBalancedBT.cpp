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

int height(TreeNode*left){
    if (left==nullptr) return 0;

    return 1 + max(height(left->left), height(left->right));
}

bool checkBalanced(TreeNode * root){
    bool balanced = false;
    if (root == nullptr) return 0;

    int lh = height(root->left);
    int rh = height(root->right);

    if((lh-rh) <=1){
        balanced =true;
    }
    return balanced;
}

int main() {
    
    return 0;
}