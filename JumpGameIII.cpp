# 🎯 Jump Game III

## 🧩 Problem Statement

You are given:

- An integer array `arr`
- A starting index `start`

From index `i`, you can jump to:

- `i + arr[i]`
- `i - arr[i]`

Return **`true`** if you can reach **any index with value `0`**, otherwise return **`false`**.

---

## 📥 Input

- `arr` → integer array
- `start` → starting index

## 📤 Output

- `true` if a zero-value index is reachable
- `false` otherwise

---

## 🧪 Example

### Input
```text
arr = [4,2,3,0,3,1,2]
start = 5
Output
true
Explanation

Possible jumps:

5 → 4 → 1 → 3

At index 3, value is:

0

So the answer is true.

💡 Approach (BFS Traversal)

This problem can be modeled as a graph traversal problem.

Each index is a node.

From index i, there are at most 2 possible moves:

i - arr[i]
i + arr[i]

We use Breadth-First Search (BFS) to explore all reachable indices.

Step 1: Start BFS from start

Push the starting index into the queue.

Step 2: Visit neighbors

For each current index:

Compute left jump:
l = i - arr[i]
Compute right jump:
r = i + arr[i]

If valid and unvisited, add to queue.

Step 3: Stop when value is 0

If:

arr[i] == 0

Return:

true
✅ C++ Solution
constexpr int N = 5e4;

int q[N], front = 0, back = 0;
bool vis[N];

class Solution {
public:
    static bool canReach(vector<int>& arr, int start) {
        const int n = arr.size();

        // Reset queue
        front = back = 0;

        q[back++] = start;
        vis[start] = 1;

        while (front < back) {
            const int i = q[front++];
            const int x = arr[i];

            int l = i - x;
            int r = i + x;

            // Found zero
            if (x == 0) {
                memset(vis, 0, n);
                return true;
            }

            // Left jump
            if (l >= 0 && !vis[l]) {
                q[back++] = l;
                vis[l] = true;
            }

            // Right jump
            if (r < n && !vis[r]) {
                q[back++] = r;
                vis[r] = true;
            }
        }

        // Reset visited for next testcase
        memset(vis, 0, n);

        return false;
    }
};
☕ Java Solution
import java.util.*;

class Solution {
    public boolean canReach(int[] arr, int start) {
        int n = arr.length;

        Queue<Integer> q = new LinkedList<>();
        boolean[] vis = new boolean[n];

        q.offer(start);
        vis[start] = true;

        while (!q.isEmpty()) {
            int i = q.poll();

            if (arr[i] == 0)
                return true;

            int left = i - arr[i];
            int right = i + arr[i];

            if (left >= 0 && !vis[left]) {
                vis[left] = true;
                q.offer(left);
            }

            if (right < n && !vis[right]) {
                vis[right] = true;
                q.offer(right);
            }
        }

        return false;
    }
}
🐍 Python Solution
from collections import deque

class Solution:
    def canReach(self, arr, start):
        n = len(arr)
        q = deque([start])
        vis = [False] * n
        vis[start] = True

        while q:
            i = q.popleft()

            if arr[i] == 0:
                return True

            left = i - arr[i]
            right = i + arr[i]

            if left >= 0 and not vis[left]:
                vis[left] = True
                q.append(left)

            if right < n and not vis[right]:
                vis[right] = True
                q.append(right)

        return False
⏱️ Complexity Analysis
Time Complexity
O(n)

Each index is visited at most once.

Space Complexity
O(n)

For the queue and visited array.

🧠 Key Insight

Treat each index as a graph node.

Use BFS (or DFS) to explore reachable positions while avoiding revisits.

🚀 Tags

Array Graph BFS DFS

📌 Author
Supriya Biradar
