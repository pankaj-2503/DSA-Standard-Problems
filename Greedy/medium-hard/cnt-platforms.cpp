 int findPlatform(int arr[], int dep[], int n)
    {
        // TC: O(N)
    	// Your code here
        sort(arr,arr+n);
        sort(dep,dep+n);
        int cnt=1,mx=1,i=1,j=0;
        while(i<n && j<n){
            if(arr[i]<=dep[j]){
                cnt++;i++;
            }
            else{
                cnt--;
                j++;
            }
            mx=max(mx,cnt);
        }
        return mx;
    }