class Solution {
public:
    bool isValid(string s) {
       
    stack<char> st;

    for (char c : s) {
        // Push opening brackets onto the stack
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else {
            // If stack is empty or doesn't match the current closing bracket
            if (st.empty()) return false;
            char top = st.top();
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                return false;
            }
            st.pop(); // Pop the matched opening bracket
        }
    }

    // Stack should be empty if all brackets matched
    return st.empty();
}

    
};
