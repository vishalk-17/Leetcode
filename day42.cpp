
/*3483. Unique 3-Digit Even Numbers
Solved
Easy
Topics
premium lock icon
Companies
Hint
You are given an array of digits called digits. Your task is to determine the number of distinct three-digit even numbers that can be formed using these digits.

Note: Each copy of a digit can only be used once per number, and there may not be leading zeros.

 

Example 1:

Input: digits = [1,2,3,4]

Output: 12

Explanation: The 12 distinct 3-digit even numbers that can be formed are 124, 132, 134, 142, 214, 234, 312, 314, 324, 342, 412, and 432. Note that 222 cannot be formed because there is only 1 copy of the digit 2.*/


class Solution {
public:
    int totalNumbers(vector<int>& digits) {

        int freq[10] = {0};

        // Count available digits
        for (int x : digits) {
            freq[x]++;
        }

        int ans = 0;

        // Check every 3-digit number
        for (int num = 100; num <= 999; num++) {

            // Number must be even
            if (num % 2 != 0)
                continue;

            int x = num;

            int a = x / 100;        // hundreds
            int b = (x / 10) % 10;  // tens
            int c = x % 10;         // units

            // Temporarily use digits
            freq[a]--;
            freq[b]--;
            freq[c]--;

            // All digits available?
            if (freq[a] >= 0 &&
                freq[b] >= 0 &&
                freq[c] >= 0) {
                ans++;
            }

            // Restore
            freq[a]++;
            freq[b]++;
            freq[c]++;
        }

        return ans;
    }
};