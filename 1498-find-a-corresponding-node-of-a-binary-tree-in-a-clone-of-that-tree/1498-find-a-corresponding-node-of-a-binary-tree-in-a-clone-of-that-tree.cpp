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
    TreeNode* cloneCopy(TreeNode* original,TreeNode* cloned, TreeNode* target){
        if(!original) return nullptr;
        if(original == target){
            return cloned;
        }
        TreeNode* left = cloneCopy(original->left, cloned->left, target);
        if(left)return left;
        return cloneCopy(original->right,cloned->right,target);
    }
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        return cloneCopy(original,cloned,target);
    }
};