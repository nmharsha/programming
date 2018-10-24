/**
 * Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.
 */

class Solution {
public:
    string multiply(string num1, string num2) {
	    int m = num1.length();
        int n = num2.length();

        int pos[ m + n ];

        for ( int i = m - 1; i >= 0; i-- ) {
            for ( int j = n - 1; j >= 0; j-- ) {
                int prod = ( num1[ i ] - '0' ) * ( nums2[ j ] - '0' );
                int p1 = i + j;
                int p2 = i + j + 1;

                int sum = prod + pos[ i + j ];

                pos[ p1 ] += sum / 10;
                pos[ p2 ] = sum % 10;
            }
        }

        string result = "";
        for ( int p : pos ) if ( !( sb.length() == 0 && p == 0 ) ) result += to_string( p );
        return result.length() == 0 ? "0" : result;
    }
};
