/**
 * A message containing letters from A-Z is being encoded to numbers using the following mapping:
 *
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * Given a non-empty string containing only digits, determine the total number of ways to decode it.
 *
 */

class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();

        if ( n <= 0 ) return 0;

        int dp[ n + 1 ] = { 0 };

        dp[ 0 ] = 1;
        dp[ 1 ] = s[ 0 ] != '0' ? 1 : 0;

        for ( int i = 2; i <= n; i++ ) {
            string f( s.begin() + i - 1, s.begin() + i );
            int first = stoi( f );
            string sec( s.begin() + i - 2, s.begin() + i );
            int second = stoi( sec );

            if ( first >=1 && first <= 9 ) {
                dp[ i ] += dp[ i - 1];
            }

            if ( second >= 10 && second <= 26 ) {
                dp[ i ] += dp[ i - 2 ];
            }
        }

        return dp[ n ];

    }
};
