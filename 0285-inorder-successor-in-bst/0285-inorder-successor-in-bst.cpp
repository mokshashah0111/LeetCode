/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };

 1,2,3,4,5,6
 */

class Solution {
    private:
    void inorder(TreeNode* root, vector<TreeNode*>& vec){
        if(!root)return;
        inorder(root->left,vec);
        vec.emplace_back(root);
        inorder(root->right, vec);
    }
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        vector<TreeNode*> result;
        inorder(root,result);
        for(int i = 0;i<result.size();i++){
            if(result[i] == p){
                if(i+1 < result.size()) return result[i+1];
            }
        }
        return nullptr;
    }
};