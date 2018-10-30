/**
 * Given an encoded string, return it's decoded string.
 *
 * The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.
 *
 * You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.
 *
 * Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].
 */

class Solution {
public:
    string decodeString(string s) {
        string result = "";
        string str = "";
        stack < pair< int, string > > st;
        int i =0;

        while ( i < s.length() ) {
            if ( s[ i ] >= '0' && s[ i ] <= '9' ) {
                size_t pos_b = s.find_first_of( '[', i + 1 );
                int count = stoi( s.substr( i, pos_b - i ) );
                st.push( make_pair( count, str ) );
                str = "";
                i = pos_b + 1;
            } else {
                if ( s[ i ] == ']' ) {
                    string temp = st.top().second;
                    int c = st.top().first;
                    st.pop();

                    while ( c-- > 0 ) {
                        temp += str;
                    }
                    str = temp;
                } else {
                    str += s[ i ];
                }
                i++;
            }
        }
        return str;
    }
};
