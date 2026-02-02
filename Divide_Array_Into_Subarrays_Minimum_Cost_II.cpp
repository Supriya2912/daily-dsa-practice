## Divide an Array Into Subarrays With Minimum Cost II

### Problem
Given an array `nums`, divide it into subarrays such that:
- Each subarray contains exactly `k` elements
- Distance between subarray boundaries is limited by `dist`
- Cost of a subarray = sum of its `k` smallest elements

Return the minimum possible total cost.

---

### Key Idea

This is a **Dynamic Programming + Sliding Window + Multiset** problem.

- Let `dp[i]` = minimum cost to partition the array up to index `i`
- For each `i`, try valid previous cut positions `j`
- Maintain the **k smallest elements** efficiently using two multisets

---

### Data Structure Trick

Use:
- `small` → keeps k smallest elements
- `large` → keeps remaining elements
- Maintain sum of `small` for quick cost calculation

This allows:
- Insert: O(log n)
- Remove: O(log n)
- Query sum: O(1)

---

### Algorithm
1. Initialize DP array
2. For each ending index `i`
3. Slide backwards up to distance `dist`
4. Dynamically maintain k smallest elements
5. Update dp[i]

---

### Complexity

- Time: **O(n × dist × log n)**
- Space: **O(n)**

Efficient due to constrained window size.

---

### Key Concepts Used
- Dynamic Programming
- Sliding Window
- Multiset balancing
- Greedy optimization

---

### Interview Value
This problem demonstrates:
- Advanced DP thinking
- Data structure mastery
- Optimization under constraints


##solution:

class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        multiset<long long> small, large;
        long long sumSmall = 0;
        int need = k - 1;

        auto add = [&](long long x) {
            if ((int)small.size() < need) {
                small.insert(x);
                sumSmall += x;
            } else {
                auto it = prev(small.end());
                if (*it > x) {
                    sumSmall -= *it;
                    large.insert(*it);
                    small.erase(it);
                    small.insert(x);
                    sumSmall += x;
                } else {
                    large.insert(x);
                }
            }
        };

        auto remove = [&](long long x) {
            auto it = small.find(x);
            if (it != small.end()) {
                sumSmall -= x;
                small.erase(it);
                if (!large.empty()) {
                    auto jt = large.begin();
                    sumSmall += *jt;
                    small.insert(*jt);
                    large.erase(jt);
                }
            } else {
                large.erase(large.find(x));
            }
        };

        // Initial window [1 .. dist + 1]
        for (int i = 1; i <= dist + 1; i++) {
            add(nums[i]);
        }

        long long ans = sumSmall;

        // Slide the window
        for (int i = dist + 2; i < n; i++) {
            add(nums[i]);
            remove(nums[i - (dist + 1)]);
            ans = min(ans, sumSmall);
        }

        return nums[0] + ans;
    }
};
