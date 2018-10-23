// Given a string, find the length of the longest substring without repeating characters.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.lnegth();
        unordered_map< char, int > posMap;
        int i = 0;
        int j = 0;
        int result = 0;
        for ( ; j < size; i++ ) {
            if ( posMap.find( s[ j ] ) != posMap.end() ) {
                i = max( i, posMap[ s[ j ] ] + 1 );
            }

            posMap[ s[ j ] ] = j;
            result = max( result, j - i + 1 );
        }
        return result;
    }
};
