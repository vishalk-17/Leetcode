/*3740. Minimum Distance Between Three Equal Elements I

You are given an integer array nums.

A tuple (i, j, k) of 3 distinct indices is good if nums[i] == nums[j] == nums[k].

The distance of a good tuple is abs(i - j) + abs(j - k) + abs(k - i), where abs(x) denotes the absolute value of x.

Return an integer denoting the minimum possible distance of a good tuple. If no good tuples exist, return -1.

 

Example 1:

Input: nums = [1,2,1,1,3]

Output: 6
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, vector<int>> mp;
        int result = INT_MAX;

        for(int k = 0; k < n; k++) {
            mp[nums[k]].push_back(k);

            if(mp[nums[k]].size() >= 3) {
                vector<int> &vec = mp[nums[k]];
                int siz = vec.size();

                int i = vec[siz-3];
                result = min(result, k - i);
            }
        }

        return result == INT_MAX ? -1 : 2 * result;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {1,2,1,1,3};  // sample input

    int ans = obj.minimumDistance(nums);

    cout << "Minimum Distance: " << ans << endl;

    return 0;
}