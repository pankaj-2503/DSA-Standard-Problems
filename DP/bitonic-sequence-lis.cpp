// TC: 2*O(N*N) , SC: 2*O(N)
int LongestBitonicSequence(int n, vector<int> &arr) {
        // code here
        vector<int> dp1(n, 1); // dp1[i] stores the length of the longest increasing subsequence ending at arr[i]
        vector<int> dp2(n, 1); // dp2[i] stores the length of the longest decreasing subsequence ending at arr[i]
    
        // Calculate the longest increasing subsequence
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[j] < arr[i]) {
                    dp1[i] = max(dp1[i], 1 + dp1[j]);
                }
            }
        }
    
        // Reverse the direction of nested loops to calculate the longest decreasing subsequence
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j > i; j--) {
                if (arr[j] < arr[i]) {
                    dp2[i] = max(dp2[i], 1 + dp2[j]);
                }
            }
        }
    
        int maxi = 0;
    
        // Find the maximum length of the bitonic subsequence
        for (int i = 0; i < n; i++) {
            if(maxi<(dp1[i]+dp2[i]) && dp1[i]!=1 && dp2[i]!=1)
            maxi = max(maxi, dp1[i] + dp2[i] - 1);
        }
    
        return maxi;
    }