class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastSeen(256, -1); // Stores last seen positions of characters
        int maxLen = 0;
        int start = 0; // Start index of current substring

        for (int i = 0; i < s.length(); ++i) {
            if (lastSeen[s[i]] >= start) {
                start = lastSeen[s[i]] + 1;
            }
            lastSeen[s[i]] = i;
            maxLen = max(maxLen, i - start + 1);
        }

        return maxLen;
    }
};

