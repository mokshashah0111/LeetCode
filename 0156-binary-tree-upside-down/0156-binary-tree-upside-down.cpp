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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        TreeNode* current = root;
        TreeNode* prev = nullptr;
        TreeNode* next = nullptr;
        TreeNode* temp = nullptr;

        while(current){
            next = current->left;
            current->left = temp;
            temp = current->right;
            current->right = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
};