# ✅ Check if Array is a Good Array

## 🧩 Problem Statement

An array `nums` of length `n` is called **good** if:

- It contains every integer from **1 to n−1 exactly once**
- The number **n−1 appears twice**

In other words, after sorting, the array should look like:

```text
[1, 2, 3, ..., n-1, n-1]
Return true if the array is good, otherwise return false.

📥 Input
nums → integer array
📤 Output
true if the array is good
false otherwise
🧪 Example
Input
nums = [2, 1, 3, 3]
Output
true
Explanation

Sorted array:

[1, 2, 3, 3]

Contains:

1 once
2 once
3 twice

So it is a good array.

💡 Approach (Cyclic Sort)

Instead of sorting normally (O(n log n)), we can use cyclic sort to place each number in its correct index.

For any value v:

Correct index = v - 1

Example:

1 → index 0
2 → index 1
3 → index 2
Step 1: Place numbers at correct indices

Swap elements until each valid number is in its intended position.

while (nums[i] < n && nums[i] != nums[nums[i] - 1]) {
    swap(nums[i], nums[nums[i] - 1]);
}
Step 2: Validate first n-1 elements

Check whether:

nums[i] == i + 1

for all indices 0 to n-2.

Step 3: Check duplicate maximum

The last element must be:

n - 1

since that value should appear twice.

✅ C++ Solution
class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return false;

        // Place every element at its correct index
        // value v belongs at index v-1
        for (int i = 0; i < n; ++i) {
            while (nums[i] < n && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        // Check first n-1 elements: should be 1,2,3,...,n-1
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] - 1 != i)
                return false;
        }

        // Last element should be duplicate max
        return nums[n - 1] == n - 1;
    }
};
☕ Java Solution
class Solution {
    public boolean isGood(int[] nums) {
        int n = nums.length;
        if (n < 2) return false;

        for (int i = 0; i < n; i++) {
            while (nums[i] < n && nums[i] != nums[nums[i] - 1]) {
                int temp = nums[i];
                nums[i] = nums[temp - 1];
                nums[temp - 1] = temp;
            }
        }

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] != i + 1)
                return false;
        }

        return nums[n - 1] == n - 1;
    }
}
🐍 Python Solution
class Solution:
    def isGood(self, nums):
        n = len(nums)

        if n < 2:
            return False

        i = 0
        while i < n:
            while nums[i] < n and nums[i] != nums[nums[i] - 1]:
                correct = nums[i] - 1
                nums[i], nums[correct] = nums[correct], nums[i]
            i += 1

        for i in range(n - 1):
            if nums[i] != i + 1:
                return False

        return nums[n - 1] == n - 1
⏱️ Complexity Analysis
Time Complexity: O(n)
Space Complexity: O(1)
