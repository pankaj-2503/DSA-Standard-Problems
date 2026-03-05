// TC -> O(N^2) , SC -> O(1)
int maxProduct(vector<int>& nums) {
    int n = nums.size();
    int maxProd = INT_MIN;

    for(int i = 0; i < n; i++) {
        int prod = 1;
        for(int j = i; j < n; j++) {
            prod *= nums[j];
            maxProd = max(maxProd, prod);
        }
    }
    return maxProd;
}

// TC -> O(N) , SC -> O(1);
int maxProduct(vector<int>& nums) {
    int n = nums.size();
    int maxProd = nums[0];
    int currMax = nums[0];  // max product ending at current position
    int currMin = nums[0];  // min product ending at current position

    for(int i = 1; i < n; i++) {
        // If negative, swap max and min (sign flip)
        if(nums[i] < 0) swap(currMax, currMin);

        // Either extend existing product or start fresh
        currMax = max(nums[i], currMax * nums[i]);
        currMin = min(nums[i], currMin * nums[i]);

        maxProd = max(maxProd, currMax);
    }
    return maxProd;
}


// TC -> O(N) , SC -> O(1)
int maxProduct(vector<int>& nums) {
    int n = nums.size();
    int maxProd = INT_MIN;
    int prefix = 1, suffix = 1;

    for(int i = 0; i < n; i++) {
        prefix = (prefix == 0) ? 1 : prefix;
        suffix = (suffix == 0) ? 1 : suffix;

        prefix *= nums[i];
        suffix *= nums[n - 1 - i];

        maxProd = max(maxProd, max(prefix, suffix));
    }
    return maxProd;
}