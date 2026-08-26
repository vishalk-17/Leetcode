// 2904 leet code problem shortest and lexicographivally smallest beautiful sting


class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        int ones = 0;
        string result = "";
        int i = 0;

        for (int j = 0; j < n; j++) {

            if (s[j] == '1')
                ones++;

            // Remove extra 1s from the left
            while (i <= j && ones > k) {
                if (s[i] == '1')
                    ones--;
                i++;
            }

            // Remove leading zeros
            while (i <= j && s[i] == '0') {
                i++;
            }

            // Exactly k ones
            if (ones == k) {
                string temp = s.substr(i, j - i + 1);

                if (result.empty() ||
                    temp.length() < result.length() ||
                    (temp.length() == result.length() && temp < result)) {
                    result = temp;
                }
            }
        }

        return result;
    }
};