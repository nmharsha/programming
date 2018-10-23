/** Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.

*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if ( matrix.size() <= 0 ) {
            return false;
        }
        int r = matrix.size();
        int c = matrix[ 0 ].size();
        int posR = r - 1;
        int posC = 0;

        do {
            if ( matrix[ posR ][ posC ] == target ) {
                return true;
            }

            if ( matrix[ posR ][ posC ] > target ) {
                posR--;
            } else {
                posC++;
            }
            if ( posR < 0 || posC >= c ) {
                return false;
            }
        } while ( true );

        return false;

    }
};
