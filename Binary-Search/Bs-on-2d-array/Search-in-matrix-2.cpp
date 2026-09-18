class Solution {
public:
    // Time complexity  - O(m+n)
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
         int n=matrix.size(),m=matrix[0].size();
        int row=0,col=m-1;
        while(row<n && col>=0){
            if(matrix[row][col]==target) return true;
            else if(matrix[row][col]>target) col--;
            else row++;
        }
        return false;
    }
};

// Time complexity  - O(log(m*n))
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(),m=matrix[0].size();
        int left=0,right=n*m-1;
        // since each row's first element is greater than prev row last , also each row element is sorted in increasing order , treat it as single 1d array
        while(left<=right){
            int mid=left+(right-left)/2;
            int row=mid/m;
            int col=mid%m;

            if(matrix[row][col]==target) return true;
            else if(matrix[row][col]<target) left=mid+1;
            else right=mid-1;
        }
        return false;
    }
};