
//3871. Count Commas in Range IIday
class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;

        // Each range starts at a power of 1000.
        long long start = 1000;
        long long commas = 1;

        while (start <= n) {
            long long end = start * 1000 - 1;

            // Avoid overflow for very large values
            if (end < start || end > n)
                end = n;

            ans += (end - start + 1) * commas;

            start *= 1000;
            commas++;
        }

        return ans;
    }
};