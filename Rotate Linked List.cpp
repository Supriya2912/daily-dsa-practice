# 🔁 Rotate Linked List (Right by K Places)

## 🧩 Problem Statement

Given the head of a singly linked list, rotate the list to the **right by `k` places**.

---

## 📥 Input

- `head`: Head of the singly linked list  
- `k`: Number of rotations

---

## 📤 Output

- The head of the modified linked list after rotating it `k` times

---

## 🧪 Example

### Input
head = 1 → 2 → 3 → 4 → 5
k = 2


### Output

4 → 5 → 1 → 2 → 3

---

## 💡 Approach

### Step 1: Find Length of Linked List
- Traverse the list and count total nodes (`n`)

### Step 2: Optimize Rotations
- Since rotating `n` times gives the same list:

k = k % n

- If `k == 0`, return original list

### Step 3: Find New Tail
- The new tail will be at position:

(n - k - 1)


### Step 4: Rearrange Links
- Break the list at new tail
- Make next node as new head
- Connect the last node to original head

---

## ✅ C++ Solution

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k == 0) return head;

        // Step 1: Calculate length
        ListNode* traverse = head;
        int count = 0;
        while (traverse) {
            count++;
            traverse = traverse->next;
        }

        // Step 2: Optimize k
        k = k % count;
        if (k == 0) return head;

        // Step 3: Find new tail
        traverse = head;
        int stop = count - k - 1;
        while (stop--) {
            traverse = traverse->next;
        }

        // Step 4: Rearrange
        ListNode* newHead = traverse->next;
        traverse->next = nullptr;

        ListNode* temp = newHead;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = head;

        return newHead;
    }
};
☕ Java Solution
class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}

class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null || k == 0) return head;

        // Step 1: Find length
        ListNode temp = head;
        int count = 0;
        while (temp != null) {
            count++;
            temp = temp.next;
        }

        // Step 2: Optimize k
        k = k % count;
        if (k == 0) return head;

        // Step 3: Find new tail
        temp = head;
        int stop = count - k - 1;
        while (stop-- > 0) {
            temp = temp.next;
        }

        // Step 4: Rearrange
        ListNode newHead = temp.next;
        temp.next = null;

        ListNode curr = newHead;
        while (curr.next != null) {
            curr = curr.next;
        }
        curr.next = head;

        return newHead;
    }
}
🐍 Python Solution
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def rotateRight(self, head, k):
        if not head or k == 0:
            return head

        # Step 1: Find length
        temp = head
        count = 0
        while temp:
            count += 1
            temp = temp.next

        # Step 2: Optimize k
        k %= count
        if k == 0:
            return head

        # Step 3: Find new tail
        temp = head
        for _ in range(count - k - 1):
            temp = temp.next

        # Step 4: Rearrange
        new_head = temp.next
        temp.next = None

        curr = new_head
        while curr.next:
            curr = curr.next
        curr.next = head

        return new_head
⏱️ Complexity Analysis
Time Complexity: O(n)
Space Complexity: O(1)
