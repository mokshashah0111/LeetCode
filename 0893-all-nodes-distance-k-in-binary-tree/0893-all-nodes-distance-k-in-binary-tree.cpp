/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    private:
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parents){
        queue<TreeNode*>q;
        q.emplace(root);

        while(!q.empty()){
            auto current = q.front();
            q.pop();

            if(current->left){
                q.emplace(current->left);
                parents[current->left] = current;
            }
            if(current->right){
                q.emplace(current->right);
                parents[current->right] = current;
            }
        }
    }
public:

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        queue<TreeNode*>q;
        unordered_map<TreeNode*, TreeNode*>parents;
        markParents(root,parents);
        unordered_map<TreeNode*, bool>visited;
        q.push(target);
        visited[target] = true;
        int currLevel =0;
        while(!q.empty()){
            int size = q.size();
            if(currLevel ==k) break;
            currLevel++;
            for(int i =0; i<size;i++){
                auto current = q.front();
                q.pop();
                visited[current] = true;
                if(current->left && !visited[current->left]){
                    q.emplace(current->left);
                    visited[current->left] = true;
                }
                if(current->right && !visited[current->right] ){
                    q.emplace(current->right);
                    visited[current->right] = true;
                }
                if(parents.find(current) != parents.end() && !visited[parents[current]]){
                    q.emplace(parents[current]);
                    visited[parents[current]] = true;
                }
            }
        }

        vector<int>result;
        while(!q.empty()){
            result.emplace_back(q.front()->val);
            q.pop();
        }
        return result;
    }
};