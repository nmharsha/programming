/** Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
*/

class Solution {
public:
    vector< string > result;
    map< int, vector< char > > const m {
        { 2, { 'a', 'b', 'c' } },
        { 3, { 'd', 'e', 'f' } },
        { 4, { 'g', 'h', 'i' } },
        { 5, { 'j', 'k', 'l' } },
        { 6, { 'm', 'n', 'o' } },
        { 7, { 'p', 'q', 'r', 's' } },
        { 8, { 't', 'u', 'v' } },
        { 9, { 'w', 'x', 'y', 'z' } }
    }
    void letterCombination( string sol, int index, string digits ) {
        if ( index >= digits.size() - 1 ) {
            result.push_back( sol );
        } else {
            int num = digits[ index ];
            for ( vector< char >::iterator it = m[ num ].begin(); it != m[ num ].end(); ++it ) {
                letterCombination( sol + ( *it ), index + 1, digits );
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        string sol = "";
        letterCombination( sol, 0, digits );
        return result;
    }
};
