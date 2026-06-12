class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, maxLen = 0;
        int n = s.length();

        auto expand = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                --left;
                ++right;
            }
            return make_pair(left + 1, right - 1);
        };

        for (int i = 0; i < n; ++i) {
            auto [l1, r1] = expand(i, i);     // odd-length
            auto [l2, r2] = expand(i, i + 1); // even-length

            if (r1 - l1 + 1 > maxLen) {
                start = l1;
                maxLen = r1 - l1 + 1;
            }

            if (r2 - l2 + 1 > maxLen) {
                start = l2;
                maxLen = r2 - l2 + 1;
            }
        }

        return s.substr(start, maxLen);
    }
};
