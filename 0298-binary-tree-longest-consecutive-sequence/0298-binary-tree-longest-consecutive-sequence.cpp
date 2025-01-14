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
    void pathCalc(TreeNode* root,int parentval,int nodeCount, int& pathLength){
        if(!root){
            return;
        }
        if(root->val == parentval+1){
            nodeCount++;
        }
        else nodeCount = 1;
        pathLength = max(pathLength,nodeCount);
        pathCalc(root->left, root->val, nodeCount, pathLength);
        pathCalc(root->right,root->val,nodeCount,pathLength);
    }
public:
    int longestConsecutive(TreeNode* root) {
        int pathlength = 0;
        pathCalc(root, root->val-1,0, pathlength);
        return pathlength;
    }
};