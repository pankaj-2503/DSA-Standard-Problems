class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Moore's voting algorithm -> TC - O(n) , SC-constant
        int n=nums.size();
        int cnt=0,candidate=0;
        for(auto i:nums){
            if(cnt==0){
                candidate=i;
            }
            if(i==candidate) cnt++;
            else cnt--;
        }
        return candidate;
    }
};