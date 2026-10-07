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
    void findPath(TreeNode* root, int targetSum, vector<int>& temp, vector<vector<int>>& result){
        if(root == nullptr)return;
        temp.emplace_back(root->val);
        if(root->left== nullptr && root->right == nullptr){
            if(root->val == targetSum){
                result.emplace_back(temp);
            }
        }
        findPath(root->left,targetSum-root->val,temp,result);
        findPath(root->right, targetSum-root->val,temp,result);
        temp.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>temp;
        vector<vector<int>>result;
        findPath(root, targetSum,temp, result);
        return result;
    }
};