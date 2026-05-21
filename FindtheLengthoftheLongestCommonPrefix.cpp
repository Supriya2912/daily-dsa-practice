# 🔢 Find the Length of the Longest Common Prefix

## 🧩 Problem Statement

You are given two arrays of positive integers:

- `arr1`
- `arr2`

A **common prefix** between two numbers is the sequence of starting digits they share.

Your task is to return the **maximum length of any common prefix** between:

- one number from `arr1`
- one number from `arr2`

---

## 📥 Input

- `arr1` → first integer array
- `arr2` → second integer array

## 📤 Output

- Length of the **longest common digit prefix**

---

## 🧪 Example

### Input
Output
3
Explanation

Compare:

12345 and 12399 → common prefix = "123" → length = 3
123 and 12 → common prefix = "12" → length = 2

Maximum = 3

💡 Approach (Trie / Prefix Tree)

Since we need to compare digit prefixes, a Trie (Prefix Tree) is ideal.

Idea
Insert every number from arr2 into a Trie digit by digit.
For every number in arr1, traverse the Trie and count how many digits match.
Track the maximum matched length.
Why Trie?

Trie allows:

Insert → O(length of number)
Prefix query → O(length of number)

Much faster than comparing every pair (O(n × m)).

✅ C++ Solution
struct TrieNode {
    TrieNode* next[10];   // digits 0-9
    bool isEnd = false;
};

static constexpr int N = 9e5;
static TrieNode pool[N];
static int ptr = 0;

struct Trie {
    TrieNode* newNode() {
        TrieNode* node = &pool[ptr++];
        memset(node->next, 0, sizeof(node->next));
        node->isEnd = false;
        return node;
    }

public:
    TrieNode* root;

    Trie() {
        ptr = 0;
        root = newNode();
    }

    void insert(string&& word) {
        TrieNode* node = root;

        for (char c : word) {
            int i = c - '0';

            if (node->next[i] == nullptr)
                node->next[i] = newNode();

            node = node->next[i];
        }

        node->isEnd = true;
    }

    int commonPrefix(string&& s) {
        TrieNode* node = root;
        int len = 0;

        for (char c : s) {
            int i = c - '0';

            if (node->next[i] == nullptr)
                return len;

            node = node->next[i];
            len++;
        }

        return len;
    }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie trie;

        // Insert all numbers from arr2
        for (int x : arr2)
            trie.insert(to_string(x));

        int maxLen = 0;

        // Find longest prefix with arr1
        for (int x : arr1)
            maxLen = max(maxLen, trie.commonPrefix(to_string(x)));

        return maxLen;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
☕ Java Solution
class TrieNode {
    TrieNode[] next = new TrieNode[10];
}

class Trie {
    TrieNode root = new TrieNode();

    void insert(String word) {
        TrieNode node = root;

        for (char c : word.toCharArray()) {
            int idx = c - '0';

            if (node.next[idx] == null)
                node.next[idx] = new TrieNode();

            node = node.next[idx];
        }
    }

    int commonPrefix(String word) {
        TrieNode node = root;
        int len = 0;

        for (char c : word.toCharArray()) {
            int idx = c - '0';

            if (node.next[idx] == null)
                return len;

            node = node.next[idx];
            len++;
        }

        return len;
    }
}

class Solution {
    public int longestCommonPrefix(int[] arr1, int[] arr2) {
        Trie trie = new Trie();

        for (int x : arr2)
            trie.insert(String.valueOf(x));

        int ans = 0;

        for (int x : arr1)
            ans = Math.max(ans, trie.commonPrefix(String.valueOf(x)));

        return ans;
    }
}
🐍 Python Solution
class TrieNode:
    def __init__(self):
        self.next = {}

class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word):
        node = self.root
        for ch in word:
            if ch not in node.next:
                node.next[ch] = TrieNode()
            node = node.next[ch]

    def common_prefix(self, word):
        node = self.root
        length = 0

        for ch in word:
            if ch not in node.next:
                break
            node = node.next[ch]
            length += 1

        return length


class Solution:
    def longestCommonPrefix(self, arr1, arr2):
        trie = Trie()

        for x in arr2:
            trie.insert(str(x))

        ans = 0
        for x in arr1:
            ans = max(ans, trie.common_prefix(str(x)))

        return ans
⏱️ Complexity Analysis
Time Complexity
O((n + m) × d)

Where:

n = size of arr1
m = size of arr2
d = maximum number of digits
Space Complexity
O(m × d)

For storing Trie nodes.

🧠 Key Insight

Trie stores digit prefixes efficiently.

Instead of comparing every pair:

O(n × m)

we reduce it to:

O((n + m) × d)

which is much faster.

🚀 Tags

Trie String Prefix Matching Hashing

📌 Author
supriya biradar
```text
arr1 = [12345, 987, 123]
arr2 = [12399, 12, 567]
