#include <iostream>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool isBalanced(TreeNode *root)
    {
        if (root == nullptr)
        {
            return true;
        }
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        int heightDiff = abs(leftHeight - rightHeight);
        return heightDiff <= 1;
    }

    int height(TreeNode *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        return 1 + std::max(leftHeight, rightHeight);
    }
};