/*1320. Minimum Distance to Type a Word Using Two Fingers


You have a keyboard layout as shown above in the X-Y plane, where each English uppercase letter is located at some coordinate.

For example, the letter 'A' is located at coordinate (0, 0), the letter 'B' is located at coordinate (0, 1), the letter 'P' is located at coordinate (2, 3) and the letter 'Z' is located at coordinate (4, 1).
Given the string word, return the minimum total distance to type such string using only two fingers.

The distance between coordinates (x1, y1) and (x2, y2) is |x1 - x2| + |y1 - y2|.

Note that the initial positions of your two fingers are considered free so do not count towards your total distance, also your two fingers do not have to start at the first letter or the first two letters.


*/
#include <bits/stdc++.h>
using namespace std;

int dp[300][27];

class Solution {
public:
    static inline int dist(int x, int y) {
        if (x==26 || y==26) return 0; // hovering
        return abs(x/6-y/6)+abs(x%6-y%6);
    }

    static int minimumDistance(string& word) {
        const int n=word.size();
        constexpr int INF=1e9+7;
        fill(&dp[0][0], &dp[0][0]+300*27, INF); // safer reset

        dp[0][26]=0;
        int prev=word[0]-'A'; 

        for (int i=1; i<n; i++) {
            int x=word[i]-'A';

            for (int j=0; j<27; j++) {
                if (dp[i-1][j]>=INF) continue;

                // move current finger
                dp[i][j]=min(dp[i][j], dp[i-1][j] + dist(prev, x));

                // move other finger
                dp[i][prev]=min(dp[i][prev], dp[i-1][j] + dist(j, x));
            }
            prev=x;
        }

        return *min_element(dp[n-1], dp[n-1]+27);
    }
};

int main() {
    string word;

    cout << "Enter word (CAPITAL letters only): ";
    cin >> word;

    cout << "Minimum Distance: " << Solution::minimumDistance(word) << endl;

    return 0;
}