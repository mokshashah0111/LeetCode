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
    TreeNode* treeHelper(vector<int>& inorder, int inorder_start, int inorder_end, vector<int>& postorder, int postorder_start, int postorder_end, unordered_map<int,int>& nodeToInorder){

        if(postorder_end <= postorder_start || inorder_end <= inorder_start) return nullptr;

        int rootVal = postorder[postorder_end - 1];
        TreeNode* root = new TreeNode(rootVal);

        int rootIndex = nodeToInorder[rootVal];
        int left_subtree_size = rootIndex - inorder_start;

         root->left = treeHelper(inorder, inorder_start, rootIndex,
                                postorder, postorder_start, postorder_start + left_subtree_size,
                                nodeToInorder);

        root->right = treeHelper(inorder, rootIndex + 1, inorder_end,
                                 postorder, postorder_start + left_subtree_size, postorder_end - 1,
                                 nodeToInorder);;

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>nodeToInorder;

        for(int i=0;i<inorder.size();i++){
            nodeToInorder[inorder[i]] = i;
        }

        return treeHelper(inorder,0,inorder.size(),postorder,0, postorder.size(), nodeToInorder);

    }
};