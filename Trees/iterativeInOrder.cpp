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

vector<int> inorder(TreeNode *root)
{

    stack<TreeNode *> st;

    TreeNode *node = root;

    vector<int> inorder;

    while (true)
    {

        if (node != NULL)
        {

            st.push(node);

            node = node->left;
        }
        else
        {

            if (st.empty())
            {
                break;
            }

            node = st.top();

            st.pop();

            inorder.push_back(node->val);

            node = node->right;
        }
    }

    return inorder;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    vector<int>ans = inorder(root);
    for(auto it:ans)
        cout<<it<<endl;

    return 0;
}