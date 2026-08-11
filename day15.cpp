#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0];
        int i = 1;

        // Find longest sequential prefix
        while (i < nums.size() && nums[i] == nums[i - 1] + 1) {
            sum += nums[i];
            i++;
        }

        // Store all elements in a set
        unordered_set<int> st(nums.begin(), nums.end());

        // Find smallest missing integer >= sum
        while (st.count(sum)) {
            sum++;
        }

        return sum;
    }
};

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;
    int result = obj.missingInteger(nums);

    cout << "Missing Integer = " << result << endl;

    return 0;
}