# 🚀 Minimum Jumps Using Prime Factor Connections

## 🧩 Problem Statement

You are given an integer array `nums`.

You start from the last index `(n - 1)` and want to reach index `0` using the minimum number of jumps.

From index `i`, you can move to:

- `i - 1`
- `i + 1`
- Any index `j` such that:
  - `nums[i]` and `nums[j]` share a common prime factor

Return the minimum number of jumps required to reach index `0`.

---

# 📥 Input

- An integer array `nums`

# 📤 Output

- Minimum number of jumps required

---

# 🧪 Example
Explanation
15 shares prime factor 3 with 3
10 shares prime factor 2 with 6

Possible jumps become optimized using prime connections.

Output
2
💡 Approach

The solution combines:

Sieve of Eratosthenes
Prime Factor Mapping
Breadth First Search (BFS)

to efficiently compute the minimum jumps.

🔹 Step 1: Precompute Prime Numbers

Using the Sieve of Eratosthenes:

Mark non-prime numbers
Store all prime numbers
Map every prime to an index

This allows fast prime factor lookup.

🔹 Step 2: Build Prime → Indices Mapping

For every number in nums:

Find its prime factors
Store the index in:
mp[prime]

This helps quickly jump between indices sharing common factors.

🔹 Step 3: BFS Traversal

Start BFS from:

n - 1

At every index:

Move left
Move right
Move to all indices sharing prime factors

The first time we reach index 0, we return the distance.

✅ C++ Solution
constexpr int M = 1e6 + 1, N = 1e5 + 1;

bitset<M> sieve;

int pIdx[M] = {[0 ... (M - 1)] = -1};

vector<int> primes;

int sz = 0;

void Sieve() {
    if (sieve[0]) return;

    sieve[0] = sieve[1] = 1;

    primes.reserve(80000);

    for (int i = 2; i <= 1000; i += 1 + (i > 2)) {
        if (sieve[i]) continue;

        primes.push_back(i);

        pIdx[i] = sz++;

        for (int j = i * i; j < M; j += i)
            sieve[j] = 1;
    }

    for (int i = 1001; i < M; i += 2) {
        if (!sieve[i]) {
            pIdx[i] = sz++;
            primes.push_back(i);
        }
    }
}

vector<int> mp[80000];

class Solution {
public:

    static void reset(const bitset<80000>& used, int maxPidx) {
        for (int i = 0; i <= maxPidx; i++) {
            if (used[i]) mp[i].clear();
        }
    }

    static int minJumps(vector<int>& nums) {

        Sieve();

        const int n = nums.size();

        bitset<80000> used;

        int maxPidx = -1;

        // Build prime-index mapping
        for (int i = 0; i < n; i++) {

            const int x = nums[i];

            if (!sieve[x]) {
                int idx = pIdx[x];

                mp[idx].push_back(i);

                used[idx] = 1;

                maxPidx = max(idx, maxPidx);
            }
        }

        bitset<N> vis;

        queue<int> q;

        q.push(n - 1);

        vis[n - 1] = 1;

        // BFS
        for (int d = 0; !q.empty(); d++) {

            int qz = q.size();

            while (qz--) {

                auto i = q.front();

                q.pop();

                if (i == 0) {
                    reset(used, maxPidx);
                    return d;
                }

                int x = nums[i];

                // Move left
                if (i > 0 && !vis[i - 1]) {
                    vis[i - 1] = 1;
                    q.push(i - 1);
                }

                // Move right
                if (i < n - 1 && !vis[i + 1]) {
                    vis[i + 1] = 1;
                    q.push(i + 1);
                }

                // Prime factor jumps
                for (int j = 0; j < sz && x > 1; j++) {

                    int p = primes[j];

                    if (!sieve[x]) p = x;

                    if (x % p == 0) {

                        const int idx = pIdx[p];

                        while (x % p == 0)
                            x /= p;

                        for (auto& it : mp[idx]) {

                            if (!vis[it]) {
                                vis[it] = 1;
                                q.push(it);
                            }
                        }

                        used[idx] = 0;

                        mp[idx].clear();
                    }
                }
            }
        }

        return -1;
    }
};

// Fast I/O
auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
☕ Java Solution
import java.util.*;

class Solution {

    public int minJumps(int[] nums) {

        int n = nums.length;

        Map<Integer, List<Integer>> map = new HashMap<>();

        // Build factor mapping
        for (int i = 0; i < n; i++) {

            int x = nums[i];

            for (int p = 2; p * p <= x; p++) {

                if (x % p == 0) {

                    map.computeIfAbsent(p, k -> new ArrayList<>()).add(i);

                    while (x % p == 0)
                        x /= p;
                }
            }

            if (x > 1)
                map.computeIfAbsent(x, k -> new ArrayList<>()).add(i);
        }

        Queue<Integer> q = new LinkedList<>();

        boolean[] vis = new boolean[n];

        q.offer(n - 1);

        vis[n - 1] = true;

        int steps = 0;

        while (!q.isEmpty()) {

            int size = q.size();

            while (size-- > 0) {

                int i = q.poll();

                if (i == 0)
                    return steps;

                if (i > 0 && !vis[i - 1]) {
                    vis[i - 1] = true;
                    q.offer(i - 1);
                }

                if (i < n - 1 && !vis[i + 1]) {
                    vis[i + 1] = true;
                    q.offer(i + 1);
                }

                int x = nums[i];

                for (int p = 2; p * p <= x; p++) {

                    if (x % p == 0) {

                        if (map.containsKey(p)) {

                            for (int idx : map.get(p)) {

                                if (!vis[idx]) {
                                    vis[idx] = true;
                                    q.offer(idx);
                                }
                            }

                            map.remove(p);
                        }

                        while (x % p == 0)
                            x /= p;
                    }
                }

                if (x > 1 && map.containsKey(x)) {

                    for (int idx : map.get(x)) {

                        if (!vis[idx]) {
                            vis[idx] = true;
                            q.offer(idx);
                        }
                    }

                    map.remove(x);
                }
            }

            steps++;
        }

        return -1;
    }
}
🐍 Python Solution
from collections import defaultdict, deque

class Solution:
    def minJumps(self, nums):

        n = len(nums)

        factor_map = defaultdict(list)

        # Build factor mapping
        for i, x in enumerate(nums):

            temp = x
            p = 2

            while p * p <= temp:

                if temp % p == 0:

                    factor_map[p].append(i)

                    while temp % p == 0:
                        temp //= p

                p += 1

            if temp > 1:
                factor_map[temp].append(i)

        q = deque([n - 1])

        vis = [False] * n

        vis[n - 1] = True

        steps = 0

        while q:

            for _ in range(len(q)):

                i = q.popleft()

                if i == 0:
                    return steps

                # Left move
                if i > 0 and not vis[i - 1]:
                    vis[i - 1] = True
                    q.append(i - 1)

                # Right move
                if i < n - 1 and not vis[i + 1]:
                    vis[i + 1] = True
                    q.append(i + 1)

                x = nums[i]

                p = 2

                while p * p <= x:

                    if x % p == 0:

                        for idx in factor_map[p]:

                            if not vis[idx]:
                                vis[idx] = True
                                q.append(idx)

                        factor_map[p].clear()

                        while x % p == 0:
                            x //= p

                    p += 1

                if x > 1:

                    for idx in factor_map[x]:

                        if not vis[idx]:
                            vis[idx] = True
                            q.append(idx)

                    factor_map[x].clear()

            steps += 1

        return -1
⏱️ Complexity Analysis
Time Complexity: O(N log M)
BFS traversal
Prime factorization
Space Complexity: O(N + M)

Where:

N = size of array
M = maximum number value



## Input
```text
nums = [15, 10, 3, 6]
