class Solution {
public:

// Recursive approach -> TC-O(N^2)
vector<int> generatePascalTriangleRow(int row) {
    if (row == 0) {
        return {1}; // Base case: First row is always 1
    }

    vector<int> previousRow = generatePascalTriangleRow(row - 1);
    vector<int> currentRow;

    currentRow.push_back(1); // First element is always 1
    for (int i = 1; i < previousRow.size(); i++) {
        currentRow.push_back(previousRow[i - 1] + previousRow[i]);
    }
    currentRow.push_back(1); // Last element is always 1

    return currentRow;
}

// TC: O(N^2) , SC: O(N)
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        vector<int>prev;
        for(int i=0;i<numRows;i++){
            vector<int>cur(i+1,1);
            for(int j=1;j<i;j++){
                cur[j]=prev[j-1]+prev[j];
            }
            ans.push_back(cur);
            prev=cur;
        }
        return ans;
    }
};