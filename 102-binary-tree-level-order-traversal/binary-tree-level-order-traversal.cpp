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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*>q;
        vector<vector<int>>result;
        q.push(root);

        while(!q.empty()){
            vector<int>temp;
            int currentSize = q.size();
            for(int i = 0;i <currentSize;i++){
                auto node = q.front();
                q.pop();
                if (node->left)q.push(node->left);
                if(node->right) q.push(node->right);
                temp.emplace_back(node->val);
            }
            result.emplace_back(temp);
        }
        return result;
    }
};