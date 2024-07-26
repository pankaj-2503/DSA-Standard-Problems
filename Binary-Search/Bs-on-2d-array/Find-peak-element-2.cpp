class Solution {
public:
   // Time complexity - O(N+M)
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        int low=0,high=m-1;

        while(low<=high){
           int col=low+(high-low)/2;
           int mx=0;
           int row=-1;
           // find maximum value in current column
           for(int i=0;i<n;i++){
            if(mat[i][col]>mx){
                mx=mat[i][col];
                row=i;
            }
           }
           int cur=mat[row][col];
           int left=(col==0)?-1:mat[row][col-1]; // current row left 
           int right=(col==m-1)?-1:mat[row][col+1]; // current row right

           // check if current element is peak
           if(cur>left && cur>right){
               return {row,col};
           }
           else if(cur<left) high=col-1;
           else low=col+1;




        }
        return {-1,-1};
    }
};