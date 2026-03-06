class Solution {
public:
    // tc -> O(N),sc-O(1)
    int totalFruit(vector<int>& fruits) {

        int last = -1, secondLast = -1;
        int lastCount = 0, curr = 0, ans = 0;

        for(int fruit : fruits){

            if(fruit == last || fruit == secondLast)
                curr++;
            else
                curr = lastCount + 1;

            if(fruit == last)
                lastCount++;
            else{
                lastCount = 1;
                secondLast = last;
                last = fruit;
            }

            ans = max(ans, curr);
        }

        return ans;
    }
};

// Hashing solution  -> tc:O(n),sc:O(1)
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        unordered_map<int,int>m;
        int i=0,j=0,mx=0;
        while(j<n){
            m[fruits[j]]++;
            while(m.size()>2 && i<n){
                m[fruits[i]]--;
                if(m[fruits[i]]==0) m.erase(fruits[i]);
                i++;
            }
            mx=max(mx,j-i+1);
            j++;
        }
        return mx;
    }
};