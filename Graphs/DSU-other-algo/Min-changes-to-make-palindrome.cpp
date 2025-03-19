
//  Question asks you to find minimum number of changes to make a string palindrome such that every kth character is 
//  eg. input:cbpecbbc , k=3 
//     output: 2
// eg. input: abzbz , k=3
//     output: 1



// TC: O(n), SC: O(n)
// Idea: We can use DSU to solve this problem. We can connect all the characters at kth distance from each other and also connect the characters at n-k-1 distance from each other.

int findMinChange(string currentPassword,int k){
    int n=currentPassword.size();   
    vector<int>parent(n);
    iota(parent.begin(),parent.end(),0);
    function<int(int)>find=[&](int x){
        return parent[x]==x?x:parent[x]=find(parent[x]);
    };
    function<void(int,int)>unionSets=[&](int x,int y){
        x=find(x);
        y=find(y);
        if(x!=y){
            parent[x]=y;
        }
    };

    for(int i=0;i<n;i++){
        if(i+k<n) unionSets(i,i+k);
        unionSets(i,n-i-1);
    }
    unordered_map<int,vector<int>>groups;
    for(int i=0;i<n;i++){
        int root=find(i);
        groups[root].push_back(i);
    }
    int totalchanges=0;
    for(auto i:groups){
        vector<int>&indices=i.second;
        unordered_map<char,int>freq;
        for(auto j:indices){
            freq[currentPassword[j]]++;
        }
        int maxFreq=0;
        for(auto j:freq){
            maxFreq=max(maxFreq,j.second);
        }
        totalchanges+=indices.size()-maxFreq;
    }
    return totalchanges;
}