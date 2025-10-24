class Solution {
public:
// Time complexity - O(N*logN)
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        unordered_map<int,int>m;
        int sum=0,cnt=0;
        m[0]++;
        for(auto i:nums){
            sum+=i;
            if(m.find(sum-goal)!=m.end()) cnt+=m[sum-goal];
            m[sum]++;
        }
        return cnt;
    }
};

    class Solution {
    public:

        int subarray(vector<int> &nums, int goal)
        {
            if(goal<0)
                return 0;

            int l=0, r=0, sum=0, count=0;

            while(r<nums.size())
            {
                sum+=nums[r];

                while(sum > goal)
                {
                    sum-=nums[l];
                    l++;
                }

                if(sum <= goal)
                {
                    count+=(r-l+1);
                }

                r++;
            }

            return count;
        }

        int numSubarraysWithSum(vector<int>& nums, int goal) {
           // subarray sum with atmost sum<=goal - subarray sum with atmost sum<=goal-1 
           // would return sum of exact goal
            return (subarray(nums, goal) - subarray(nums, goal-1));
            
        }
    };