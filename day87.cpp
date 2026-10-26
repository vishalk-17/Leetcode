//3619. Count Islands With Total Value Divisible by K
class Solution {
public:
    int m, n;
    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};
    long long dfs(int r, int c, vector<vector<int>>& grid) {
        long long sum = grid[r][c];
        grid[r][c] = 0;
        for (int k=0;k<4;k++) {
            int nr=r+dr[k];
            int nc=c+dc[k];
            if (nr>=0 && nr<m && nc>=0 && nc<n &&grid[nr][nc] > 0) {
                sum += dfs(nr, nc, grid);
            }
        }
        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();//cols
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    long long sum = dfs(i, j, grid);
                    if (sum % k == 0)
                        ans++;
                }
            }
        }
        return ans;
    }
};