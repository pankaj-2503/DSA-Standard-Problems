class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
         int n = nums.size();
        vector<int> cnt(n + 1, 0);
        cnt[0] = 1;
        int ans = 0, t = 0;
        for (int v : nums) {
            t += v & 1;
            if (t - k >= 0) {
                ans += cnt[t - k];
            }
            cnt[t]++;
        }
        return ans;
    }
};


//another approach
class Solution {
public:

    int subarray(vector<int> &nums, int k)
    {
        if(k<0)
            return 0;

        int l=0, r=0, odd=0, count=0;

        while(r<nums.size())
        {
            if(nums[r]%2)
                odd++;

            while(odd>k)
            {
                if(nums[l]%2)
                    odd--;

                l++;
            }
            
            count = count + (r-l+1);

            r++;
        }

        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
         //atmost k odd - atmost k odd = exactly k odd
        return subarray(nums,k) - subarray(nums, k-1);

    }
};