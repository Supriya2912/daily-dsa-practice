# 🔢 Find the Prefix Common Array of Two Arrays

## 🧩 Problem Statement

You are given two **integer arrays** `A` and `B` of length `n`, both being **permutations of integers from `1` to `n`**.

For each index `i`, define the **prefix common count** as the number of integers that appear in **both**:

- `A[0...i]`
- `B[0...i]`

Return an array `ans` where:

```text
ans[i] = number of common elements in prefixes A[0...i] and B[0...i]
📥 Input
A → integer array (permutation of 1...n)
B → integer array (permutation of 1...n)
📤 Output
An integer array ans representing prefix common counts
🧪 Example
Input
A = [1,3,2,4]
B = [3,1,2,4]
Output
[0,2,3,4]
Explanation
Index	Prefix A	Prefix B	Common Elements	Count
0	[1]	[3]	{}	0
1	[1,3]	[3,1]	{1,3}	2
2	[1,3,2]	[3,1,2]	{1,2,3}	3
3	[1,3,2,4]	[3,1,2,4]	{1,2,3,4}	4

So:

ans = [0,2,3,4]
💡 Approach (Bitset Tracking)

Since values range only from 1 to 50, we can efficiently track seen elements using bitsets.

Idea

Maintain two bitsets:

x → numbers seen in A
y → numbers seen in B

For each index:

Mark current values as seen
Compute:
(x & y).count()

This gives the number of common elements in both prefixes.

✅ C++ Solution
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        const int n = A.size();

        bitset<51> x = 0, y = 0;
        vector<int> ans(n, 0);

        for (int i = 0; i < n; i++) {
            int a = A[i];
            int b = B[i];

            x[a] = 1;
            y[b] = 1;

            ans[i] = (x & y).count();
        }

        return ans;
    }
};
☕ Java Solution
class Solution {
    public int[] findThePrefixCommonArray(int[] A, int[] B) {
        int n = A.length;
        boolean[] seenA = new boolean[51];
        boolean[] seenB = new boolean[51];
        int[] ans = new int[n];

        for (int i = 0; i < n; i++) {
            seenA[A[i]] = true;
            seenB[B[i]] = true;

            int count = 0;
            for (int j = 1; j <= 50; j++) {
                if (seenA[j] && seenB[j])
                    count++;
            }

            ans[i] = count;
        }

        return ans;
    }
}
🐍 Python Solution
class Solution:
    def findThePrefixCommonArray(self, A, B):
        seenA = set()
        seenB = set()
        ans = []

        for a, b in zip(A, B):
            seenA.add(a)
            seenB.add(b)

            ans.append(len(seenA & seenB))

        return ans
⏱️ Complexity Analysis
Time Complexity
O(n)

Each step performs constant-time bit operations.

Space Complexity
O(1)

Bitsets use fixed size (51), independent of input size.

🧠 Key Insight

Using bitsets allows fast set intersection:

(x & y).count()

This efficiently computes how many numbers are common in both prefixes at every step.

🚀 Tags

Array Bit Manipulation Bitset Prefix

📌 Author
Supriya Biradar
