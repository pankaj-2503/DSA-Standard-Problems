class Solution {
public:
// TC -> O(Log(m+n))
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Approach is that we are taking 0,1,2,..n, no of element from arr1 and rest from arr2 similarly on right side of partition
        // then coming to a conclusion from those partitioned arr end values that final merged would be sorted or not
        int n1=nums1.size(),n2=nums2.size();
        // we will be performing binary search on smallest array for better tc
        if(n1>n2) return findMedianSortedArrays(nums2,nums1);
        int low=0,high=n1;
        int left=(n1+n2+1)/2; // how many element to take on left side of partition
        int n=n1+n2;
        while(low<=high){
            int mid1=low+(high-low)/2;
            int mid2=left-mid1;
            // Pointers to end of each array in first partiton and second partition
            int l1=INT_MIN,l2=INT_MIN;
            int r1=INT_MAX,r2=INT_MAX;
            if(mid1<n1) r1=nums1[mid1];
            if(mid2<n2) r2=nums2[mid2];
            if(mid1-1>=0) l1=nums1[mid1-1];
            if(mid2-1>=0) l2=nums2[mid2-1];
            if(l1<=r2 && l2<=r1){            // merged array would be sorted if this condition hold
                if(n%2==1) return max(l1,l2);
                return (double)(max(l1,l2)+min(r1,r2))/2.0; 
            }
            if(l1>r2) high=mid1-1;
            else low=mid1+1;
        }
        return 0;
    }
};