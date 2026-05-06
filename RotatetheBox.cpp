# 📦 Rotate the Box

## 🧩 Problem Statement

You are given an `m x n` matrix representing a box. Each cell contains one of the following:

- `'#'` → a stone  
- `'*'` → an obstacle  
- `'.'` → empty space  

The box is rotated **90 degrees clockwise**, and due to gravity:
- Stones (`#`) fall down until they hit:
  - another stone  
  - an obstacle (`*`)  
  - or the bottom  

Return the resulting box after rotation and gravity simulation.

---

## 📥 Input

- A 2D matrix `box` of size `m x n`

## 📤 Output

- A rotated matrix of size `n x m`

---

## 🧪 Example

### Input

box = [
['#', '.', '#'],
['#', '*', '.']
]


### Output

[
['#', '.'],
['#', '#'],
['*', '#']
]


---

## 💡 Approach

### Key Idea:
Instead of simulating gravity **after rotation**, we simulate it **while rotating**.

---

### 🔁 Step-by-Step

1. Create a result matrix of size `n x m`
2. Traverse each row from **right to left**
3. Maintain a pointer (`bottom`) where the next stone should fall
4. Rules:
   - If `'#'` → place at `bottom`, move pointer up
   - If `'*'` → place obstacle, reset `bottom`
   - If `'.'` → ignore

---

## ✅ C++ Solution

```cpp
class Solution {
public:
    static vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        const int r = box.size(), c = box[0].size();
        vector<vector<char>> rotate(c, vector<char>(r, '.'));

        for(int i = 0; i < r; i++){
            int bottom = c - 1;

            for(int j = c - 1; j >= 0; j--){
                if (box[i][j] == '#'){
                    rotate[bottom][r - 1 - i] = '#';
                    bottom--;
                }
                else if (box[i][j] == '*'){
                    rotate[j][r - 1 - i] = '*';
                    bottom = j - 1;
                }
            }
        }
        return rotate;
    }
};
⚡ Optimization (Fast I/O)
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
☕ Java Solution
class Solution {
    public char[][] rotateTheBox(char[][] box) {
        int r = box.length, c = box[0].length;
        char[][] result = new char[c][r];

        for (char[] row : result) {
            Arrays.fill(row, '.');
        }

        for (int i = 0; i < r; i++) {
            int bottom = c - 1;

            for (int j = c - 1; j >= 0; j--) {
                if (box[i][j] == '#') {
                    result[bottom][r - 1 - i] = '#';
                    bottom--;
                } else if (box[i][j] == '*') {
                    result[j][r - 1 - i] = '*';
                    bottom = j - 1;
                }
            }
        }
        return result;
    }
}
🐍 Python Solution
class Solution:
    def rotateTheBox(self, box):
        r, c = len(box), len(box[0])
        result = [['.' for _ in range(r)] for _ in range(c)]

        for i in range(r):
            bottom = c - 1

            for j in range(c - 1, -1, -1):
                if box[i][j] == '#':
                    result[bottom][r - 1 - i] = '#'
                    bottom -= 1
                elif box[i][j] == '*':
                    result[j][r - 1 - i] = '*'
                    bottom = j - 1

        return result
⏱️ Complexity Analysis
Time Complexity: O(m × n)
Space Complexity: O(m × n) (for rotated matrix)
