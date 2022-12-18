#include <iostream>
#include <vector>

using namespace std;

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
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> result;
        preorder(root, result);

        return result;
    }

    void preorder(TreeNode *root, vector<int> &v)
    {
        if (root != nullptr)
        {
            v.push_back(root->val);
            preorder(root->left, v);
            preorder(root->right, v);
        }
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}