## Smallest Subtree with All the Deepest Nodes

### Problem
Given the root of a binary tree, return the smallest subtree that contains all the deepest nodes.

### Approach
- Perform BFS to traverse the tree level by level
- Track parent pointers for each node
- Store the nodes of the last level (deepest nodes)
- Move all deepest nodes upward using parent pointers
- Continue until only one node remains (LCA of deepest nodes)

### Complexity
- Time Complexity: O(n)
- Space Complexity: O(n)

### Key Insight
The smallest subtree containing all deepest nodes is equivalent to the lowest common ancestor (LCA) of all deepest nodes.


  #### soluton:

  class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if (!root) return nullptr;

        unordered_map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> q;
        q.push(root);
        parent[root] = nullptr;

        vector<TreeNode*> lastLevel;

        // BFS traversal
        while (!q.empty()) {
            int size = q.size();
            lastLevel.clear();

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                lastLevel.push_back(node);

                if (node->left) {
                    parent[node->left] = node;
                    q.push(node->left);
                }
                if (node->right) {
                    parent[node->right] = node;
                    q.push(node->right);
                }
            }
        }

        unordered_set<TreeNode*> deepest(lastLevel.begin(), lastLevel.end());

        // Move upward until one node remains
        while (deepest.size() > 1) {
            unordered_set<TreeNode*> next;
            for (auto node : deepest) {
                next.insert(parent[node]);
            }
            deepest = next;
        }

        return *deepest.begin();
    }
};
