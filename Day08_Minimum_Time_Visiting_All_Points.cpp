## Minimum Time Visiting All Points

### Problem
Given a sequence of points on a 2D plane, find the minimum time required to visit all points in order.

### Approach
- From one point to the next, the optimal move is diagonal when possible
- The minimum time is the maximum of horizontal and vertical distances

### Complexity
- Time Complexity: O(n)
- Space Complexity: O(1)

### Insight
Diagonal moves reduce both x and y distance simultaneously, so the maximum of the two distances determines the total time.


  ### solution:

  class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;

        for(int i = 0; i < points.size() - 1; i++){
            int currX = points[i][0];
            int currY = points[i][1];

            int targetX = points[i+1][0];
            int targetY = points[i+1][1];

            ans += max(abs(targetX - currX), abs(targetY - currY));
        }

        return ans;
    }
};
