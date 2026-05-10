# 🦘 Maximum Number of Jumps to Reach the Last Index

## 🧩 Problem Statement

You are given:

- An integer array `nums`
- An integer `target`

You start at index `0` and want to reach index `n - 1`.

You can jump from index `i` to index `j` (`i < j`) if:

```text
|nums[j] - nums[i]| <= target
Return the maximum number of jumps needed to reach the last index.

If it is impossible to reach the last index, return:

-1
📥 Input
nums → integer array
target → allowed maximum absolute difference
📤 Output
Maximum number of jumps to reach the last index
🧪 Example
Input
nums = [1, 3, 6, 4, 1, 2]
target = 2
Output
3
Explanation

One valid path:

0 → 1 → 3 → 5

Total jumps = 3

💡 Approach (Dynamic Programming)

We use DP where:

dp[i] = maximum jumps needed to reach index i

Initialize:

dp[0] = 0

All other positions:

dp[i] = -1

(-1 means unreachable)

🔹 Transition

For every pair (i, j) where i < j:

Check:

|nums[j] - nums[i]| <= target

If valid:

dp[j] = max(dp[j], dp[i] + 1)

This ensures we keep the maximum possible jumps.

✅ C++ Solution
class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        
        int n = nums.size();

        vector<int> dp(n, -1);

        // Starting point
        dp[0] = 0;

        for (int i = 0; i < n; i++) {

            if (dp[i] == -1) continue;

            for (int j = i + 1; j < n; j++) {

                long long diff = 1LL * nums[j] - nums[i];

                if (diff >= -target && diff <= target) {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
        }

        return dp[n - 1];
    }
};
☕ Java Solution
class Solution {
    public int maximumJumps(int[] nums, int target) {

        int n = nums.length;

        int[] dp = new int[n];
        Arrays.fill(dp, -1);

        dp[0] = 0;

        for (int i = 0; i < n; i++) {

            if (dp[i] == -1) continue;

            for (int j = i + 1; j < n; j++) {

                long diff = (long) nums[j] - nums[i];

                if (diff >= -target && diff <= target) {
                    dp[j] = Math.max(dp[j], dp[i] + 1);
                }
            }
        }

        return dp[n - 1];
    }
}
🐍 Python Solution
class Solution:
    def maximumJumps(self, nums, target):
        n = len(nums)

        dp = [-1] * n
        dp[0] = 0

        for i in range(n):

            if dp[i] == -1:
                continue

            for j in range(i + 1, n):

                if abs(nums[j] - nums[i]) <= target:
                    dp[j] = max(dp[j], dp[i] + 1)

        return dp[-1]
⏱️ Complexity Analysis
Time Complexity: O(n²)
Space Complexity: O(n)
