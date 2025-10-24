class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
       
        vector<int>ans;
        deque<int>dq;

        for(int i=0;i<n;i++){
            // Maintaining window of size k
            if(!dq.empty() && dq.front()<=i-k) dq.pop_front();

            // maintaining maximum at front in monotonic way such that dq front would contain max value
            while(!dq.empty() && nums[dq.back()]<=nums[i]) dq.pop_back();


            dq.push_back(i);

            if(i>=k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};