
// Input: N = 3, arr[] = {5,2,1} , you have to give all sum that is possible throuh given arr element
// Output: 0,1,2,3,5,6,7,8  

// Time Complexity: O(2^n)+O(2^n log(2^n)) , Space Complexity: O(2^n)
class Solution {
  public:
    void subsetSumsHelper(int ind, vector < int > & arr, int n, vector < int > & ans, int sum) {
      if (ind == n) {
        ans.push_back(sum);
        return;
      }
      //element is picked
      subsetSumsHelper(ind + 1, arr, n, ans, sum + arr[ind]);
      //element is not picked
      subsetSumsHelper(ind + 1, arr, n, ans, sum);
    }
  vector < int > subsetSums(vector < int > arr, int n) {
    vector < int > ans;
    subsetSumsHelper(0, arr, n, ans, 0);
    sort(ans.begin(), ans.end());
    return ans;
  }
};