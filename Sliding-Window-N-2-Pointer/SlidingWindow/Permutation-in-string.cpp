class Solution {
public:
    // TC -> O(n)
    bool checkInclusion(string s1, string s2) {
        int n1=s1.size(),n2=s2.size();
        if(n1>n2) return false;
        // Approach is that we are maintaining sliding window of s1 length over s2
        vector<int>freq1(26,0);
        vector<int>freq2(26,0);
        for(int i=0;i<n1;i++){
            freq1[s1[i]-'a']++;
            freq2[s2[i]-'a']++;
        }
        // At each step compar freq1 and freq1, move the window by removing the frequency of the character going out of the window and adding the one coming in.
        for(int i=n1;i<n2;i++){
            if(freq1==freq2) return true;
            freq2[s2[i-n1]-'a']--;
            freq2[s2[i]-'a']++;
        }
        return freq1==freq2;
    }
};