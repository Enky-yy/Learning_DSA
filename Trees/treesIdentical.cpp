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

bool check(TreeNode * left , TreeNode * right){
    if(left == nullptr && right == nullptr) return true;
    if(left == nullptr || right == nullptr) return false;
    if(left->val!=right->val){
        return false;
    }
    
    return (left->val == right->val) && check(left->left, right->left) && check(left->right, right->right);
}

int main() {
    // Creating the first binary tree (Node1)
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right= new TreeNode(5);

    // Creating the second binary tree (Node2)
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    root2->left->left = new TreeNode(4);

    // Creating an instance of the Solution class
    

    // Check if the two binary trees are identical and output the result
    if (check(root1, root2)) {
        cout << "The binary trees are identical." << endl;
    } else {
        cout << "The binary trees are not identical." << endl;
    }

    return 0;
}