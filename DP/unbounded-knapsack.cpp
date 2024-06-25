#include <bits/stdc++.h>
using namespace std;

// Function to solve the unbounded knapsack problem
int knapsackUtil(vector<int>& wt, vector<int>& val, int ind, int W, vector<vector<int>>& dp) {
    // Base case: if we're at the first item
    if (ind == 0) {
        // Calculate and return the maximum value for the given weight limit
        return (W / wt[0]) * val[0];
    }
    
    // If the result for this index and weight limit is already calculated, return it
    if (dp[ind][W] != -1)
        return dp[ind][W];
        
    // Calculate the maximum value without taking the current item
    int notTaken = 0 + knapsackUtil(wt, val, ind - 1, W, dp);
    
    // Calculate the maximum value by taking the current item
    int taken = INT_MIN;
    if (wt[ind] <= W)
        taken = val[ind] + knapsackUtil(wt, val, ind, W - wt[ind], dp);
        
    // Store the maximum value in the DP table and return it
    return dp[ind][W] = max(notTaken, taken);
}

// Function to solve the unbounded knapsack problem
int unboundedKnapsack(int n, int W, vector<int>& val, vector<int>& wt) {
    vector<vector<int>> dp(n, vector<int>(W + 1, -1)); // Create a DP table
    
    // Call the utility function to calculate the maximum value
    return knapsackUtil(wt, val, n - 1, W, dp);
}
