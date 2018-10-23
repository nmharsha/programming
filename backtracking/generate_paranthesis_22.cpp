/**
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
 */

class Solution {
public:

    vector< string > result;

    void generateString(string str, int c, stack<int> s, int n) {
        if ( c == n && s.empty() ) {
            result.push_back( str );
        }
        if ( c < n ) {
            stack< int > s1(s);
            s1.push( 1 );
            generateString( str + "(", c + 1, s1, n );
        }

        if ( !s.empty() ) {
            s.pop();
            generateString( str + ")", c, s, n );
        }
    }
    vector<string> generateParenthesis(int n) {
        string str = "";
        stack<int> s;
        generateString(str, 0, s, n);
        return result;
    }
};
