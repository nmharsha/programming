/**
 * Given an input string , reverse the string word by word.
 */

class Solution {
public:
    void reverseWords(vector<char>& str) {
        reverse(str.begin(), str.end());
        int prev = 0;
        int curr = 0;
        for ( int i = 0; i < str.size(); i++ ) {
            if(str[i] == ' ') {
                reverse(str.begin() + prev, str.begin() + i);
                prev = i + 1;
            }
        }
        reverse(str.begin() + prev, str.end());
    }
};
