bool isMaxHeap(int arr[], int n)
    {
        // Your code goes here
        int i=0;
        while(i<n){
            int leftindex=2*i+1;
            int rightindex=2*i+2;
            if((arr[leftindex]>arr[i] && leftindex<n) || (arr[rightindex]>arr[i] && rightindex<n)) return false;
            i++;
        }
        return true;
    }