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

vector<vector<int>> levelOrder( TreeNode* root){
    vector<vector<int>> ans;
    if(root== nullptr) return ans;

    queue<TreeNode*>q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        vector<int>level;

        for (int i = 0; i < size; i++)
        {
            TreeNode *Node = q.front();
            q.pop();
            level.push_back(Node->val);
            if((Node->left)!=nullptr)
                q.push(Node->left);
            if(Node->right != nullptr){
                q.push(Node->right);
            }
        }
        ans.push_back(level);
        
    }
    return ans;
}

void printVector(const vector<int>& vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}



int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    vector<vector<int>> ans =levelOrder(root);
    for (const vector<int>& level : ans) {
        printVector(level);
    }

    return 0;
}