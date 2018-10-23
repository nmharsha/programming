// Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

// Note:

// The same word in the dictionary may be reused multiple times in the segmentation.
// You may assume the dictionary does not contain duplicate words.

class Solution {
public:
    bool wordBreak( string s, vector< string > &wordDict ) {
        unordered_set< string > wordDictSet( wordDict.begin(), wordDict.end() );
        int dict_size = s.size();
        int dp[ dict_size + 1 ];
        dp[ 0 ] = 1;
        for ( int i = 1; i <= dict_size; i++ ) {
            for ( int j = 0; j < i; j++ ) {
                if ( dp[ j ] && wordDictSet.find( s.substr(j, (i-j) + 1 )  ) != wordDictSet.end() ) {
                    dp[ i ] = true;
                    break;
                }
            }
        }
        return dp[ dict_size ];
    }
};
