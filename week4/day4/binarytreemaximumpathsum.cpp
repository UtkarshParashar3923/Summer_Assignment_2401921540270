class Solution {
private:
    int maxSum;

    int maxGain(TreeNode* node) {
        if (node == nullptr) return 0;

        int leftGain = max(maxGain(node->left), 0);
        int rightGain = max(maxGain(node->right), 0);

        int currentPathSum = node->val + leftGain + rightGain;

        maxSum = max(maxSum, currentPathSum);

        return node->val + max(leftGain, rightGain);
    }

public:
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        maxGain(root);
        return maxSum;
    }
};
