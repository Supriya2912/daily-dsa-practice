## Max Dot Product of Two Subsequences

### Problem
Given two integer arrays, return the maximum dot product between non-empty subsequences of both arrays.

### Approach (Dynamic Programming)
- dp[i][j] represents the maximum dot product using first i elements of array A and first j elements of array B
- At each step:
  - Take current pair: a[i-1] * b[j-1] + max(0, dp[i-1][j-1])
  - Skip element from A
  - Skip element from B
- Take the maximum of all options

### Complexity
- Time Complexity: O(n × m)
- Space Complexity: O(n × m)

### Key Insight
Using `max(0, dp[i-1][j-1])` ensures that we always select a non-empty subsequence and correctly handle negative values.


###solution:

class Solution {
public:
    int maxDotProduct(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
        const int NEG = -1e9;
        vector<vector<int>> dp(n+1, vector<int>(m+1, NEG));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int take = a[i-1]*b[j-1] + max(0, dp[i-1][j-1]);
                dp[i][j] = max({take, dp[i-1][j], dp[i][j-1]});
            }
        }
        return dp[n][m];
    }
};


