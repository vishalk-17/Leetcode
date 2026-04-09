//3653. XOR After Range Multiplication Queries I

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int M = 1e9 + 7;

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for (auto &query : queries) {
            int l = query[0];
            int r = query[1];
            int k = query[2];
            int v = query[3];

            while (l <= r) {
                nums[l] = (1LL * nums[l] * v) % M;
                l += k;
            }
        }

        int result = 0;
        for (int &num : nums) {
            result ^= num;
        }
        return result;
    }
};

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int q;
    cout << "Enter number of queries: ";
    cin >> q;

    vector<vector<int>> queries(q, vector<int>(4));
    cout << "Enter queries (l r k v):\n";
    for (int i = 0; i < q; i++) {
        cin >> queries[i][0] >> queries[i][1] >> queries[i][2] >> queries[i][3];
    }

    Solution obj;
    int ans = obj.xorAfterQueries(nums, queries);

    cout << "Final XOR Result: " << ans << endl;

    return 0;
}