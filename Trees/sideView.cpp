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

void rightView(TreeNode * root , int level , vector<int> &ans){
    if(!root) return;

    if(ans.size() == level){
        ans.push_back(root->val);
    }

    rightView(root->right, level+1, ans);
    rightView(root->left, level+1, ans);
}

vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        rightView(root , 0 , ans);
        return ans;
    }

int main() {
    
    return 0;
}