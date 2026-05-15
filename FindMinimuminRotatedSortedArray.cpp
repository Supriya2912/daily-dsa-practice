# 🔍 Find Minimum in Rotated Sorted Array

## 🧩 Problem Statement

You are given a **rotated sorted array** `nums` of unique integers.

The array was originally sorted in ascending order but then rotated between `1` and `n` times.

Return the **minimum element** in the array.

---

## 📥 Input

- `nums` → a rotated sorted integer array

## 📤 Output

- The smallest element in the array

---

## 🧪 Example

### Input

```text
nums = [3,4,5,1,2]
Output
1
Explanation

Original sorted array:

[1,2,3,4,5]

After rotation:

[3,4,5,1,2]

Minimum element = 1

💡 Approach (Sorting)

This solution sorts the array again and returns the first element.

Steps:
Sort the array in ascending order.
Return the first element (nums[0]), which will be the minimum.
✅ C++ Solution
class Solution {
public:
    int findMin(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = nums[0];
        return ans;
    }
};
☕ Java Solution
import java.util.Arrays;

class Solution {
    public int findMin(int[] nums) {
        Arrays.sort(nums);
        return nums[0];
    }
}
🐍 Python Solution
class Solution:
    def findMin(self, nums):
        nums.sort()
        return nums[0]
⏱️ Complexity Analysis
Current Solution:
Time Complexity: O(n log n) (due to sorting)
Space Complexity: O(1) or O(log n) depending on sorting implementation
