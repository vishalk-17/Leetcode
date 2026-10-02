// LeetCode 22 — Generate Parentheses
// Approach: Backtracking

// We need to generate all valid parentheses combinations using exactly n pairs.

// For every position, we have two choices:

// Add ( if open < n
// Add ) if close < open

// The important condition is:

// We can never add ) when close >= open, because that would make the parentheses invalid.

// C++ Solution
class Solution {
public:
    vector<string> ans;

    void backtrack(string curr, int open, int close, int n) {
        // Complete valid string
        if (curr.length() == 2 * n) {
            ans.push_back(curr);
            return;
        }

        // Add opening bracket
        if (open < n) {
            backtrack(curr + "(", open + 1, close, n);
        }

        // Add closing bracket
        if (close < open) {
            backtrack(curr + ")", open, close + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        backtrack("", 0, 0, n);
        return ans;
    }
};