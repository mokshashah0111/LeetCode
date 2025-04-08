/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    private:
    struct Status{
        int targetNodes;
        TreeNode* ancestor;
    };
    Status LCAhelper(TreeNode* root, TreeNode* node0, TreeNode* node1){
        if(!root) return {0, nullptr};
        auto left = LCAhelper(root->left, node0, node1);
        if(left.targetNodes==2) return left;
        auto right = LCAhelper(root->right, node0, node1);
        if(right.targetNodes== 2) return right;

        int target = left.targetNodes+ right.targetNodes+ (root == node0) + (root==node1);
        TreeNode* ancestor = target == 2 ? root : nullptr;
        return {target,ancestor};
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return LCAhelper(root,p,q).ancestor;
    }
};