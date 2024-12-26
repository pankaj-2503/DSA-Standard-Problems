vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices){
        //write your code here
        // TC: O(q*n)
        vector<int>ans(queries);
        for(int i=0;i<queries;i++){
            for(int j=indices[i]+1;j<n;j++){
                ans[i]=arr[j]>arr[indices[i]]?ans[i]+1:ans[i];
            }
        }
        return ans;
       
    }


