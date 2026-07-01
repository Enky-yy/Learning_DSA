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

vector<int> bottomView(TreeNode * root){
    vector<int> ans ;
    if(!root) return ans;
    map<int , int> mpp;
    queue<pair<TreeNode* , int>> q;
    q.push({root,0});

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        TreeNode * Node = it.first;

        int line = it.second;

        mpp[line] = Node->val;

        if(Node->left!= nullptr){
            q.push({Node->left, line-1});
        }
        if(Node->right!=nullptr){
            q.push({Node->right, line+1});
        }
    }
    for(auto it:mpp){
        ans.push_back(it.second);
    }
    return ans;
    

}

int main() {
    // Creating a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(10);
    root->left->left->right = new TreeNode(5);
    root->left->left->right->right = new TreeNode(6);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(10);
    root->right->left = new TreeNode(9);

    vector<int> bottomview =
                    bottomView(root);

    // Print the result
    cout << "Bottom View Traversal: "<< endl;
    for(auto node: bottomview){
        cout << node << " ";
    }

    return 0;
}