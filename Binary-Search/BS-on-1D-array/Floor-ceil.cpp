
int fl(int arr[] , int n , int x , int low , int high){
    low = 0;
    high = n-1;
    int floor = -1;
    while(low<=high){
        int mid = low+(high-low)/2;
   
     if(arr[mid]<=x){
         floor = arr[mid];
         low=mid+1;
     }
     else{
         high=mid-1;
     }
        
    }
    return floor;
}

int ce(int arr[], int n , int x , int low , int high){
     low = 0;
    high = n-1;
    int ceil=-1;
    while(low<=high){
        int mid = low+(high-low)/2;
   
     if(arr[mid]>=x){
         ceil = arr[mid];
         high = mid-1;
     }
     else{
         low = mid+1;
     }
        
    }
    return ceil;
}
pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    // code here
    
    sort(arr,arr+n);
    int floor=fl(arr,n,x,0,n-1);
    int ceil=ce(arr,n,x,0,n-1);
    return {floor,ceil};
}