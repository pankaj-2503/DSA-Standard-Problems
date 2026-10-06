// brute force approach
// TC -> O(M^2+N)

#include <string>
#include <vector>
#include <climits>
using namespace std;

class SolutionBetter {
public:
    string minWindow(string s, string t) {
        int m = s.length(), n = t.length();
        if (m < n) return "";

        vector<int> tFreq(256, 0);
        for (char c : t) tFreq[c]++;

        int minLen = INT_MAX;
        int startIdx = -1;

        for (int i = 0; i < m; i++) {
            vector<int> subFreq(256, 0);
            for (int j = i; j < m; j++) {
                subFreq[s[j]]++;

                // Check validity after adding s[j]
                bool isValid = true;
                for (int k = 0; k < 256; k++) {
                    if (tFreq[k] > 0 && subFreq[k] < tFreq[k]) {
                        isValid = false;
                        break;
                    }
                }

                if (isValid && (j - i + 1) < minLen) {
                    minLen = j - i + 1;
                    startIdx = i;
                    break; // Since j is increasing, current valid window from i is the smallest starting at i
                }
            }
        }

        return startIdx == -1 ? "" : s.substr(startIdx, minLen);
    }
};


// sliding window approach 


class Solution {
public:
    string minWindow(string s, string t) {
        // Step 1: Edge cases
    if (s.empty() || t.empty() || s.size() < t.size()) {
        return "";
    }

    // Step 2: Create frequency array for characters in t
    // Since all chars are ASCII, we can use size 128
    vector<int> requiredCount(128, 0);
    for (char c : t) {
        requiredCount[c]++;
    }

    // Step 3: Initialize window variables
    int left = 0;
    int right = 0;
    int totalNeeded = t.size(); // total number of chars we still need to match
    int minWindowLen = INT_MAX;
    int minWindowStart = 0;

    // Step 4: Start expanding the window using 'right' pointer
    while (right < s.size()) {
        char currentChar = s[right];

        // If this char is needed, decrease the count
        if (requiredCount[currentChar] > 0) {
            totalNeeded--;  // We found one of the required characters
        }

        // Decrease the frequency in requiredCount (can go negative if extra)
        requiredCount[currentChar]--;

        // Move right pointer forward (expand window)
        right++;

        // Step 5: When we have all needed chars in current window
        while (totalNeeded == 0) {
            // Update the minimum window if current is smaller
            int windowLength = right - left;
            if (windowLength < minWindowLen) {
                minWindowLen = windowLength;
                minWindowStart = left;
            }

            // Try to shrink the window from the left
            char leftChar = s[left];
            requiredCount[leftChar]++;

            // If we removed a required char, window is no longer valid
            if (requiredCount[leftChar] > 0) {
                totalNeeded++;
            }

            // Move left pointer to shrink window
            left++;
        }
    }

    // Step 6: Return result
    if (minWindowLen == INT_MAX) {
        return "";
    }
    return s.substr(minWindowStart, minWindowLen);
    }



};

// more cleaned code , TC -> O(M+N)
class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size(),m=t.size();

        if(n==0 || m==0 || n<m) return "";

        vector<int>freq1(256,0),freq2(256,0);

        int unique=0;

        for(auto c:t) freq2[c]++;
        for(int i=0;i<256;i++) if(freq2[i]>0) unique++;

        int i=0,j=0,mn=INT_MAX,match=0,start=0;

        while(j<n){
            char c=s[j];
            freq1[c]++;

            if(freq2[c]>0 && freq1[c]==freq2[c]){
                match++; // match when freq of character are equal in both
            }

            while(match==unique){
                if(j-i+1<mn){
                    mn=min(mn,j-i+1);
                    start=i;
                }
                char ch=s[i];
                freq1[ch]--;

                if(freq2[ch]>0 && freq1[ch]<freq2[ch]) match--;
                i++;
            }



            j++;
        }

        return mn==INT_MAX?"":s.substr(start,mn);


    }
};