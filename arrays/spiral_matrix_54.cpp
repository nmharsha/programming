/** Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
*/

class Solution {
public:
    vector< int > spiralOrder( vector< vector< int > > &matrix ) {
        vector < int > solution;
        if ( matrix.size() == 0 || matrix[ 0 ].size() == 0 ) {
            return solution;
        }

        int topLimit = 0;
        int bottomLimit = matrix.size() - 1;
        int leftLimit = 0;
        int rightLimit = matrix[ 0 ].size() - 1;

        while( ( leftLimit <= rightLimit ) && ( topLimit <= bottomLimit ) ) {
            for ( int i = leftLimit; i <= rightLimit; i++ ) {
                solution.push_back( matrix[ topLimit ][ i ] );
            }
            topLimit++;

            if ( topLimit > bottomLimit ) {
                break;
            }

            for ( int i = topLimit; i <= bottomLimit; i++ ) {
                solution.push_back( matrix[ i ][ rightLimit ] );
            }
            rightLimit--;

            if ( leftLimit > rightLimit ) {
                break;
            }

            for ( int i = rightLimit; i>= leftLimit; i-- ) {
                solution.push_back( matrix[ bottomLimit ][ i ] );
            }
            bottomLimit--;

            if ( topLimit > bottomLimit ) {
                break;
            }

            for ( int i = bottomLimit; i>= topLimit; i-- ) {
                solution.push_back( matrix[ i ][ leftLimit ] );
            }

            leftLimit++;
        }

        return solution;
    }
};

