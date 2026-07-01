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

vector<int> topView(TreeNode * root){
    vector<int> ans;
    if (root == NULL) {
            return ans;
        }
    map <int , int> mpp;
    queue<pair<TreeNode* , int>> q;
    q.push({root, 0});

    while (!q.empty())
    {       
        auto it = q.front();
        q.pop();

        TreeNode * Node = it.first;
        int line = it.second;

        if(mpp.find(line) == mpp.end())
            mpp[line]= Node->val;

        if(Node->left!=nullptr){
            q.push({Node->left, line--});\
        
        if(Node->right!=nullptr){
            q.push({Node->right, line+1});
        }
        }

    }
    for(auto it : mpp){
        ans.push_back(it.second);
    }
    return ans;
    
}

int main() {
    
    return 0;
}