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
public:
    void inorder(TreeNode* root, int& minValue, int& prev){
        if(!root) return;
        inorder(root->left, minValue, prev);
        if(prev !=-1){
            minValue= min(minValue, abs(root->val - prev));
        }
        prev = root->val;
        inorder(root->right,minValue, prev);
    }
    int minDiffInBST(TreeNode* root) {
        int prev  = -1;
        int minValue = INT_MAX;
        inorder(root, minValue, prev);
        return minValue;
    }
};