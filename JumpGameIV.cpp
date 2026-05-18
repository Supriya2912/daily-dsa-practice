# 🔄 Jump Game IV

## 🧩 Problem Statement

You are given an integer array `arr`.

From index `i`, you can jump to:

- `i + 1` (if within bounds)
- `i - 1` (if within bounds)
- Any index `j` where:

```text
arr[i] == arr[j] and i != j
Return the minimum number of jumps required to reach the last index starting from index 0.

📥 Input
arr → integer array
📤 Output
Minimum number of jumps to reach the last index
🧪 Example
Input
arr = [100,-23,-23,404,100,23,23,23,3,404]
Output
3
Explanation

One optimal path:

0 → 4 → 3 → 9
0 → 4 (same value: 100)
4 → 3 (adjacent jump)
3 → 9 (same value: 404)

Minimum jumps = 3

💡 Approach (Breadth-First Search)

This is a shortest path problem, so BFS is ideal.

Each index is treated as a node.

Possible moves from index i:

i - 1
i + 1
Any index with the same value
Step 1: Build value → indices map

Store all indices for each number:

unordered_map<int, vector<int>> dict;

Example:

100 → [0,4]
404 → [3,9]

This allows fast same-value jumps.

Step 2: Perform BFS

Start from index 0.

Use a queue to explore all reachable indices level by level.

Each BFS level represents one jump.

Step 3: Avoid revisiting

Use a visited array:

bitset<N> vis;

to prevent cycles.

Step 4: Clear processed same-value lists

After using:

dict[arr[cur]]

clear it:

dict[arr[cur]].clear();

This avoids repeatedly traversing the same indices and improves efficiency.

✅ C++ Solution
constexpr int N = 5e4 + 1;

bitset<N> vis;
int q[N], front = 0, back = 0;

class Solution {
public:
    static int minJumps(vector<int>& arr) {
        const int n = arr.size();

        vis.reset();

        unordered_map<int, vector<int>> dict;
        dict.reserve(n);

        // Build map: value -> all indices
        for (int i = 0; i < n; i++)
            dict[arr[i]].push_back(i);

        front = back = 0;
        q[back++] = 0;
        vis[0] = 1;

        int step = 0;

        while (front < back) {
            int s = back - front;

            while (s--) {
                int cur = q[front++];

                // Reached destination
                if (cur == n - 1)
                    return step;

                // Jump left
                if (cur - 1 >= 0 && !vis[cur - 1]) {
                    q[back++] = cur - 1;
                    vis[cur - 1] = 1;
                }

                // Jump right
                if (cur + 1 < n && !vis[cur + 1]) {
                    q[back++] = cur + 1;
                    vis[cur + 1] = 1;
                }

                // Same-value jumps
                for (int idx : dict[arr[cur]]) {
                    if (!vis[idx]) {
                        q[back++] = idx;
                        vis[idx] = 1;
                    }
                }

                // Prevent repeated processing
                dict[arr[cur]].clear();
            }

            step++;
        }

        return -1;
    }
};
☕ Java Solution
import java.util.*;

class Solution {
    public int minJumps(int[] arr) {
        int n = arr.length;

        Map<Integer, List<Integer>> map = new HashMap<>();

        for (int i = 0; i < n; i++) {
            map.computeIfAbsent(arr[i], k -> new ArrayList<>()).add(i);
        }

        Queue<Integer> q = new LinkedList<>();
        boolean[] vis = new boolean[n];

        q.offer(0);
        vis[0] = true;

        int steps = 0;

        while (!q.isEmpty()) {
            int size = q.size();

            while (size-- > 0) {
                int cur = q.poll();

                if (cur == n - 1)
                    return steps;

                if (cur - 1 >= 0 && !vis[cur - 1]) {
                    vis[cur - 1] = true;
                    q.offer(cur - 1);
                }

                if (cur + 1 < n && !vis[cur + 1]) {
                    vis[cur + 1] = true;
                    q.offer(cur + 1);
                }

                for (int idx : map.get(arr[cur])) {
                    if (!vis[idx]) {
                        vis[idx] = true;
                        q.offer(idx);
                    }
                }

                map.get(arr[cur]).clear();
            }

            steps++;
        }

        return -1;
    }
}
🐍 Python Solution
from collections import defaultdict, deque

class Solution:
    def minJumps(self, arr):
        n = len(arr)

        graph = defaultdict(list)
        for i, num in enumerate(arr):
            graph[num].append(i)

        q = deque([0])
        visited = {0}
        steps = 0

        while q:
            for _ in range(len(q)):
                cur = q.popleft()

                if cur == n - 1:
                    return steps

                for nxt in [cur - 1, cur + 1]:
                    if 0 <= nxt < n and nxt not in visited:
                        visited.add(nxt)
                        q.append(nxt)

                for idx in graph[arr[cur]]:
                    if idx not in visited:
                        visited.add(idx)
                        q.append(idx)

                graph[arr[cur]].clear()

            steps += 1

        return -1
⏱️ Complexity Analysis
Time Complexity
O(n)

Each index is processed once, and same-value groups are cleared after use.

Space Complexity
O(n)

For queue, visited array, and hashmap.

🧠 Key Insight

Use BFS for shortest path.

The optimization:

dict[arr[cur]].clear();

is crucial—it prevents repeated same-value traversals and keeps the solution efficient.

🚀 Tags

Array HashMap Graph BFS

📌 Author
Supriya Biradar
