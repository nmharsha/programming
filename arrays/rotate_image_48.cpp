/**
 * You are given an n x n 2D matrix representing an image.
 *
 * Rotate the image by 90 degrees (clockwise).
 */

// This is incorrect. CHeck leetcode for the correct version

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int off = 0;
        for ( int size = n; size > 0; size-- ) {
            for ( int i = off; i < size; i++ ) {
                int a = mat[ off ][ off ];
                int b = mat[ off ][ size - 1 - off ];
                int c = mat[ size - 1 - off ][ size - 1 - off ];
                int d = mat[ size - 1 - off ][ off ]

                int temp = d;
                d = c;
                c = b;
                b = a;
                a = temp;

                mat[ off ][ off ] = a;
                mat[ off ][ size - 1 - off ] = b;
                mat[ size - 1 - off ][ size - 1 - off ] = c;
                mat[ size - 1 - off ][ off ] = d;

            }
            off++;
        }
    }
};
