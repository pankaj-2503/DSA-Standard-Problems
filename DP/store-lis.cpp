// Time Complexity: O(N*N) , Space Complexity: O(N)
vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        // Code here
        vector<int> dp(n,1);
        vector<int> hash(n,1);
        
        for(int i=0; i<n; i++){
            
            hash[i] = i; // initializing with current index
            for(int prev_index = 0; prev_index <i; prev_index ++){
                
                if(arr[prev_index]<arr[i] && 1 + dp[prev_index] > dp[i]){
                    dp[i] = 1 + dp[prev_index];
                    hash[i] = prev_index;
                }
            }
        }
        
        int ans = -1;
        int lastIndex =-1;
        
        for(int i=0; i<n; i++){
            if(dp[i]> ans){
                ans = dp[i];
                lastIndex = i;
            }
        }
        
        vector<int> temp;
        temp.push_back(arr[lastIndex]);
        
        while(hash[lastIndex] != lastIndex){ // till not reach the initialization value
            lastIndex = hash[lastIndex];
            temp.push_back(arr[lastIndex]);    
        }
        
        // reverse the array 
        reverse(temp.begin(),temp.end());
        return temp;
    }
    
