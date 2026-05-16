# 🔍 Find Minimum in Rotated Sorted Array

## 🧩 Problem Statement

You are given a **rotated sorted array** `nums` containing **unique integers**.

The array was originally sorted in ascending order but then rotated at some pivot.

Your task is to return the **minimum element** in the array.

---

## 📥 Input

- `nums` → a rotated sorted integer array

## 📤 Output

- The minimum element in the array

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

The smallest element is 1.

💡 Approach (Sorting)

This solution uses a simple approach:

Sort the array in ascending order.
Return the first element, which will be the minimum.

Since sorting places all elements in order, the smallest number will be at index 0.

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
Time Complexity
O(n log n)

Sorting the array takes O(n log n) time.

Space Complexity
O(1)

Extra space is constant (ignoring sorting internals).
