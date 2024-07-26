int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    int mx=0,index=-1;
	    
	    for(int i=0;i<n;i++){
	       auto p=lower_bound(arr[i].begin(),arr[i].end(),1);
	       int cnt=m-(p-arr[i].begin());
	       if(cnt>mx){
	           mx=cnt;
	           index=i;
	       }
	    }
	    return index;
	}