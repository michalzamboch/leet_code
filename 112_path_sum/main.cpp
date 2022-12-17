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
    bool hasPath = false;

    bool hasPathSum(TreeNode *root, int targetSum)
    {
        preorder(root, 0, targetSum);
        return hasPath;
    }

    void preorder(TreeNode *root, int currentSum, int targetSum)
    {
        if (root == nullptr || this->hasPath == true)
        {
            return;
        }

        auto tmp = currentSum + root->val;

        if (tmp < targetSum)
        {
            currentSum = tmp;
            preorder(root->left, currentSum, targetSum);
            preorder(root->right, currentSum, targetSum);
        }
        else if (tmp == targetSum)
        {
            if (root->right == nullptr && root->left == nullptr)
            {
                this->hasPath = true;
            }
        }
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}