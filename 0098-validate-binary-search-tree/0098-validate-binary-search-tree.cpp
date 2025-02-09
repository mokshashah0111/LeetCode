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
    bool validation(TreeNode* root, long long max, long long  min){
        if(!root) return true;
        else if(root->val <= min || root->val>=max) return false;
        return validation(root->left,root->val,min) && validation(root->right,max,root->val);
    }
public:
    bool isValidBST(TreeNode* root) {
        return validation(root,LLONG_MAX,LLONG_MIN);
    }
};