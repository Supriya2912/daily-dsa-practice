# 🔍 Minimum Common Value

## 🧩 Problem Statement

You are given **two sorted integer arrays** `nums1` and `nums2`.

Return the **smallest integer that appears in both arrays**.  
If there is no common integer, return **`-1`**.

---

## 📥 Input

- `nums1` → sorted integer array
- `nums2` → sorted integer array

## 📤 Output

- The minimum common integer
- `-1` if no common value exists

---

## 🧪 Example

### Input

```text
nums1 = [1,2,3]
nums2 = [2,4]
Output
2
Explanation

The common elements are:

[2]

The smallest common value is 2.

💡 Approach (Two Pointers)

Since both arrays are already sorted, we can solve this efficiently using the two-pointer technique.

Idea
Start with pointers:
i = 0 for nums1
j = 0 for nums2
Compare:
If nums1[i] == nums2[j], we found the smallest common element.
If nums1[i] < nums2[j], move i forward.
Otherwise, move j forward.

Because arrays are sorted, the first match is guaranteed to be the minimum common value.

✅ C++ Solution
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;

        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j])
                return nums1[i];

            if (nums1[i] < nums2[j])
                i++;
            else
                j++;
        }

        return -1;
    }
};
☕ Java Solution
class Solution {
    public int getCommon(int[] nums1, int[] nums2) {
        int i = 0, j = 0;

        while (i < nums1.length && j < nums2.length) {
            if (nums1[i] == nums2[j])
                return nums1[i];

            if (nums1[i] < nums2[j])
                i++;
            else
                j++;
        }

        return -1;
    }
}
🐍 Python Solution
class Solution:
    def getCommon(self, nums1, nums2):
        i, j = 0, 0

        while i < len(nums1) and j < len(nums2):
            if nums1[i] == nums2[j]:
                return nums1[i]

            if nums1[i] < nums2[j]:
                i += 1
            else:
                j += 1

        return -1
⏱️ Complexity Analysis
Time Complexity
O(n + m)

Where:

n = length of nums1
m = length of nums2

Each pointer moves at most once through its array.

Space Complexity
O(1)

Only constant extra space is used.

🧠 Key Insight

Because both arrays are sorted, we can avoid brute force searching and use two pointers to efficiently find the first common element.

The first match is automatically the minimum common value.

🚀 Tags

Array Two Pointers Sorting

📌 Author
Supriya Biradar
