// Time Complexity: O(n*m), Space Complexity: O(n*m)
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid[0].size(), n = grid.size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        deque<pair<int, int>> dq;
        int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

        dist[0][0] = 0;
        dq.push_front({0, 0});

        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();
            int curDir = grid[x][y] - 1;
            for (int i = 0; i < 4; i++) {
                int nx = dx[i] + x, ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                    continue;

                int cost = dist[x][y] + (i == curDir ? 0 : 1);
                if (cost < dist[nx][ny]) {
                    dist[nx][ny] = cost;
                    if (i == curDir)
                        dq.push_front({nx, ny});
                    else
                        dq.push_back({nx, ny});
                }
            }
        }
        return dist[n - 1][m - 1];
    }
};