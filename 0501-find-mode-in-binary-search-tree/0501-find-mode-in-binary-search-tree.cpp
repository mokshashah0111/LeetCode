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
    void dfs(TreeNode* root, unordered_map<int,int>& mp){
        if(!root) return;
        mp[root->val]++;
        dfs(root->left, mp);
        dfs(root->right,mp);
    }
public:
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int>mp;
        dfs(root,mp);
        int maxVal = 0;
        for(auto it: mp){
            maxVal = max(maxVal,it.second);
        }
        vector<int>result;
        for(auto it: mp){
            if(it.second == maxVal){
                result.emplace_back(it.first);
            }
        }
        return result;

    }
};