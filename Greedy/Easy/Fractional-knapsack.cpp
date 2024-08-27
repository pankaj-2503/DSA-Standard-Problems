// TC: O(N)
bool static comp(Item a,Item b){
       double r1=(double)a.value/(double)a.weight;
       double r2=(double)b.value/(double)b.weight;
       return r1>r2;
   }
    
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n) {
        // sort according to profit by wt in decreasing order
       sort(arr,arr+n,comp);
       double curwt=0;
       double total=0.0;
       for(int i=0;i<n;i++){
           if(curwt+arr[i].weight<=w){
               curwt+=arr[i].weight;
               total+=arr[i].value;
           }else{
               int remain=w-curwt;
               total+=((double)arr[i].value/(double)arr[i].weight)*(double)remain;
               break;
           }
       }
       return total;
    }