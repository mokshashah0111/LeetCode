class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty() || postorder.empty()) return nullptr;

        TreeNode* root = new TreeNode(postorder.back());
        postorder.pop_back();

        int rootIndex = find(inorder.begin(), inorder.end(), root->val) - inorder.begin();
        vector<int> left_inorder(inorder.begin(), inorder.begin() + rootIndex);
        vector<int> right_inorder(inorder.begin() + rootIndex + 1, inorder.end());

        vector<int> left_postorder(postorder.begin(), postorder.begin() + left_inorder.size());
        vector<int> right_postorder(postorder.begin() + left_inorder.size(), postorder.end());

        root->left = buildTree(left_inorder, left_postorder);
        root->right = buildTree(right_inorder, right_postorder);

        return root;
    }
};
