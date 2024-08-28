class Solution {
public:
// TC: O(n) , SC: O(1)
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>v;
        int n=intervals.size();
        int i=0;
        // kb tk chota hai
        while(i<n && intervals[i][1]<newInterval[0]){
            v.push_back(intervals[i]);
            i++;
        }
        // kaha tk overlap hai
        while(i<n && intervals[i][0]<=newInterval[1]){
            newInterval={min(newInterval[0],intervals[i][0]),max(newInterval[1],intervals[i][1])};
            i++;
        }
        v.push_back(newInterval);
        //kb tk bada hai
        while(i<n){
            v.push_back(intervals[i]);
            i++;
        }
        return v;
    }
};