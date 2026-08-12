#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int left = 0;
        int res = 0;

        unordered_map<int, int> count;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            count[nums[i]]++;

            while (count[nums[i]] > k) {
                count[nums[left]]--;
                left++;
            }

            res = max(res, i - left + 1);
        }

        return res;
    }
};

int main() {
    vector<int> nums = {1, 2, 1, 2, 1, 2, 1};
    int k = 2;

    Solution obj;
    int ans = obj.maxSubarrayLength(nums, k);

    cout << "Maximum Valid Subarray Length = " << ans << endl;

    return 0;
}