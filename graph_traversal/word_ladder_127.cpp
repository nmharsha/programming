/**
 * Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:
 *
 * Only one letter can be changed at a time.
 * Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
 * Note:
 *
 * Return 0 if there is no such transformation sequence.
 * All words have the same length.
 * All words contain only lowercase alphabetic characters.
 * You may assume no duplicates in the word list.
 * You may assume beginWord and endWord are non-empty and are not the same.
 */

int getdiff( string s1, string s2 ) {
    int diff = 0;
    for ( int i = 0; i < s1.length(); i++ ) {
        if ( !( s1[ i ] == s2[ i ] ) ) {
            diff++;
        }
    }
    return diff;
}

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		int result = 0;
        queue< pair< string, int > > q;
        q.push( make_pair( beginWord, 0 ) );
        bool visited[ wordList.size() ] = { 0 };

        while( !q.empty() ) {
            string s = q.front().first;
            int pos = q.front().second;
            q.pop();
            for ( int i = 0; i < wordList.size(); i++ ) {
                string ref = wordList[ i ];
                if ( getdiff( s, ref ) == 1 && !visited[ i ] ) {
                    if ( ref == endWord ) {
                        result = pos + 1;
                        return result + 1;
                    }
                    visited[ i ] = true;
                    q.push( make_pair( ref, pos + 1 ) );
                }
            }
        }

        return result;
    }
};
