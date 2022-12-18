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
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        inorderPrint(root, result);

        return result;
    }

    void inorderPrint(TreeNode *root, vector<int> &v)
    {
        if (root != nullptr)
        {
            inorderPrint(root->left, v);
            v.push_back(root->val);
            inorderPrint(root->right, v);
        }
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}