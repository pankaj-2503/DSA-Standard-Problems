class Solution {
public:
    // tC -> O(nlogn)
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        sort(nums.begin(),nums.end());
        int mx=0;
        int len=1;
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1]){
                if(nums[i]==nums[i-1]+1) len++;
                else len=1;
                mx=max(mx,len);
            }
        }
        return max(mx,len);

    }
};


// TC -> O(N)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;

        for (int num : numSet) {
            if (numSet.find(num - 1) == numSet.end()) {
                int length = 1;

                while (numSet.find(num + length) != numSet.end()) {
                    length++;
                }

                longest = max(longest, length);
            }
        }

        return longest;
    }
};