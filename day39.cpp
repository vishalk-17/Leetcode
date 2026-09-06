//  115 .Distinct subsequences


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef unsigned long long ull;

    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();

        vector<ull> curr(n + 1, 0);
        vector<ull> prev(n + 1, 0);

        prev[0] = 1;

        for (int i = 1; i <= m; i++) {
            curr[0] = 1;

            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == t[j - 1])
                    curr[j] = prev[j - 1] + prev[j];
                else
                    curr[j] = prev[j];
            }

            prev = curr;
        }

        return prev[n];
    }
};

int main() {
    Solution obj;

    string s, t;

    cout << "Enter string s: ";
    cin >> s;

    cout << "Enter string t: ";
    cin >> t;

    cout << "Number of distinct subsequences: "
         << obj.numDistinct(s, t) << endl;

    return 0;
}