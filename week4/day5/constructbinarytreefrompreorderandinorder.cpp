class Solution {
public:
    unordered_map<int, int> inorderMap;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
         for (int i = 0; i < inorder.size(); ++i) {
            inorderMap[inorder[i]] = i;
        }

        return build(preorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

private:
    TreeNode* build(const vector<int>& preorder, int preStart, int preEnd,
                    int inStart, int inEnd) {
        if (preStart > preEnd || inStart > inEnd) {
            return nullptr;
        }

        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);

        int inRootIndex = inorderMap[rootVal];
        int leftTreeSize = inRootIndex - inStart;

        root->left = build(preorder, preStart + 1, preStart + leftTreeSize,
                           inStart, inRootIndex - 1);

        root->right = build(preorder, preStart + leftTreeSize + 1, preEnd,
                            inRootIndex + 1, inEnd);

        return root;
    }
};
