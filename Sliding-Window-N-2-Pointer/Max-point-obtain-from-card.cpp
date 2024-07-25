class Solution {
public:
    int maxScore(vector<int>& points, int k) {
        int n=points.size();
        int total=accumulate(points.begin(),points.end(),0);
        int sum=0;
        int left=0,right=0,mx=0;

        if(k==n) return total;

        while(right<n){
            sum+=points[right];
            if(right-left+1<n-k){
                right++;
            }
            else{
                mx=max(mx,total-sum);
                sum-=points[left];
                left++;right++;
            }
        }
        return mx;
    }
};