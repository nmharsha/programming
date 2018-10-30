/**
 * Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.
 *
 */

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col_zeros = -1;

        for ( int i = 0; i < matrix[ 0 ].size(); i++ ) if ( matrix[ 0 ][ i ] == 0 ) matrix[ 0 ][ 0 ] = 0;
        for ( int i = 0; i < matrix.size(); i++ ) if ( matrix[ i ][ 0 ] == 0 ) col_zeros = 0;

        for ( int i = 1; i < matrix.size(); i++ ) {
            for ( int j = 1; j < matrix[ 0 ].size(); j++ ) {
                if ( matrix[ i ][ j ] == 0 ) {
                    matrix[ i ][ 0 ] = 0;
                    matrix[ 0 ][ j ] = 0;
                }
            }
        }

        for ( int i = 0; i < matrix.size(); i++ ) {
            for ( int j = 0; j < matrix[ 0 ].size(); j++ ) {
                if ( matrix[ i ][ 0 ] == 0 || matrix[ 0 ][ j ] == 0 ) {
                    matrix[ i ][ j ] = 0;
                }
            }
        }
    }
};
