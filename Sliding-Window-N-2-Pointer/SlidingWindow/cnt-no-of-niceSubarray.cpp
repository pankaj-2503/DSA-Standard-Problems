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

        return subarray(nums,k) - subarray(nums, k-1);

    }
};