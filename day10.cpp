/*Agar kisi value v ka sabse bada contiguous block length L hai,
To us block ko base bana kar baaki n - L elements ko v me convert kiya ja sakta hai.
Har converted element ka effective cost v aata hai.
Isliye total cost:
Cost=v×(n−L)
Har distinct value ke liye ye cost nikaalo aur minimum answer return karo.

Example: arr = [3,1,4,2]

3: longest block = 1 → cost = 3 × (4−1) = 9
1: longest block = 1 → cost = 1 × (4−1) = 3
4: cost = 12
2: cost = 6

Minimum = 3.
*/

#include <bits/stdc++.h>
using namespace std;

long long getMinCost(vector<int> arr) {
    int n = arr.size();

    unordered_map<int, int> maxRun;

    int i = 0;
    while (i < n) {
        int j = i;

        while (j < n && arr[j] == arr[i])
            j++;

        int len = j - i;
        maxRun[arr[i]] = max(maxRun[arr[i]], len);

        i = j;
    }

    long long ans = LLONG_MAX;

    for (auto &p : maxRun) {
        long long value = p.first;
        long long longestBlock = p.second;

        ans = min(ans, value * (n - longestBlock));
    }

    return ans;
}

int main() {
    vector<int> arr = {3, 1, 4, 2};

    cout << getMinCost(arr) << endl;   // Output: 3

    return 0;
}