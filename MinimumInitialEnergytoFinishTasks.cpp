# ⚡ Minimum Initial Energy to Finish Tasks

## 🧩 Problem Statement

You are given a list of tasks where each task is represented as:

```text
[actual, minimum]
  Where:

actual = the energy required to complete the task
minimum = the minimum energy you must have before starting the task

You can complete the tasks in any order.

Return the minimum initial energy required to finish all tasks.

📥 Input
tasks → a 2D array where:
tasks[i] = [actual_i, minimum_i]
📤 Output
Minimum initial energy needed
🧪 Example
Input
tasks = [[1,2],[2,4],[4,8]]
Output
8
Explanation

Start with energy 8:

Do task [4,8] → remaining energy = 4
Do task [2,4] → remaining energy = 2
Do task [1,2] → remaining energy = 1

All tasks completed successfully.

💡 Approach (Greedy Sorting)

To minimize initial energy:

Perform tasks with the largest gap between minimum and actual energy first.

That gap is:

minimum - actual

Tasks with larger "wasted required reserve" should be completed earlier.

🔹 Step 1: Sort Tasks

Sort by:

(minimum - actual) descending

This ensures difficult tasks are handled first.

🔹 Step 2: Simulate Energy Usage

Maintain:

current → current available energy
extra → additional energy added when needed

For every task:

If current energy is insufficient:
current < minimum

Add extra energy:

extra += minimum - current

Then update:

current = minimum
Complete Task

Subtract actual energy:

current -= actual
✅ C++ Solution
class Solution {
    static bool cmp(vector<int>& a, vector<int>& b) {
        return (a[1] - a[0]) > (b[1] - b[0]);
    }

public:
    int minimumEffort(vector<vector<int>>& tasks) {

        // Sort by (minimum - actual) descending
        sort(tasks.begin(), tasks.end(), cmp);

        int current = 0;
        int extra = 0;

        for (auto& task : tasks) {

            // Add energy if needed
            if (current < task[1]) {
                extra += (task[1] - current);
                current = task[1];
            }

            // Perform task
            current -= task[0];
        }

        return extra;
    }
};
☕ Java Solution
import java.util.*;

class Solution {
    public int minimumEffort(int[][] tasks) {

        Arrays.sort(tasks, (a, b) ->
            (b[1] - b[0]) - (a[1] - a[0])
        );

        int current = 0;
        int extra = 0;

        for (int[] task : tasks) {

            if (current < task[1]) {
                extra += task[1] - current;
                current = task[1];
            }

            current -= task[0];
        }

        return extra;
    }
}
🐍 Python Solution
class Solution:
    def minimumEffort(self, tasks):
        # Sort by (minimum - actual) descending
        tasks.sort(key=lambda x: x[1] - x[0], reverse=True)

        current = 0
        extra = 0

        for actual, minimum in tasks:
            if current < minimum:
                extra += minimum - current
                current = minimum

            current -= actual

        return extra
⏱️ Complexity Analysis
Time Complexity: O(n log n)
Sorting dominates
Space Complexity: O(1)
Ignoring sorting overhead
