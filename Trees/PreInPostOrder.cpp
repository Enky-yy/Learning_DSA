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

vector<vector<int>> PreInPost(TreeNode *root)
{
    stack<pair<TreeNode *, int>> st;
    st.push({root, 1});
    vector<vector<int>> ans;
    vector<int> pre , in ,post;
    while (!st.empty())
    {
        auto it = st.top();
        st.pop();

        if (it.second == 1)
        {
            it.second=2;
            pre.push_back(it.first->val);
            st.push(it);
            if (it.first->left != nullptr)
                st.push({it.first->left, 1});
        }
        else if (it.second == 2)
        {
            it.second=3;
            in.push_back(it.first->val);
            st.push(it);
            if (it.first->right != nullptr)
                st.push({it.first->right, 1});
        }
        else
        {
            post.push_back(it.first->val);
        }
    }

    ans.push_back(pre);
    ans.push_back(in);
    ans.push_back(post);
    return ans;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    vector<vector<int>> ans = PreInPost(root);
    vector<int> pre , in ,post;
    pre = ans[0];
    in = ans[1];
    post = ans[2];

    // Printing the traversals
    cout << "Preorder traversal: ";
    for (int val : pre) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Inorder traversal: ";
    for (int val : in) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Postorder traversal: ";
    for (int val : post) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}