//301. Remove Invalid Parentheses

class Solution {
public:

    bool isValid(string s) {
        int balance = 0;

        for (char ch : s) {
            if (ch == '(') {
                balance++;
            }
            else if (ch == ')') {
                balance--;

                // Too many closing brackets
                if (balance < 0)
                    return false;
            }
        }

        // All opening brackets must be closed
        return balance == 0;
    }

    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;

        unordered_set<string> visited;
        queue<string> q;

        q.push(s);
        visited.insert(s);

        bool found = false;

        while (!q.empty()) {
            string current = q.front();
            q.pop();

            // Current level contains strings
            // with same number of removals
            if (isValid(current)) {
                ans.push_back(current);
                found = true;
            }

            // If valid strings are found at this level,
            // don't generate next level.
            if (found)
                continue;

            // Remove one character at every position
            for (int i = 0; i < current.size(); i++) {

                // Only parentheses should be removed
                if (current[i] != '(' && current[i] != ')')
                    continue;

                string next = current.substr(0, i) +
                              current.substr(i + 1);

                if (visited.find(next) == visited.end()) {
                    visited.insert(next);
                    q.push(next);
                }
            }
        }

        return ans;
    }
};