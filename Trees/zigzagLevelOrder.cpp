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

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    if (root == nullptr)
        return ans;

    queue<TreeNode *> st;
    st.push(root);
    bool leftToRight = true;
    while (!st.empty())
    {
        int size = st.size();
        vector<int> levels(size);

        

        for (int i = 0; i < size; i++)
        {
            TreeNode *node = st.front();
            st.pop();

            int index = leftToRight ? i : size - i-1;
            levels[index] = node->val;

            if (node->left)
                st.push(node->left);
            if (node->right)
                st.push(node->right);
        }
        leftToRight = !leftToRight;
        ans.push_back(levels);
    }

    return ans;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    vector<vector<int>> ans = zigzagLevelOrder(root);

    cout << "[";
    for (auto &level : ans)
    {
        cout << "[";
        for (int i = 0; i < level.size(); i++)
        {
            cout << level[i];
            if (i != level.size() - 1) 
                cout << ", ";
        }
        cout << "]";
    }
    cout << "]" << endl;
    return 0;
}