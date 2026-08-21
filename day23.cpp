// leet code 3039 solution in c++

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {

        vector<int> first;
        vector<int> second;

        first.push_back(nums[0]);
        second.push_back(nums[1]);

        for (int i = 2; i < nums.size(); i++) {

            if (first.back() > second.back()) {
                first.push_back(nums[i]);
            } 
            else {
                second.push_back(nums[i]);
            }
        }

        // Combine both arrays
        first.insert(first.end(), second.begin(), second.end());

        return first;
    }
};