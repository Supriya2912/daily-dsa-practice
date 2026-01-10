## Minimum ASCII Delete Sum for Two Strings

### Problem
Given two strings, return the minimum ASCII sum of deleted characters to make the two strings equal.

### Approach (Dynamic Programming)
- Compute the maximum ASCII sum of the common subsequence
- Use DP where dp[i][j] stores the maximum ASCII sum for s1[i:] and s2[j:]
- If characters match, add ASCII value and move diagonally
- Otherwise, take the maximum from skipping one character

### Complexity
- Time Complexity: O(m × n)
- Space Complexity: O(m × n)

### Key Insight
Minimum delete sum = (sum of ASCII values of both strings) − 2 × (maximum ASCII sum of common subsequence)


###Solution:

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (s1[i] == s2[j]) {
                    dp[i][j] = s1[i] + dp[i + 1][j + 1];
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }

        int total = 0;
        for (char c : s1) total += c;
        for (char c : s2) total += c;

        return total - 2 * dp[0][0];
    }
};
