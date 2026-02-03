## Trionic Array I

### Problem
An array is called **trionic** if it consists of:
1. A strictly increasing sequence
2. Followed by a strictly decreasing sequence
3. Followed by another strictly increasing sequence

Each part must have **at least one element**.

Return `true` if the array is trionic, otherwise `false`.

---

### Approach

Use a single pointer to traverse the array in three phases:

1. Move forward while the array is strictly increasing
2. Then move while it is strictly decreasing
3. Finally move while it is strictly increasing again

Ensure:
- Each phase has at least one valid step
- The traversal ends exactly at the last index

---

### Key Checks
- Array length must be ≥ 4
- No phase can be empty
- Comparisons must be strictly `<` or `>`

---

### Complexity
- Time: O(n)
- Space: O(1)

---

### Example
Input:  [1, 3, 5, 4, 2, 6, 8]  
Output: true

Explanation:
Increasing → Decreasing → Increasing




### solution:

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n < 4) return false;

        int i = 0;

        // First increasing part
        while (i + 1 < n && nums[i] < nums[i + 1]) {
            i++;
        }
        if (i == 0 || i == n - 1) return false;

        int peak = i;

        // Decreasing part
        while (i + 1 < n && nums[i] > nums[i + 1]) {
            i++;
        }
        if (i == peak || i == n - 1) return false;

        // Final increasing part
        while (i + 1 < n && nums[i] < nums[i + 1]) {
            i++;
        }

        return i == n - 1;
    }
};





