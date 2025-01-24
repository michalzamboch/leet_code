
var tree1 = new TreeNode(1)
{
    left = new TreeNode(2),
    right = new TreeNode(3)
    {
        left = new TreeNode(4),
        right = new TreeNode(5),
    },
};

var tree2 = new TreeNode(1)
{
    left = new TreeNode(3)
    {
        left = new TreeNode(4),
        right = new TreeNode(5),
    },
    right = new TreeNode(3)
    {
        left = new TreeNode(4),
        right = new TreeNode(5),
    },
};

var tree3 = new TreeNode(1)
{
    right = new TreeNode(2),
    left = new TreeNode(3)
    {
        right = new TreeNode(2),
        left = new TreeNode(3)
        {
            right = new TreeNode(2),
            left = new TreeNode(3)
            {
                right = new TreeNode(2),
                left = new TreeNode(3)
                {
                    left = new TreeNode(4),
                    right = new TreeNode(5),
                },
            },
        },
    },
};

var tree4 = new TreeNode(1);

Execute(tree1);
Execute(tree2);
Execute(tree3);
Execute(tree4);

return;

void Execute(TreeNode root)
{
    var result = new Solution().MinDepth(root);
    Console.WriteLine($"Result: {result}");
}

public sealed class TreeNode(int val = 0, TreeNode left = null, TreeNode right = null)
{
    public int val = val;
    public TreeNode left = left;
    public TreeNode right = right;
}

public sealed class Solution {
    public int MinDepth(TreeNode root)
    {
        if (root == null)
        {
            return 0;
        }
        if (root.left == null)
        {
            return 1 + this.MinDepth(root.right);
        }
        if (root.right == null)
        {
            return 1 + this.MinDepth(root.left);
        }
        
        return 1 + Math.Min(MinDepth(root.left), MinDepth(root.right));
    }
}