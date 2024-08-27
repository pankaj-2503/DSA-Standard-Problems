class Solution {
public:
// TC: O(N)
    bool lemonadeChange(vector<int>& bills) {
        int cnt5=0,cnt10=0,cnt20=0;
        bool ok=true;
        for(int i=0;i<bills.size();i++){
            if(bills[i]==10){
                if(cnt5>0){
                    cnt5--;cnt10++;
                }else{
                    ok=false;break;
                }
            }
            else if(bills[i]==20){
                if(cnt5>0 && cnt10>0){
                    cnt5--;cnt10--;
                }
                else if(cnt5>2){
                    cnt5-=3;
                }
                else{ok=false;break;}
            }
            else cnt5++;
        }
        if(ok) return true;
        else return false;
    }
};