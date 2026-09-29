class Solution {
public:
    // TC -> O(M*NLOg(M*N)) , SC -> O(M*N + M+N)
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size(),m=heights[0].size();
        using p = pair<int,pair<int,int>>;
        // Min-heap storing {current_max_effort, {row, col}}
        priority_queue<p,vector<p>,greater<p>>pq;

        // Distance array initialized to a very large value
        vector<vector<int>> efforts(n, vector<int>(m, 1e9));

        // Direction arrays for Up, Right, Down, Left
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        pq.push({0,{0,0}});
        efforts[0][0]=0;

        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();

            int effort=it.first;
            int r=it.second.first;
            int c=it.second.second;

            // if we reach bottom return the effort
            if(r==n-1 && c==m-1) return effort;

            // explore 4 dirn
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];

                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    int neweffort= max(effort,abs(heights[r][c]-heights[nr][nc]));

                    if(neweffort<efforts[nr][nc]){
                        efforts[nr][nc]=neweffort;
                        pq.push({neweffort,{nr,nc}});
                    }
                }


            }

        }
        return 0;

    }
};



// Using binary search + bfs - TC -> O(M*NLog(k)) , where k is max value of diff of height[i]


#include <vector>
#include <queue>
#include <cmath>

using namespace std;

class Solution {
private:
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    // Helper function to verify if destination is reachable under the given effort limit
    bool canReachDest(const vector<vector<int>>& heights, int limit, int m, int n) {
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        q.push({0, 0});
        visited[0][0] = true;

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            if (r == m - 1 && c == n - 1) return true;

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc]) {
                    // Only traverse if the height difference is within the allowed limit
                    if (abs(heights[r][c] - heights[nr][nc]) <= limit) {
                        visited[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }
        }
        return false;
    }

public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        // Constraints state 1 <= heights[i][j] <= 10^6
        int low = 0, high = 1e6;
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canReachDest(heights, mid, m, n)) {
                ans = mid;         // This effort limit works, store it
                high = mid - 1;    // Try to find a tighter limit
            } else {
                low = mid + 1;     // Limit too strict, we must increase it
            }
        }

        return ans;
    }
};