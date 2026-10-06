/*

60. Permutation Sequence

The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

 

Example 1:

Input: n = 3, k = 3
Output: "213"
Example 2:

Input: n = 4, k = 9
Output: "2314"
Example 3:

Input: n = 3, k = 1
Output: "123"
 

Constraints:

1 <= n <= 9
1 <= k <= n!
*/

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;

        for (int i = 1; i <= n; i++) {
            nums.push_back(i);
        }

        // Convert k to 0-based indexing
        k--;

        string ans;

        // factorial = (n - 1)!
        int factorial = 1;
        for (int i = 1; i <= n - 1; i++) {
            factorial *= i;
        }

        for (int i = n; i >= 1; i--) {

            // Find which block contains k
            int index = k / factorial;

            // Pick that number
            ans += to_string(nums[index]);

            // Remove selected number
            nums.erase(nums.begin() + index);

            // Update k for next block
            k %= factorial;

            // Calculate next factorial
            if (i > 1) {
                factorial /= (i - 1);
            }
        }

        return ans;
    }
};