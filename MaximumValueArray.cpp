# 📈 Maximum Value Array

## 🧩 Problem Statement

Given an integer array `nums`, construct a new array `ans` such that:

- `ans[i]` represents the maximum valid value considering:
  - prefix maximums
  - suffix minimum constraints

For every index:
- If the prefix maximum up to index `i` is greater than the minimum element on the right side,
  then inherit the next answer value.
- Otherwise, store the prefix maximum.

Return the final transformed array.

---

## 📥 Input

- An integer array `nums`

## 📤 Output

- A transformed integer array `ans`

---

## 🧪 Example

### Input
``` id="cdd95u"
nums = [2, 1, 3, 2]


Prefix Maximum
[2, 2, 3, 3]
Suffix Minimum
[1, 1, 2, 2]
Output
[3, 3, 3, 3]
💡 Approach

We use two helper arrays:

🔹 Prefix Maximum Array

prefMax[i] stores the maximum element from index 0 → i

🔹 Suffix Minimum Array

sufMin[i] stores the minimum element from index i → n-1

🔁 Logic

Traverse from right to left:

If:
prefMax[i] > sufMin[i + 1]

then:

ans[i] = ans[i + 1]

Otherwise:

ans[i] = prefMax[i]

This ensures consistency based on future constraints.

✅ C++ Solution
/*
 // global static array option
 const int N=1e5;
 int prefMax[N], sufMin[N];
*/

class Solution {
public:
    static vector<int> maxValue(vector<int>& nums) {
        const int n = nums.size();

        vector<int> prefMax(n), sufMin(n);

        // Initialize
        prefMax[0] = nums[0];
        sufMin[n - 1] = nums[n - 1];

        // Build prefix max and suffix min
        for(int i = 1; i < n; i++) {
            const int x = nums[i];
            const int y = nums[n - 1 - i];

            prefMax[i] = max(prefMax[i - 1], x);
            sufMin[n - 1 - i] = min(sufMin[n - i], y);
        }

        // Build answer array
        vector<int> ans(n);

        ans[n - 1] = prefMax[n - 1];

        for(int i = n - 2; i >= 0; i--) {
            if(prefMax[i] > sufMin[i + 1])
                ans[i] = ans[i + 1];
            else
                ans[i] = prefMax[i];
        }

        return ans;
    }
};
☕ Java Solution
class Solution {
    public int[] maxValue(int[] nums) {
        int n = nums.length;

        int[] prefMax = new int[n];
        int[] sufMin = new int[n];

        prefMax[0] = nums[0];
        sufMin[n - 1] = nums[n - 1];

        // Build prefix max and suffix min
        for(int i = 1; i < n; i++) {
            prefMax[i] = Math.max(prefMax[i - 1], nums[i]);
            sufMin[n - 1 - i] = Math.min(sufMin[n - i], nums[n - 1 - i]);
        }

        int[] ans = new int[n];
        ans[n - 1] = prefMax[n - 1];

        // Build answer
        for(int i = n - 2; i >= 0; i--) {
            if(prefMax[i] > sufMin[i + 1])
                ans[i] = ans[i + 1];
            else
                ans[i] = prefMax[i];
        }

        return ans;
    }
}
🐍 Python Solution
class Solution:
    def maxValue(self, nums):
        n = len(nums)

        prefMax = [0] * n
        sufMin = [0] * n

        prefMax[0] = nums[0]
        sufMin[-1] = nums[-1]

        # Build prefix max and suffix min
        for i in range(1, n):
            prefMax[i] = max(prefMax[i - 1], nums[i])
            sufMin[n - 1 - i] = min(sufMin[n - i], nums[n - 1 - i])

        ans = [0] * n
        ans[-1] = prefMax[-1]

        # Build answer
        for i in range(n - 2, -1, -1):
            if prefMax[i] > sufMin[i + 1]:
                ans[i] = ans[i + 1]
            else:
                ans[i] = prefMax[i]

        return ans
⏱️ Complexity Analysis
Time Complexity: O(n)
Space Complexity: O(n)
