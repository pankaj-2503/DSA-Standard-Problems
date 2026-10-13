class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            ans[(i+k)%n]=nums[i];
        }
        nums=ans;
    }
};


// right rotate by k

// without taking space
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k%=n;
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};


//left rotate by k

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k%=n;
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
        reverse(nums.begin(),nums.end());
    }
};