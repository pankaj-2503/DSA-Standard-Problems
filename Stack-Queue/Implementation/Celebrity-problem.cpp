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


// TC:O(N) , SC:constant
int celebrity(vector<vector<int> >& mat) {
        // code here
         int n = mat.size();
        int top = 0;
        int bottom = n - 1;
        while(top < bottom){
            if(mat[top][bottom] == 1 && mat[bottom][top] == 1){
                top++;
                bottom--;
            }else if(mat[top][bottom] == 1 ){
                top++;
            }else if(mat[bottom][top] == 1){
                bottom--;
            }else{
                top++;
                bottom--;
            }
        }
        if(top < bottom){
            return -1;
        }
        for(int i = 0; i < n; i++){
            if(i == top){
                continue;
            }
            if(mat[i][top] != 1 || mat[top][i] != 0){
                return -1;
            }
        }
        return top;
    }