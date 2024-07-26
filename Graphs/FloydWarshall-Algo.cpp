class Solution {
public:
// TC : O(N^3) , SC:O(N^2),  
// Also work for detecting negative cycles 
	void shortest_distance(vector<vector<int>>&matrix) {
		int n = matrix.size();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (matrix[i][j] == -1) {
					matrix[i][j] = 1e9;
				}
				if (i == j) matrix[i][j] = 0;
			}
		}

		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					matrix[i][j] = min(matrix[i][j],
					                   matrix[i][k] + matrix[k][j]);
				}
			}
		}




		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (matrix[i][j] == 1e9) {
					matrix[i][j] = -1;
				}
			}
		}
	}
};

// Application of bellman ford algo
// Question -> Find city with smallest number neighbourhood at threshodl distance

// TC: O(N^3) , SC:O(N^2)
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        for(auto i:edges){
           dist[i[0]][i[1]]=i[2];
           dist[i[1]][i[0]]=i[2];
        }

        for(int i=0;i<n;i++) dist[i][i]=0;
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX)
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
        
        int cntcity=n;
        int cityno=-1;
        for(int city=0;city<n;city++){
            int cnt=0;
            for(int adjcity=0;adjcity<n;adjcity++){
                if(dist[city][adjcity]<=distanceThreshold) cnt++;
            }
            if(cnt<=cntcity){
                cntcity=cnt;
                cityno=city;
            }
        }
        return cityno;
    }
};