 
 int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
        unordered_map<int,int>m;
        // storing prefix sum ending at index i means sum of all elements of that subarray
        int sum=0,ans=0;
        for(int i=0;i<N;i++){
            sum+=A[i];
            // prefix sum ending at index i with sum x
            if(sum==K) ans=i+1;
            // if sum is greater than k store it
            // prefix sum ending at index i with sum x-k
            if(m.find(sum-K)!=m.end()) ans=max(ans,i-m[sum-K]);
            m.insert({sum,i});
        }
        return ans;
    } 