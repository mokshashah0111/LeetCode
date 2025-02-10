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
    TreeNode* helper(vector<int>& preorder, int start, int end){
        if(start>end) return nullptr;
        TreeNode* root = new TreeNode(preorder[start]);
        if(start == end) return root;

        int i = start+1;
        for(;i<=end;i++){
            if(preorder[i] > root->val) break;
        }
        root->left = helper(preorder,start+1,i-1);
        root->right = helper(preorder,i,end);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return helper(preorder, 0, preorder.size()-1);
    }
};