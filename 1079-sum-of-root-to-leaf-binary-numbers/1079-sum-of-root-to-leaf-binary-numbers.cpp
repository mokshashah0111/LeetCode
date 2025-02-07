/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    private:
    int sumHelper(TreeNode* root, int partialSum){
        if(!root) return 0;
        partialSum = partialSum*2 + root->val;
        if(!root->left && !root->right) return partialSum;
        return sumHelper(root->left, partialSum) + sumHelper(root->right, partialSum);
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        return sumHelper(root, 0);
        
    }
};