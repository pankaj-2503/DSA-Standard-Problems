class Solution {
public:
// TC: O(NlogN) , sC: O(n)
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int>m;
        for(auto i:nums){
            m[i]++;
        }
        int n=nums.size();
        vector<int>ans;
        for(auto i:m){
            if(i.second>n/3) ans.push_back(i.first);
        }
        return ans;
    }
};

// Using moore's voting algorithm 
// TC: O(N)

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
          int candidate1 = 0, candidate2 = 1;  
        int count1 = 0, count2 = 0;  

        for (int num : nums) {  
            if (num == candidate1) {  
                count1++;  
            } else if (num == candidate2) {  
                count2++;  
            } else if (count1 == 0) {  
                candidate1 = num;  
                count1 = 1;  
            } else if (count2 == 0) {  
                candidate2 = num;  
                count2 = 1;  
            } else {  
                count1--;  
                count2--;  
            }  
        }  
        
        // Step 2: Verify the candidates  
        count1 = count2 = 0;  
        for (int num : nums) {  
            if (num == candidate1) count1++;  
            else if (num == candidate2) count2++;  
        }  

        vector<int> result;  
        int n = nums.size();  
        if (count1 > n / 3) result.push_back(candidate1);  
        if (count2 > n / 3) result.push_back(candidate2);  
        
        return result;  
    }
};