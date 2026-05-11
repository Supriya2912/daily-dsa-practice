# 🔢 Separate the Digits in an Array

## 🧩 Problem Statement

You are given an integer array `nums`.

Your task is to **separate every digit** of each number in the same order and return a new array containing all digits individually.

---

## 📥 Input

- `nums` → an integer array

## 📤 Output

- A new array containing every digit of each number

---

## 🧪 Example

### Input

```text
nums = [13, 25, 83, 77]
Output
[1, 3, 2, 5, 8, 3, 7, 7]
Explanation
13 → [1, 3]
25 → [2, 5]
83 → [8, 3]
77 → [7, 7]

Combined result:

[1, 3, 2, 5, 8, 3, 7, 7]
💡 Approach

For each number:

Find its highest digit place value (1, 10, 100...)
Extract digits one by one using:
digit = x / place
x = x % place
Append each digit to the answer array.
🔹 Optimization

We predefine powers of 10:

int tens[6] = {1, 10, 100, 1000, 10000, 100000};

Using upper_bound(), we quickly find the largest place value for each number.

This avoids converting numbers to strings.

✅ C++ Solution
int tens[6] = {1, 10, 100, 1000, 10000, 100000};

class Solution {
public:
    vector<int> ans;

    inline void add2Ans(int x) {
        int d = upper_bound(tens, tens + 6, x) - tens - 1;

        for (int i = d; i >= 0; i--) {
            auto [q, r] = div(x, tens[i]);
            ans.push_back(q);
            x = r;
        }
    }

    vector<int> separateDigits(vector<int>& nums) {
        const int n = nums.size();

        ans.reserve(n * 6);

        for (int x : nums)
            add2Ans(x);

        return ans;
    }
};
☕ Java Solution
import java.util.*;

class Solution {
    public int[] separateDigits(int[] nums) {
        List<Integer> result = new ArrayList<>();

        for (int num : nums) {
            String s = String.valueOf(num);

            for (char c : s.toCharArray()) {
                result.add(c - '0');
            }
        }

        return result.stream().mapToInt(i -> i).toArray();
    }
}
🐍 Python Solution
class Solution:
    def separateDigits(self, nums):
        result = []

        for num in nums:
            for digit in str(num):
                result.append(int(digit))

        return result
⏱️ Complexity Analysis
Time Complexity: O(n × d)
n = number of elements
d = number of digits per number
Space Complexity: O(n × d)
