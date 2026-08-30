
// Removing minimum and maximum from array
class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minIdx = min_element(nums.begin(), nums.end()) - nums.begin();
        int maxIdx = max_element(nums.begin(), nums.end()) - nums.begin();

        int left = min(minIdx, maxIdx);
        int right = max(minIdx, maxIdx);

        return min({
            right + 1,          // dono left se remove
            n - left,           // dono right se remove
            left + 1 + n - right // min left + max right
        });
    }
};