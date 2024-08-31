     long long int helper(string s, int k){
        vector<int> freq(26, 0);
        long long int count = 0;
        int left = 0;
        int distinct = 0;
        
        for(int right = 0; right < s.size(); right++){
            freq[s[right]-'a']++;
            if(freq[s[right]-'a'] == 1) distinct++;
            
            while(distinct > k){
                freq[s[left]-'a']--;
                if(freq[s[left]-'a'] == 0) distinct--;
                left++;
            }
            
            count += (right - left + 1);
        }
        return count;
    }
    long long int substrCount (string s, int k) {
    	//code here.
    	return helper(s,k)-helper(s,k-1);
    }