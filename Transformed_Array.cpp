# Transformed Array

## Problem Statement
Given an integer array `nums` of size `n`, construct a transformed array `result` such that:


result[i] = nums[(i + nums[i]) mod n]
  
The modulo operation must correctly handle **negative values**.

---

## Approach
For every index `i`:
- Compute the target index using a **safe modulo formula** to avoid negative indices:
((i + nums[i]) % n + n) % n
  - Assign `nums[targetIndex]` to `result[i]`.

This guarantees the index always lies in the range `[0, n - 1]`.

---

## Example

**Input**

  nums = [3, -2, 1, 1]
  
**Output**

  [1, 1, 1, 3]

  
---

## C++ Implementation

```cpp
class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        for (int i = 0; i < n; i++) {
            int targetIdx = ((i + nums[i]) % n + n) % n;
            result[i] = nums[targetIdx];
        }

        return result;
    }
};
