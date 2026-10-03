//nextGreaterElements ||

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n, -1);
        stack<int> st;

        // Traverse the array twice
        for (int i = 2 * n - 1; i >= 0; i--) {
            int idx = i % n;

            // Remove elements which are not greater
            while (!st.empty() && nums[st.top()] <= nums[idx]) {
                st.pop();
            }

            // Only fill answer during the first traversal
            if (i < n) {
                if (!st.empty()) {
                    ans[idx] = nums[st.top()];
                }
            }

            // Store current index
            st.push(idx);
        }

        return ans;
    }
};