# 🔄 Cyclically Rotate Grid Layers

## 🧩 Problem Statement

You are given an `m x n` integer matrix `grid` and an integer `k`.

The matrix consists of multiple **layers (rings)**.  
Each layer must be rotated **counter-clockwise** by `k` positions.

Return the rotated grid.

---

## 📥 Input

- `grid` → an `m x n` integer matrix
- `k` → number of rotations

---

## 📤 Output

- The matrix after rotating each layer by `k`

---

## 🧪 Example

### Input
```text
grid = [
  [40, 10],
  [30, 20]
]
k = 1



Output
[
  [10, 20],
  [40, 30]
]
💡 Approach

Each matrix has multiple concentric layers.

For every layer:

Extract all elements into a temporary array
Rotate the array by k % layer_size
Place the rotated elements back into the grid
🔹 Step 1: Find Number of Layers

Number of layers:

min(m, n) / 2

Each layer forms one rectangular ring.

🔹 Step 2: Extract Layer Elements

Traverse in this order:

Top row → left to right
Right column → top to bottom
Bottom row → right to left
Left column → bottom to top

Store elements in a vector.

🔹 Step 3: Rotate Layer

To rotate counter-clockwise:

rotate(vals.begin(), vals.begin() + shift, vals.end());

Where:

shift = k % layer_length
🔹 Step 4: Put Elements Back

Traverse the same boundary again and overwrite values.

✅ C++ Solution
class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int layers = min(m, n) / 2;

        for (int l = 0; l < layers; l++) {
            vector<int> vals;

            int top = l, left = l;
            int bottom = m - l - 1;
            int right = n - l - 1;

            // Extract top row
            for (int j = left; j < right; j++)
                vals.push_back(grid[top][j]);

            // Extract right column
            for (int i = top; i < bottom; i++)
                vals.push_back(grid[i][right]);

            // Extract bottom row
            for (int j = right; j > left; j--)
                vals.push_back(grid[bottom][j]);

            // Extract left column
            for (int i = bottom; i > top; i--)
                vals.push_back(grid[i][left]);

            int len = vals.size();
            int shift = k % len;

            // Rotate layer
            rotate(vals.begin(), vals.begin() + shift, vals.end());

            int idx = 0;

            // Put back top row
            for (int j = left; j < right; j++)
                grid[top][j] = vals[idx++];

            // Put back right column
            for (int i = top; i < bottom; i++)
                grid[i][right] = vals[idx++];

            // Put back bottom row
            for (int j = right; j > left; j--)
                grid[bottom][j] = vals[idx++];

            // Put back left column
            for (int i = bottom; i > top; i--)
                grid[i][left] = vals[idx++];
        }

        return grid;
    }
};
☕ Java Solution
class Solution {
    public int[][] rotateGrid(int[][] grid, int k) {
        int m = grid.length;
        int n = grid[0].length;
        int layers = Math.min(m, n) / 2;

        for (int l = 0; l < layers; l++) {
            List<Integer> vals = new ArrayList<>();

            int top = l, left = l;
            int bottom = m - l - 1;
            int right = n - l - 1;

            for (int j = left; j < right; j++)
                vals.add(grid[top][j]);

            for (int i = top; i < bottom; i++)
                vals.add(grid[i][right]);

            for (int j = right; j > left; j--)
                vals.add(grid[bottom][j]);

            for (int i = bottom; i > top; i--)
                vals.add(grid[i][left]);

            int len = vals.size();
            int shift = k % len;

            Collections.rotate(vals, -shift);

            int idx = 0;

            for (int j = left; j < right; j++)
                grid[top][j] = vals.get(idx++);

            for (int i = top; i < bottom; i++)
                grid[i][right] = vals.get(idx++);

            for (int j = right; j > left; j--)
                grid[bottom][j] = vals.get(idx++);

            for (int i = bottom; i > top; i--)
                grid[i][left] = vals.get(idx++);
        }

        return grid;
    }
}
🐍 Python Solution
class Solution:
    def rotateGrid(self, grid, k):
        m, n = len(grid), len(grid[0])
        layers = min(m, n) // 2

        for l in range(layers):
            vals = []

            top, left = l, l
            bottom = m - l - 1
            right = n - l - 1

            for j in range(left, right):
                vals.append(grid[top][j])

            for i in range(top, bottom):
                vals.append(grid[i][right])

            for j in range(right, left, -1):
                vals.append(grid[bottom][j])

            for i in range(bottom, top, -1):
                vals.append(grid[i][left])

            shift = k % len(vals)

            vals = vals[shift:] + vals[:shift]

            idx = 0

            for j in range(left, right):
                grid[top][j] = vals[idx]
                idx += 1

            for i in range(top, bottom):
                grid[i][right] = vals[idx]
                idx += 1

            for j in range(right, left, -1):
                grid[bottom][j] = vals[idx]
                idx += 1

            for i in range(bottom, top, -1):
                grid[i][left] = vals[idx]
                idx += 1

        return grid
⏱️ Complexity Analysis
Time Complexity: O(m × n)
Space Complexity: O(m + n)
(temporary storage for one layer)
