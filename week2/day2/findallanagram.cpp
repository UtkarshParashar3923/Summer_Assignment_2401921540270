class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> ans;

        int n = s.size();
        int m = p.size();

        if (m > n) return ans;

        vector<int> freqP(26, 0);
        vector<int> freqWin(26, 0);

        for (int i = 0; i < m; i++) {
            freqP[p[i] - 'a']++;
            freqWin[s[i] - 'a']++;
        }

        if (freqP == freqWin)
            ans.push_back(0);

        for (int i = m; i < n; i++) {

            freqWin[s[i] - 'a']++;

            freqWin[s[i - m] - 'a']--;

            if (freqP == freqWin)
                ans.push_back(i - m + 1);
        }

        return ans;
    }
};
