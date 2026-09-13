//835. Image Overlap


class Solution {
public:
    int maxOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = A.size();
        int ans = 0;

        for(int x_shift = -(n - 1); x_shift <= n - 1; x_shift++) {
            for(int y_shift = -(n - 1); y_shift <= n - 1; y_shift++) {

                int temp = 0;

                for(int i = 0; i < n; i++) {
                    for(int j = 0; j < n; j++) {

                        int ni = i - y_shift;
                        int nj = j - x_shift;

                        if(ni >= 0 && ni < n &&
                           nj >= 0 && nj < n &&
                           A[i][j] == 1 &&
                           B[ni][nj] == 1) {
                            temp++;
                        }
                    }
                }

                ans = max(ans, temp);
            }
        }

        return ans;
    }

    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        return max(maxOverlap(A, B), maxOverlap(B, A));
    }
};