## Largest Magic Square

### Problem
Find the largest square subgrid where all rows, columns, and both diagonals
have the same sum.

### Approach
- Precompute row and column prefix sums
- Iterate from largest possible square to smallest
- For each square:
  - Check all row sums
  - Check all column sums
  - Check both diagonals

### Optimization
Prefix sums reduce row/column checks to O(1).

### Complexity
- Time: O(min(n,m)³)
- Space: O(n × m)

## Solution:
class Solution {
public:
    bool isMagicSquare(int i, int j, int side, vector<vector<int>>& rowSum,
                       vector<vector<int>>& colSum, vector<vector<int>>& grid) {

        int targetSum =
            rowSum[i][j + side - 1] - (j > 0 ? rowSum[i][j - 1] : 0);
        bool flag = true;
        for (int row = i + 1; row < i + side; row++) {
            int currSum =
                rowSum[row][j + side - 1] - (j > 0 ? rowSum[row][j - 1] : 0);
            if (currSum != targetSum) {
                flag = false;
                break;
            }
        }
        if (!flag) {
            return false;
        }
        for (int col = j; col < j + side; col++) {
            int currSum =
                colSum[i + side - 1][col] - (i > 0 ? colSum[i - 1][col] : 0);
            if (currSum != targetSum) {
                flag = false;
                break;
            }
        }
        if (!flag) {
            return false;
        }
        int diagSum = 0;
        int antiDiagSum = 0;
        for (int k = 0; k < side; k++) {
            diagSum += grid[i + k][j + k];
            antiDiagSum += grid[i + k][j + side - 1 - k];
        }
        if (diagSum != targetSum || antiDiagSum != targetSum) {
            return false;
        }
        return true;
    }
    int largestMagicSquare(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> rowSum(n, vector<int>(m, 0));
        vector<vector<int>> colSum(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            rowSum[i][0] = grid[i][0];
            for (int j = 1; j < m; j++) {
                rowSum[i][j] = rowSum[i][j - 1] + grid[i][j];
            }
        }
        for (int j = 0; j < m; j++) {
            colSum[0][j] = grid[0][j];
            for (int i = 1; i < n; i++) {
                colSum[i][j] = colSum[i - 1][j] + grid[i][j];
            }
        }

        for (int side = min(n, m); side >= 2; side--) {
            for (int i = 0; i + side - 1 < n; i++) {
                for (int j = 0; j + side - 1 < m; j++) {
                    if (isMagicSquare(i, j, side, rowSum, colSum, grid)) {
                        return side;
                    }
                }
            }
        }
        return 1;
    }
};
