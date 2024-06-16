// Time Complexity: O( 2^n *(k log (x) )). 2^n  for generating every subset and k* log( x)  to insert every combination of average length k in a set of size x
// Space Complexity:  O(2^n * k)
class Solution {
public:
    void fun(vector < int > & nums, int index, vector < int > ds, set < vector < int >> & res) {
        if (index == nums.size()) {
            sort(ds.begin(), ds.end());
            res.insert(ds);
            return;
        }
        ds.push_back(nums[index]);
        fun(nums, index + 1, ds, res);
        ds.pop_back();
        fun(nums, index + 1, ds, res);
        }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector < vector < int >> ans;
        set < vector < int >> res;
        vector < int > ds;
        fun(nums, 0, ds, res);
        for (auto it = res.begin(); it != res.end(); it++) {
        ans.push_back( * it);
        }
        return ans;
    }
};

// optimal approach
// Time Complexity: O(2^n*K) , Space Complexity: O(2^n * k) 
class solution{
 void findSubsets(int ind, vector < int > & nums, vector < int > & ds, vector < vector < int >> & ans) {
         ans.push_back(ds);
         for (int i = ind; i < nums.size(); i++) {
            if (i != ind && nums[i] == nums[i - 1]) continue;
            ds.push_back(nums[i]);
            findSubsets(i + 1, nums, ds, ans);
            ds.pop_back();
         }
      }
   public:
      vector < vector < int >> subsetsWithDup(vector < int > & nums) {
         vector < vector < int >> ans;
         vector < int > ds;
         sort(nums.begin(), nums.end());
         findSubsets(0, nums, ds, ans);
         return ans;
      }
};