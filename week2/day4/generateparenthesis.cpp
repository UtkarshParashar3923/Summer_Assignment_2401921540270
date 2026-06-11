class Solution {
public:
    void backtrack(int open, int close, int maxPairs, string& current, vector<string>& result) {
        if (current.size() == maxPairs * 2) {
            result.push_back(current);
            return;
        }

        if (open < maxPairs) {
            current.push_back('(');
            backtrack(open + 1, close, maxPairs, current, result);
            current.pop_back();
        }
        if (close < open) {
            current.push_back(')');
            backtrack(open, close + 1, maxPairs, current, result);
            current.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        backtrack(0, 0, n, current, result);
        return result;
    }
};

