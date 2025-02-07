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
    void pathHelper(TreeNode* root, int target, vector<vector<int>>& result, vector<int>& ds){
        if(!root) return;
        ds.emplace_back(root->val);
        if(!root->left && !root->right){
            if(target == root->val){
                // ds.emplace_back(root->val);
                result.emplace_back(ds);     
            }
            // return;
        } 
        pathHelper(root->left, target-root->val, result, ds);
        pathHelper(root->right, target-root->val, result, ds);
        ds.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>result;
        vector<int>ds;
        pathHelper(root, targetSum, result, ds);
        return result;
    }
};