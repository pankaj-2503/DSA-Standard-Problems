class Solution {
public:
// Time complexity - O(nlogn)

// Algorithm	    Best	            Average	           Worst
// Merge Sort	    O(n log n)	       O(n log n)	    O(n log n)
// Insertion Sort	O(n)	            O(n^2)	         O(n^2)
// Bubble Sort	    O(n)	            O(n^2)	         O(n^2)
// Quick Sort	    O(n log n)	       O(n log n)	     O(n^2)
// Heap Sort	    O(n log n)	       O(n log n)	    O(n log n)

    void merge(int l,int mid,int r,vector<int>&nums){
        int n1=mid-l+1;
        int n2=r-mid;

        int a[n1],b[n2];
        for(int i=0;i<n1;i++) a[i]=nums[l+i];
        for(int i=0;i<n2;i++) b[i]=nums[mid+i+1];

        int i=0,j=0,k=l;
        while(i<n1 && j<n2){
            if(a[i]<=b[j]){
                nums[k]=a[i];
                i++;k++;
            }else{
                nums[k]=b[j];
                j++;k++;
            }
        }
        while(i<n1){
            nums[k]=a[i];
            i++;k++;
        }
        while(j<n2){
            nums[k]=b[j];
            j++;k++;
        }

    }
    void mergeSort(int l,int r,vector<int>&nums){
        if(l<r){
            int mid=(l+r)/2;
            mergeSort(l,mid,nums);
            mergeSort(mid+1,r,nums);
            merge(l,mid,r,nums);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        mergeSort(0,n-1,nums);
        return nums;
    }
};