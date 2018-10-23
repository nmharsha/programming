/**
 * Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.
 *
 * Example 1:
 *
 * Input: "bcabc"
 * Output: "abc"
 * Example 2:
 *
 * Input: "cbacdcbc"
 * Output: "acdb"
 */

class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack< char > st;
        int char_counts[ 26 ] = {0};
        for ( int i = 0; i < s.length(); i++ ) {
            char_counts[ s[ i ] - 'a' ]++;
        }

        bool visited[ 26 ] = {0};

        for ( int  i = 0; i < s.length(); i++ ) {
            int index = s[ i ] - 'a';
            char_counts[ index ]--;
            if ( visited[ index ] ) {
                continue;
            }

            while ( !st.empty() && s[ i ] < st.top() && char_counts[ st.top() - 'a' ] != 0 ) {
                char top = st.top();
                visited[ top - 'a' ] = false;
                st.pop();
            }
            st.push( s[ i ] );
            visited[ index ]  = true;
        }

        string result = "";

        while( !st.empty() ) {
            result += st.top();
            st.pop();
        }

        reverse( result.begin(), result.end() );

        return result;
    }
};
