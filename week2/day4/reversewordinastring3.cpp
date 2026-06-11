class Solution {
public:
    
    string reverseWord(string word) {
        if(word.length() <= 1)
            return word;

        return reverseWord(word.substr(1)) + word[0];
    }

    string reverseWords(string s) {

        int pos = s.find(' ');

        // Base case: last word
        if(pos == string::npos)
            return reverseWord(s);

        string firstWord = s.substr(0, pos);

        return reverseWord(firstWord) + " " +
               reverseWords(s.substr(pos + 1));
    }
};
