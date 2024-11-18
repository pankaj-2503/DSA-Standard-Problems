class Solution {
public:
//Tc:O(N), sC:O(N)
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        s.push(asteroids[asteroids.size()-1]);
        int i = asteroids.size()-2;
        while(i>=0){
            if(s.empty())s.push(asteroids[i]);
            else if(s.top()<0 && asteroids[i]>0){
                if(abs(s.top())<abs(asteroids[i])){
                    s.pop();
                    i++;
                }
                else if(abs(s.top())==abs(asteroids[i]))s.pop();
            }
            else{
                s.push(asteroids[i]);
            }
            i--;
        }
        vector<int>ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};

// or 
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>s;
        for(auto i:asteroids){
            bool alive=true;
            while(!s.empty() && s.top()>0 && i<0){
                if(s.top()<-i){
                    s.pop();
                    continue;
                }
                else if(s.top()==-i) s.pop();
                alive=false;
                break;
            }
            if(alive) s.push(i);
        }
        vector<int>res(s.size());
        for(int i=s.size()-1;i>=0;--i){
            res[i]=s.top();
            s.pop();
        }
        return res;
    }
};