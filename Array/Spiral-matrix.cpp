class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
           vector<int>ans;
        int n = matrix.size();  // n rows
        int m = matrix[0].size();  // m columns
        
        int startRow = 0;
        int endRow = n -1 ;
        int startCol = 0;
        int endCol = m - 1;
        
        int totalElements = n*m;
        int count = 0;
        
        
        while(count < totalElements)
        {
          for(int i = startCol;i<=endCol && count<totalElements;i++)
          {
           ans.push_back(matrix[startRow][i]);
              count++;
          }
         startRow++;
            
          for(int i = startRow;i<=endRow && count<totalElements;i++)
          {
           ans.push_back(matrix[i][endCol]);
              count++;            
          }
         endCol--;
            
          for(int i = endCol;i>=startCol && count<totalElements;i--)
          {
           ans.push_back(matrix[endRow][i]);
              count++;            
          }            
          endRow--;
            
          for(int i = endRow;i>=startRow && count<totalElements;i--)
          {
             ans.push_back(matrix[i][startCol]);
              count++;
          }
          startCol++;  
        
        }
       return ans;
    }
};