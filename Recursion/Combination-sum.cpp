class Solution {
public:
// time complexity - O((2^t)*k) , space complexity - O(x*k) where t is target,k is no. of times call happened
     void findCombination(int ind, int target, vector < int > & arr, vector < vector < int >> & ans, vector < int > & temp) {
      if (ind == arr.size()) {
        if (target == 0) {
          ans.push_back(temp);
        }
        return;
      }
      // pick up the element 
      if (arr[ind] <= target) {
        temp.push_back(arr[ind]);
        findCombination(ind, target - arr[ind], arr, ans, temp);
        temp.pop_back();
      }

      findCombination(ind + 1, target, arr, ans, temp);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       vector < vector < int >> ans;
       vector < int > temp;
       findCombination(0, target, candidates, ans, temp);
       return ans;
    }
};