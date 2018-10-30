/**
 * Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
 */

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector< vector< int > > result( n, vector< int >( n, 0 ) );

        if ( n == 0 )
            return result;

        int topLimit = 0;
        int bottomLimit = n - 1;
        int leftLimit = 0;
        int rightLimit = n - 1;

        int counter = 1;

        while( ( leftLimit <= rightLimit ) && ( topLimit <= bottomLimit ) ) {
            for ( int i = leftLimit; i <= rightLimit; i++ ) {
                result[ topLimit ][ i ] = counter++;
            }
            topLimit++;
            if ( topLimit > bottomLimit )
                break;

            for ( int i = topLimit; i <= bottomLimit; i++ ) {
                result[ i ][ rightLimit ] = counter++;
            }
            rightLimit--;
            if ( rightLimit > leftLimit ) break;

            for ( int i = rightLimit; i >= leftLimit; i-- ) {
                result[ bottomLimit ][ i ] = counter++;
            }
            bottomLimit--;
            if ( topLimit > bottomLimit ) break;

            for ( int i = bottomLimit; i >= topLimit; i-- ) {
                result[ i ][ leftLimit ] = counter++;
            }
            leftLimit++;

        }

        return result;
    }
};
