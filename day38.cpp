//Contiguous Subarrays Divisible by K

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<long long> freq(k, 0);

    // Empty prefix sum has remainder 0
    freq[0] = 1;

    long long prefixSum = 0;
    long long answer = 0;

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;

        prefixSum += x;

        // C++ can give negative remainder for negative numbers
        long long rem = prefixSum % k;
        if (rem < 0)
            rem += k;

        // Every previous prefix with same remainder
        // forms a valid subarray ending at current index
        answer += freq[rem];

        freq[rem]++;
    }

    cout << answer << '\n';

    return 0;
}