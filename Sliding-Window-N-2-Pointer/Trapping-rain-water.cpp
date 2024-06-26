class Solution {
public:
// brute force approach is finding max at ith index to left and to right of ith index
   // Time complexity - O(N) ,space complexity - O(1)
    int trap(vector<int>& height) {
        int n=height.size();
        int i=0,j=n-1;
        int leftmax=0,rightmax=0;
        int ans=0;
        while(i<=j){
            if(height[i]<=height[j]){
               if(height[i]>=leftmax) leftmax=height[i];
               ans+=leftmax-height[i];
               i++;
            }else{
               if(height[j]>=rightmax) rightmax=height[j];
               ans+=rightmax-height[j];
               j--;
               
            }
        }
        return ans;
    }
};

class Solution {
public:
   // Time complexity - O(3*N) ,space complexity - O(3*N)
    int trap(vector<int>& height) {
        int n=height.size();
        int prefix[n],suffix[n];
        
        // just taking max till index i using prefix max , similarly for suffix max
        // adding into ans min of prefix and suffix of ith index - height of ith index
        prefix[0]=height[0];
        int leftmax=height[0],rightmax=height[n-1];

        for(int i=1;i<n;i++){
           if(height[i]>leftmax) leftmax=height[i];
           prefix[i]=leftmax;
        }

        suffix[n-1]=height[n-1];
        for(int j=n-2;j>=0;j--){
            if(height[j]>rightmax) rightmax=height[j];
            suffix[j]=rightmax;
        }

        int ans=0;
        for(int i=0;i<n;i++){
            int mn=min(prefix[i],suffix[i]);
            ans+=abs(mn-height[i]);
        }
        
        return ans;
    }
};