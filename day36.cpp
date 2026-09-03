/*LeetCode 3876 — Construct Uniform Parity Array II

The key is to think about what happens to parity when we subtract two numbers.

For two integers:

odd − odd = even
even − even = even
odd − even = odd
even − odd = odd

We need nums2 to be all even OR all odd.*/

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minOdd = INT_MAX;
        int minEven = INT_MAX;

        for (int x : nums1) {
            if (x % 2 == 0) {
                minEven = min(minEven, x);
            } else {
                minOdd = min(minOdd, x);
            }
        }

        // All even
        if (minOdd == INT_MAX) {
            return true;
        }

        // All odd
        if (minEven == INT_MAX) {
            return true;
        }

        // Mixed parity: make all elements odd
        return minOdd < minEven;
    }
};
