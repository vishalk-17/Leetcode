class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        
        unordered_map<int, int> count;
        
        // Generate every subarray of size k
        for (int i = 0; i <= n - k; i++) {
            
            // To avoid counting the same number twice
            // inside one subarray
            unordered_set<int> seen;
            
            for (int j = i; j < i + k; j++) {
                seen.insert(nums[j]);
            }
            
            // Each number appears in this subarray
            // exactly once in our subarray-counting logic
            for (int x : seen) {
                count[x]++;
            }
        }
        
        int ans = -1;
        
        // Find largest number appearing in exactly one subarray
        for (auto &[x, freq] : count) {
            if (freq == 1) {
                ans = max(ans, x);
            }
        }
        
        return ans;
    }
};