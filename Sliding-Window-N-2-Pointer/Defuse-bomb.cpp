class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n=code.size();
        vector<int>ans(n,0);
        if(k==0) return ans;
        int l=0,cursum=0;
        for(int r=0;r<abs(k)+n;r++){
            cursum+=code[r%n];

            if(r-l+1>abs(k)){
                cursum-=code[l%n];
                l=(l+1)%n;
            }
            if(r-l+1==abs(k)){
                if(k>0){
                    ans[(l-1+n)%n]=cursum;
                }else if(k<0){
                    ans[(r+1)%n]=cursum;
                }
            }

        }
        return ans;
    }
};