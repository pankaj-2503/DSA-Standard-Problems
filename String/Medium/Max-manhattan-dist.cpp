class Solution {
    public:
    
    // Time complexity - O(4*N), Space complexity - O(1)
    
        int solve(char a,char b,string &s,int k){
            int dist=0,mx=0;
            for(int i=0;i<s.size();i++){
                if(a==s[i] or b==s[i]) dist++;
                else{
                    if(k>0){k--;dist++;}
                    else{
                        mx=max(mx,dist);
                        dist--;
                    }
                }
                cout<<dist<<" ";
            }
            mx=max(mx,dist);
            return mx;
        }
    
        int maxDistance(string s, int k){
            if(k==s.size()) return k;
    
            // good direction
            int nw=solve('N','W',s,k);
            int ne=solve('N','E',s,k);
            int sw=solve('S','E',s,k);
            int se=solve('S','W',s,k);
    
            return max({nw,ne,sw,se});
        }
    };