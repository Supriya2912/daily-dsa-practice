/*
LeetCode Problem of the Day: Maximum Matrix Sum

Approach:
- Take the absolute value of all elements and add them to get the maximum possible sum.
- Count the number of negative elements.
- Track the minimum absolute value in the matrix.
- If there is a zero OR the count of negative numbers is even,
  then we can make all elements positive.
- Otherwise, one element must remain negative, so subtract
  twice the minimum absolute value from the total sum.

Time Complexity: O(n * m)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int negCount = 0;
        int minAbs = INT_MAX;
        bool hasZero = false;

        for (auto &row : matrix) {
            for (int val : row) {
                if (val == 0) hasZero = true;
                if (val < 0) negCount++;

                sum += abs(val);
                minAbs = min(minAbs, abs(val));
            }
        }

        if (hasZero || negCount % 2 == 0)
            return sum;

        return sum - 2LL * minAbs;
    }
};
