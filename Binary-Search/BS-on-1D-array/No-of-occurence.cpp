 int firstOccur(int nums[],int target,int n){
        
        int low=0,high=n-1,ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                ans=mid;
                high=mid-1;
                
            }
            else if(nums[mid]>target) high=mid-1;
            else low=mid+1;
        }
        return ans;
    }
    int lastOccur(int nums[],int target,int n){
        
         int low=0,high=n-1,ans=-1;
         while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                ans=mid;
                low=mid+1;
            }else if(nums[mid]>target){
                high=mid-1;
            }else low=mid+1;
         }
         return ans;
    }
	int count(int arr[], int n, int x) {
	    int target=x;
	    int f=firstOccur(arr,target,n);
	    int l=lastOccur(arr,target,n);
	    if(f==-1 && l==-1) return 0;
	    return l-f+1;
	    
	}
