// TC: -> O(sz+∣add∣×fz) where sz=∣expression∣,fz=∣fraction∣.
class Solution {
public:
    vector<pair<int,int>>convert(string &expression){
        vector<pair<int,int>>fraction;
        stringstream s(expression);
        char op;
        int num,den;
        while(s>>num>>op>>den){
            fraction.push_back({num,den});
        }
        return fraction;
    }
    pair<int,int>add(pair<int,int>&x,pair<int,int>&y){
        auto [xp,xq]=x;
        auto [yp,yq]=y;
        long long q=xq*yq;
        long long p=xp*yq+xq*yp;
        long long g=gcd(p,q);
        return {p/g,q/g};
    }
    string fractionAddition(string expression) {
        auto fraction=convert(expression);
        int sz=fraction.size();
        pair<int,int> ans={0,1};
        for(auto i:fraction){
            ans=add(ans,i);
        }
        string s=to_string(ans.first)+"/"+to_string(ans.second);
        return s;
    }
};