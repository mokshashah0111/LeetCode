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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>>result;
        queue<TreeNode*>q;
        q.push(root);
        int count =1;
        while(!q.empty()){
            int currentsize =q.size();
            vector<int>currentLevel;
            for(int i=0;i<currentsize;i++){
                auto current = q.front();
                q.pop();
                if(count%2 == 0) currentLevel.insert(currentLevel.begin(),current->val);
                else currentLevel.emplace_back(current->val);   
                if(current->left)q.emplace(current->left);
                if(current->right)q.emplace(current->right);
            }
            result.emplace_back(currentLevel);
            count++;
        }
        return result;
    }
};