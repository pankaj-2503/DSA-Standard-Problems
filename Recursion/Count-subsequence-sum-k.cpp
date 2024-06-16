class Solution{
// Time complexity - O(2^n)
public:
int mod = (int)(1e9 + 7);
        int solve(int index,int cursum,int sum,int arr[],int n){
                if(index==n){
                    if(cursum==sum) return 1;
                    else return 0;
                }
                
                //pick
                int pick=solve(index+1,cursum+arr[index],sum,arr,n);
                // notpick
                int notpick=solve(index+1,cursum,sum,arr,n);
                return (pick+notpick)%mod;
        }

        int perfectSum(int arr[], int n, int sum) {
          return solveMem(0, 0, sum, arr, n, dp);
       }


};