## Maximum Product of Splitted Binary Tree

### Problem
Given a binary tree, split it into two subtrees by removing one edge such that the product of the sums of the two subtrees is maximized.

### Approach
- First DFS to compute the total sum of the tree
- Second DFS to compute subtree sums
- For each subtree, consider splitting and minimize:
  |2 * subtreeSum - totalSum|
- Use the minimized difference to compute maximum product

### Complexity
- Time Complexity: O(n)
- Space Complexity: O(h) (recursion stack)

### Key Insight
Maximizing the product is equivalent to minimizing the difference between the two subtree sums.


class Solution {
public:
    const int mod=1e9+7;
    long long diff=INT_MAX, total=0;
    int dfs(TreeNode* root, bool compute_ans=0){
        if (!root) return 0;
        int sum=root->val
            +dfs(root->left, compute_ans)
            +dfs(root->right, compute_ans);
        if (compute_ans) diff=min(diff, abs(sum*2-total));
        return sum;
    }
    int maxProduct(TreeNode* root) {
        total=dfs(root);
        dfs(root, 1);
    
        return (total-diff)/2*(total+diff)/2%mod;
    }
};



auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
