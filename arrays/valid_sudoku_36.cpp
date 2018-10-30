/**
 * Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
 *
 * Each row must contain the digits 1-9 without repetition.
 * Each column must contain the digits 1-9 without repetition.
 * Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.
 */

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int counts[ 9 ] = { 0 };
        for ( int i = 0; i < 9; i++ ) {
            for ( int j = 0; j < 9; j++ ) {
                if ( board[ i ][ j ] >= '0' && board[ i ][ j ] <='9' ) {
                    count[ board[ i ][ j ] - '0' ]++;
                }
            }
            for ( int k : counts ) {
                if ( k > 1 )
                    return false;
            }

            memset( counts, 0, 9 );

            for ( int j = 0; j < 9; j++ ) {
                if ( board[ j ][ i ] >= '0' && board[ j ][ i ] <= '9' ) {
                    count[ board[ j ][ i ] - '0' ]++;
                }
            }
            for ( int k : counts ) {
                if ( k > 1 ) {
                    return false;
                }
            }

            memset( counts, 0, 9 );
        }

        for ( int i = 0; i < 9; i += 3 ) {
            for ( int j = 0; j < 9; j += 3 ) {
                for ( int k = 0; k < 3; k++ ) {
                    for ( int l = 0; l < 3; l++ ) {
                        if ( board[ i + k ][ j + l ] >= '0' && board[ i + k ][ j + l ] <= '9' ) {
                            counts[ board[ i + k ][ j + l ] - '0' ]++;
                        }
                    }
                }

                for ( int x : counts ) {
                    if ( x > 1 ) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};
