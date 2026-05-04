# 🔄 Rotate Image (90 Degrees Clockwise)

## 🧩 Problem Statement

Given an `n x n` 2D matrix representing an image, rotate the image by **90 degrees clockwise**.

You must rotate the image **in-place**, meaning you cannot use another matrix.

---

## 📥 Input

- A 2D square matrix `matrix` of size `n x n`

## 📤 Output

- The same matrix rotated by 90 degrees clockwise (modified in-place)

---

## 🧪 Example

### Input
matrix = [
[1, 2, 3],
[4, 5, 6],
[7, 8, 9]
]

### Output
[
[7, 4, 1],
[8, 5, 2],
[9, 6, 3]
]


---

## 💡 Approach

To rotate the matrix by 90° clockwise **in-place**, we follow two main steps:

### 🔁 Step 1: Transpose the Matrix

- Convert rows into columns
- Swap `matrix[i][j]` with `matrix[j][i]` for all `i < j`

**After transpose:**

[
[1, 4, 7],
[2, 5, 8],
[3, 6, 9]
]


---

### 🔄 Step 2: Reverse Each Row

- Reverse every row of the matrix

**After reversing rows:**

[
[7, 4, 1],
[8, 5, 2],
[9, 6, 3]
]


---

## ✅ C++ Solution

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Step 1: Transpose
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Step 2: Reverse each row
        for(int k = 0; k < n; k++){
            int i = 0, j = n - 1;
            while(i < j) { 
                swap(matrix[k][i], matrix[k][j]);
                i++;
                j--;
            }
        }
    }
};

Complexity Analysis
Time Complexity: O(n²)
Space Complexity: O(1) (In-place)

  Java solution :
class Solution {
    public void rotate(int[][] matrix) {
        int n = matrix.length;

        // Transpose
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }

        // Reverse each row
        for (int k = 0; k < n; k++) {
            int i = 0, j = n - 1;
            while (i < j) {
                int temp = matrix[k][i];
                matrix[k][i] = matrix[k][j];
                matrix[k][j] = temp;
                i++;
                j--;
            }
        }
    }
}



## python solution:

class Solution:
    def rotate(self, matrix):
        n = len(matrix)

        # Transpose
        for i in range(n):
            for j in range(i + 1, n):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

        # Reverse each row
        for row in matrix:
            row.reverse()
  
