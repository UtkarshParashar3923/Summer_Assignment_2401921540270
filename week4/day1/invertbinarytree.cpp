class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return nullptr;

        // Swap the left and right subtree recursively
        TreeNode* leftSubtree = invertTree(root->left);
        TreeNode* rightSubtree = invertTree(root->right);

        root->left = rightSubtree;
        root->right = leftSubtree;

        return root;
    }
};
