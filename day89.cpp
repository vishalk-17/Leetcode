//3882. Minimum XOR Path in a Grid
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<bitset<1024>> dp(m * n);

        dp[0].set(grid[0][0]);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int id = i * n + j;

                if (i == 0 && j == 0)
                    continue;

                bitset<1024> prev;

                if (i > 0)
                    prev |= dp[(i - 1) * n + j];

                if (j > 0)
                    prev |= dp[i * n + j - 1];

                for (int x = 0; x < 1024; x++) {
                    if (prev[x]) {
                        dp[id].set(x ^ grid[i][j]);
                    }
                }
            }
        }

        int last = m * n - 1;

        for (int x = 0; x < 1024; x++) {
            if (dp[last][x])
                return x;
        }

        return 0;
    }
};
