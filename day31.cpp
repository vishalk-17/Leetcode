//Longest Subarray with At Most K Distinct Elements

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<long long> arr(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    unordered_map<long long, int> freq;

    int left = 0;
    int distinct = 0;
    int ans = 0;

    for (int right = 0; right < N; right++) {

        // Add current element
        if (freq[arr[right]] == 0) {
            distinct++;
        }

        freq[arr[right]]++;

        // If distinct elements exceed K,
        // shrink the window from left
        while (distinct > K) {

            freq[arr[left]]--;

            if (freq[arr[left]] == 0) {
                distinct--;
            }

            left++;
        }

        // Current window is valid
        ans = max(ans, right - left + 1);
    }

    cout << ans << endl;

    return 0;
}