class Solution {
public:
// Time complexity - O(N) , space complexity - O(1)
    int maxArea(vector<int>& height) {
        int n=height.size();
        int left=0,right=n-1;
        int mxwater=0;
        while(left<right){
            int width=right-left;
            int heightt=min(height[left],height[right]);
            int area=width*heightt;
            mxwater=max(mxwater,area);
            if(height[left]<height[right]) left++;
            else if(height[left]>height[right]) right--;
            else {
                left++;right--;
            }
        }
        return mxwater;
    }
};