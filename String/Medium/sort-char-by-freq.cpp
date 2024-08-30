class Solution {
public:
// tC: O(N+NlogN) , SC:O(N)
    string frequencySort(string s) {
        int n=s.size();
        unordered_map<char,int>m;
        for(auto i:s) m[i]++;
        vector<pair<int,char>>v;
        for(auto i:m){
            v.push_back({i.second,i.first});
        }
        sort(v.begin(),v.end(),[&](pair<int,char>a,pair<int,char>b){
            return a.first>b.first;
        });
        string ans="";
        for(auto i:v){
            int times=i.first;
            string p(times,i.second);
            ans+=p;
            p.clear();
        }
        return ans;
    }
};