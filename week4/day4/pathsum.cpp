class Solution {
public:
   bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;

        // If it's a leaf node
        if (!root->left && !root->right)
            return root->val == targetSum;

        // Recurse on left and right subtrees
        int newSum = targetSum - root->val;
        return hasPathSum(root->left, newSum) || hasPathSum(root->right, newSum);
    }
};
