class Solution {
public:
// Tc:O(N*M*K), SC:O(n)
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(nums1[i]==nums2[j]){
                    for(int k=j+1;k<m;k++){
                        if(nums2[k]>nums2[j]){
                            ans[i]=nums2[k];break;
                        }
                    }
                }
            }
        }
        return ans;
    }
};

// using monotonic stack -> TC:O(2N),SC:O(N)
    class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        stack<int>s;
        unordered_map<int,int>mp;
        for(int i=m-1;i>=0;i--){
            while(!s.empty() && s.top()<nums2[i]){
                s.pop();
            }
            if(s.empty()) mp[nums2[i]]=-1;
            else mp[nums2[i]]=s.top();
            s.push(nums2[i]);
        }
        // for(auto i:mp){
        //     cout<<i.first<<" "<<i.second<<endl;
        // }
        vector<int>ans(n);
        int j=0;
        for(auto i:nums1){
            if(mp.find(i)!=mp.end()){
                ans[j]=mp[i];j++;
            }
        }
        return ans;
    }
};