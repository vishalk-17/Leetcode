//2333. Minimum Sum of Squared Difference

class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1,
                               vector<int>& nums2,
                               int k1, int k2) {
        int n = nums1.size();
        long long k = 1LL * k1 + k2;

        vector<int> diff(n);
        int mx = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            mx = max(mx, diff[i]);
        }

        long long total = 0;
        for (int d : diff) {
            total += d;
        }

        // Agar saare differences zero kiye ja sakte hain
        if (k >= total) return 0;

        // Binary search: maximum difference limit
        int low = 0, high = mx;

        while (low < high) {
            int mid = low + (high - low) / 2;
            long long operations = 0;

            for (int d : diff) {
                if (d > mid) {
                    operations += d - mid;
                }
            }

            if (operations <= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        int limit = low;
        long long ans = 0;
        long long used = 0;

        // Sab differences ko limit tak reduce karo
        for (int d : diff) {
            if (d > limit) {
                used += d - limit;
                d = limit;
            }
            ans += 1LL * d * d;
        }

        // Remaining operations: limit wale differences ko
        // ek-ek karke limit - 1 karo.
        long long remaining = k - used;

        for (int i = 0; i < n && remaining > 0; i++) {
            if (diff[i] >= limit && limit > 0) {
                ans -= 1LL * limit * limit;
                ans += 1LL * (limit - 1) * (limit - 1);
                remaining--;
            }
        }

        return ans;
    }
};
