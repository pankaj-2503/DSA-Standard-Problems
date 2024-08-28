// TC: O(NlogN)+O(N*M) , SC:O(n)
static bool  compare(Job a,Job b){
        return (a.profit>b.profit);
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr,arr+n,compare);
        int slot[n];
        for(int i=0;i<n;i++) slot[i]=-1;
        
        int cnt=0,sum=0;
        for(int i=0;i<n;i++){
            for(int j=arr[i].dead-1;j>=0;j--){
                if(slot[j]==-1){
                    cnt++;
                    sum+=arr[i].profit;
                    slot[j]=1;
                    break;
                }
            }
        }
        vector<int>ans;
        ans.push_back(cnt);
        ans.push_back(sum);
        
        return ans;
    } 