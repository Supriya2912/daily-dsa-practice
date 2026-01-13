## Separate Squares I

### Problem
Given multiple axis-aligned squares, find the horizontal line that splits the total area into two equal halves.

### Approach
- Compute total area of all squares
- Perform binary search on Y-coordinate
- For a candidate Y, calculate area below the line
- Adjust search range based on comparison with half area

### Area Calculation
- Square fully below → full area added
- Square fully above → ignored
- Square partially intersecting → partial area added

### Complexity
- Time Complexity: O(n × log(range))
- Space Complexity: O(1)

### Key Insight
This is a classic "binary search on answer" problem combined with geometric area computation.


  ###solution:

  class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = groups.size();
        vector<string> ans;

        if(n == 1)
        return words;

        for(int i = 1; i < n; i++){
            if(groups[i-1] != groups[i]){
                if(ans.size() == 0){
                    ans.push_back(words[i-1]);
                    ans.push_back(words[i]);
                }else{
                    ans.push_back(words[i]);
                }
            }
        }

        if(ans.size() == 0){
            ans.push_back(words[0]);
        }
        return ans;
    }
};
