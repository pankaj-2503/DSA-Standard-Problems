// TC: O(logN)
void heapify(vector<int>&arr,int N,int i){
        int largest=i;
        int left=2*i+1;
        int right=2*i+2;
        if(arr[largest]<arr[left] && left<N) largest=left;
        if(arr[largest]<arr[right] && right<N) largest=right;
        if(largest!=i){
            swap(arr[i],arr[largest]);
            if(largest<=N/2) heapify(arr,N,largest);
        }
    }
    void convertMinToMaxHeap(vector<int> &arr, int N){
        // since from N/2 to n are leaf nodes
      for(int i=(N/2)-1;i>=0;i--){
          heapify(arr,N,i);
      }
    }