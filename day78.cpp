//3551. Minimum Swaps to Sort by Digit Sum
class Solution {
public:
    int digitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<pair<int, int>> arr;

        // Store {digit sum, original number}
        for (int x : nums) {
            arr.push_back({digitSum(x), x});
        }

        // Sort by digit sum, then by number
        sort(arr.begin(), arr.end());

        // Map each number to its target sorted index
        unordered_map<int, int> target;
        for (int i = 0; i < n; i++) {
            target[arr[i].second] = i;
        }

        vector<bool> visited(n, false);
        int swaps = 0;

        // Count cycles in the permutation
        for (int i = 0; i < n; i++) {
            if (visited[i] || target[nums[i]] == i) {
                continue;
            }

            int cycleSize = 0;
            int j = i;

            while (!visited[j]) {
                visited[j] = true;
                j = target[nums[j]];
                cycleSize++;
            }

            if (cycleSize > 1) {
                swaps += cycleSize - 1;
            }
        }

        return swaps;
    }
};
