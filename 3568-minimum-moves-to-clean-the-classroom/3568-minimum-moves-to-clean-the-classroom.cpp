class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {

        int m = classroom.size();
        int n = classroom[0].size();

        // Give every litter cell an index
        vector<vector<int>> litterIndex(m, vector<int>(n, -1));

        int litterCount = 0;
        int sr = 0, sc = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }

                if (classroom[i][j] == 'L') {
                    litterIndex[i][j] = litterCount++;
                }
            }
        }

        // All litter collected
        int fullMask = (1 << litterCount) - 1;

        // State = row, col, remaining energy, mask
        queue<array<int, 4>> q;

        // visited[row][col][energy][mask]
        vector<vector<vector<vector<bool>>>> visited(
            m,
            vector<vector<vector<bool>>>(
                n,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(1 << litterCount, false)
                )
            )
        );

        q.push({sr, sc, energy, 0});

        visited[sr][sc][energy][0] = true;

        int moves = 0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {

            int sz = q.size();

            while (sz--) {

                auto [r, c, currEnergy, mask] = q.front();
                q.pop();

                // All litter collected
                if (mask == fullMask) {
                    return moves;
                }

                for (int d = 0; d < 4; d++) {

                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    // Outside grid
                    if (nr < 0 || nr >= m ||
                        nc < 0 || nc >= n) {
                        continue;
                    }

                    // Obstacle
                    if (classroom[nr][nc] == 'X') {
                        continue;
                    }

                    // Cannot move with zero energy
                    if (currEnergy == 0) {
                        continue;
                    }

                    int newEnergy = currEnergy - 1;
                    int newMask = mask;

                    // Collect litter
                    if (classroom[nr][nc] == 'L') {
                        int idx = litterIndex[nr][nc];

                        newMask |= (1 << idx);
                    }

                    // Reset energy
                    if (classroom[nr][nc] == 'R') {
                        newEnergy = energy;
                    }

                    if (!visited[nr][nc][newEnergy][newMask]) {

                        visited[nr][nc][newEnergy][newMask] = true;

                        q.push({
                            nr,
                            nc,
                            newEnergy,
                            newMask
                        });
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};