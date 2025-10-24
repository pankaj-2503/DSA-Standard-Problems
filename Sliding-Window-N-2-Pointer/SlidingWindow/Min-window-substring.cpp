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