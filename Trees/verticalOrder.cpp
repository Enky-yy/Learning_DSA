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

vector<vector<int>> verticalTraversal(TreeNode * root){
    vector<vector<int>> ans;
    queue<pair<TreeNode* , int>> q;
    q.push({root,1});
    while (!q.empty())
    {
        if (root == nullptr ) return ans;

    }
    
}

int main() {
    
    return 0;
}