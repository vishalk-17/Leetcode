#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        vector<int> freq(26, 0);

        int left = 0;
        int right = 0;
        int longest = 0;

        while (right < n) {
            freq[s[right] - 'a']++;

            while (freq[s[right] - 'a'] > 2) {
                freq[s[left] - 'a']--;
                left++;
            }

            longest = max(longest, right - left + 1);
            right++;
        }

        return longest;
    }
};

int main() {
    Solution obj;

    string s;
    cout << "Enter string: ";
    cin >> s;

    int ans = obj.maximumLengthSubstring(s);

    cout << "Maximum Length Substring: " << ans << endl;

    return 0;
}