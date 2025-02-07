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
    bool findSum(TreeNode* root, int target){
        // if(!root || target<0) return false;//5,22....4,17....11,13....11,2
        if(!root) return false;

        if(!root->left && !root->right) return target==root->val;//5,22....4,17....11.13...11,2
        bool leftSum = findSum(root->left,target-root->val);//5,22....4,17....11,13....11,2
        bool right = findSum(root->right, target-root->val);
        return  leftSum|| right;
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return findSum(root, targetSum);
    }
};