#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> result;
        if (root != nullptr)
        {
            preorder(root, result);
        }

        return result;
    }

    void preorder(Node* root, vector<int> &v)
    {
        auto x = root->val;
        v.push_back(x);

        for (auto child : root->children)
        {
            preorder(child, v);
        }
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}