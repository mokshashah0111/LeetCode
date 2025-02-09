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
    bool validation(TreeNode* root, long long max, long long  min){
        if(!root) return true;
        else if(root->val <= min || root->val>=max) return false;
        return validation(root->left,root->val,min) && validation(root->right,max,root->val);
    }
    struct bfsQueue{
        TreeNode* node;
        long lower;
        long upper;
    };
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        queue<bfsQueue>q;
        q.push(bfsQueue(root,LLONG_MIN,LLONG_MAX));
        while(!q.empty()){
            auto currentNode = q.front();
            q.pop();
            if(currentNode.node->val <= currentNode.lower || currentNode.node->val >= currentNode.upper) return false;
            if(currentNode.node->left){
                q.push(bfsQueue(currentNode.node->left,currentNode.lower,currentNode.node->val));
            }
            if(currentNode.node->right){
                q.push(bfsQueue(currentNode.node->right,currentNode.node->val,currentNode.upper));
            }
        }
        return true;

    }
};