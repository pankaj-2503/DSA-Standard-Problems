// brute force approach -> TC:O(N*N)+O(N), SC:O(2N)
int celebrity(vector<vector<int> >& mat) {
        // code here
        int ans=-1;
        int n=mat.size(),m=mat[0].size();
        vector<int>iknow(n),knows(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               if(mat[i][j]==1){
                   iknow[i]++;
                   knows[j]++;
               }
            }
        }
        for(int i=0;i<n;i++){
            if(iknow[i]==0 && knows[i]==n-1) ans=i;
        }
        return ans;
    }