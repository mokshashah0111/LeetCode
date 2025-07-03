class Solution {
private:
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* current = q.front(); q.pop();
            if (current->left) {
                parent[current->left] = current;
                q.push(current->left);
            }
            if (current->right) {
                parent[current->right] = current;
                q.push(current->right);
            }
        }
    }

    TreeNode* findNode(TreeNode* root, int val) {
        if (!root) return nullptr;
        if (root->val == val) return root;
        TreeNode* left = findNode(root->left, val);
        if (left) return left;
        return findNode(root->right, val);
    }

public:
    int findDistance(TreeNode* root, int p, int q) {
        unordered_map<TreeNode*, TreeNode*> parent;
        markParents(root, parent);

        TreeNode* start = findNode(root, p);
        TreeNode* target = findNode(root, q);

        queue<pair<TreeNode*, int>> bfs;
        unordered_set<TreeNode*> visited;

        bfs.push({start, 0});
        visited.insert(start);

        while (!bfs.empty()) {
            auto [node, dist] = bfs.front(); bfs.pop();
            if (node == target) return dist;

            if (node->left && !visited.count(node->left)) {
                visited.insert(node->left);
                bfs.push({node->left, dist + 1});
            }
            if (node->right && !visited.count(node->right)) {
                visited.insert(node->right);
                bfs.push({node->right, dist + 1});
            }
            if (parent.count(node) && !visited.count(parent[node])) {
                visited.insert(parent[node]);
                bfs.push({parent[node], dist + 1});
            }
        }

        return -1;  // Should never reach here if both nodes exist
    }
};
