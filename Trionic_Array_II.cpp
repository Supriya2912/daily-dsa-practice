## Trionic Array II

### Problem
Given an integer array, find the **maximum possible sum of a trionic subarray**.

A trionic array consists of:
1. A strictly increasing segment
2. Followed by a strictly decreasing segment
3. Followed by another strictly increasing segment

Each segment must contain at least one element.

---

### Approach (Dynamic Programming)

We track three DP states while iterating through the array:

- `a` → maximum sum of the **first increasing** segment
- `b` → maximum sum of the **decreasing** segment
- `c` → maximum sum of the **second increasing** segment

At each index, transitions depend on whether the current element is:
- Increasing (`nums[i] > nums[i-1]`)
- Decreasing (`nums[i] < nums[i-1]`)

We update the states accordingly and keep track of the maximum valid trionic sum.

---

### State Transitions

- If increasing:
  - Extend first increasing (`a`)
  - Extend third increasing (`c`)
- If decreasing:
  - Extend decreasing (`b`)

Only valid transitions are allowed to maintain trionic order.

---

### Complexity
- Time: **O(n)**
- Space: **O(1)**

---

### Key Insight
This problem generalizes the pattern from **Trionic Array I** by adding a **maximum sum constraint**, making it a classic multi-state DP problem.

---

### Example
Input:  [1, 4, 7, 3, 2, 6, 9]  
Output: Maximum sum of a valid trionic subarray


##solution:

class Solution {
public:
    long long maxSumTrionic(const vector<int>& nums) {
        const long long INF = -1e17;

        // a -> increasing phase
        // b -> decreasing phase
        // c -> second increasing phase
        long long result = INF;
        long long a = INF, b = INF, c = INF;

        long long prev = nums[0];

        for (size_t i = 1; i < nums.size(); i++) {
            long long curr = nums[i];
            long long na = INF, nb = INF, nc = INF;

            if (curr > prev) {
                // increasing: first or third phase
                na = max(a, prev) + curr;
                nc = max(b, c) + curr;
            } 
            else if (curr < prev) {
                // decreasing: second phase
                nb = max(a, b) + curr;
            }

            a = na;
            b = nb;
            c = nc;

            result = max(result, c);
            prev = curr;
        }

        return result;
    }
};


