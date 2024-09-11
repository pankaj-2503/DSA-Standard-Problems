#define ll long long
class Solution {
public:
// Brute force - TC:O(n^2) , SC-constant
    long long subArrayRanges(vector<int>& nums) {
        ll sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            ll smallest=1e9,largest=-1e9;
            for(int j=i;j<n;j++){
                smallest=min(smallest,nums[j]*1ll);
                largest=max(largest,nums[j]*1ll);
                sum+=largest-smallest;
            }
        }
        return sum;
    }
};

#define ll long long
class Solution {
public:
// TC: O(4*N) ,  space complexity-O(4N)
    long long subArrayRanges(vector<int>& nums) {
        ll sum=0;
        int n=nums.size();
        stack<int>s;
        vector<int>prevmin(n,-1),nextmin(n,n),prevmax(n,-1),nextmax(n,n);

        // calculating prevmin indexes for each index
        for(int i=0;i<n;i++){
            while(!s.empty() && nums[s.top()]>=nums[i]){s.pop();}
            if(!s.empty()){prevmin[i]=s.top();}
            s.push(i);
        }
        while(!s.empty()){s.pop();}

        // calculating nextmin indexes for each index
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && nums[s.top()]>nums[i]) s.pop();
            if(!s.empty()) nextmin[i]=s.top();
            s.push(i);
        }
        while(!s.empty()){s.pop();}
        
        // calculating prevmax indexes for each index
        for(int i=0;i<n;i++){
            while(!s.empty() && nums[s.top()]<=nums[i]) s.pop();
            if(!s.empty()) prevmax[i]=s.top();
            s.push(i);
        }
        while(!s.empty()){s.pop();}

        // calculating nextmax indexes for each index
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && nums[s.top()]<nums[i]) s.pop();
            if(!s.empty()) nextmax[i]=s.top();
            s.push(i);
        }

        // no of combination where ith index contribute m*n*a[i];
        for(int i=0;i<n;i++){
            ll leftMin=i-prevmin[i],rightMin=nextmin[i]-i;
            ll leftMax=i-prevmax[i],rightMax=nextmax[i]-i;
            sum+=(leftMax*rightMax-leftMin*rightMin)*nums[i];
        }
        return sum;

    }
};