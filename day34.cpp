
//3568. Minimum Moves to Clean the Classroom
class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        // Find all L locations and assign IDs
        unordered_map<int, pair<int, int>> litter;
        int litterId = 0;
        int startX, startY;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'L') {
                    litter[litterId++] = {i, j};
                } else if (classroom[i][j] == 'S') {
                    startX = i;
                    startY = j;
                }
            }
        }

        int fullMask = (1 << litterId) - 1;

        // visited[x][y][mask] = max energy we’ve had at (x,y) with mask
        vector<vector<vector<int>>> bestEnergy(m, vector<vector<int>>(n, vector<int>(1 << litterId, -1)));

        queue<tuple<int, int, int, int, int>> q; // x, y, mask, energy left, steps
        q.push({startX, startY, 0, energy, 0});
        bestEnergy[startX][startY][0] = energy;

        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};

        while (!q.empty()) {
            auto [x, y, mask, e, steps] = q.front();
            q.pop();

            if (mask == fullMask) return steps;
            if (e == 0) continue; // dead end

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                int ne = e - 1;
                int nmask = mask;

                if (nx < 0 || ny < 0 || nx >= m || ny >= n || classroom[nx][ny] == 'X') continue;

                char cell = classroom[nx][ny];
                if (cell == 'R') ne = energy;
                else if (cell == 'L') {
                    // Find which litter ID this cell is
                    for (auto& [id, pos] : litter) {
                        if (pos.first == nx && pos.second == ny) {
                            nmask |= (1 << id);
                            break;
                        }
                    }
                }

                if (ne <= bestEnergy[nx][ny][nmask]) continue;
                bestEnergy[nx][ny][nmask] = ne;
                q.push({nx, ny, nmask, ne, steps + 1});
            }
        }

        return -1; // impossible
    }
};