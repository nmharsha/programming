/**
 * You are given a 2D char matrix representing the game board. 'M' represents an unrevealed mine, 'E' represents an unrevealed empty square, 'B' represents a revealed blank square that has no adjacent (above, below, left, right, and all 4 diagonals) mines, digit ('1' to '8') represents how many mines are adjacent to this revealed square, and finally 'X' represents a revealed mine.
 *
 * Now given the next click position (row and column indices) among all the unrevealed squares ('M' or 'E'), return the board after revealing this position according to the following rules:
 *
 * If a mine ('M') is revealed, then the game is over - change it to 'X'.
 * If an empty square ('E') with no adjacent mines is revealed, then change it to revealed blank ('B') and all of its adjacent unrevealed squares should be revealed recursively.
 * If an empty square ('E') with at least one adjacent mine is revealed, then change it to a digit ('1' to '8') representing the number of adjacent mines.
 * Return the board when no more squares will be revealed.
 */

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        vector< vector< char > > result( board );
        int x = click[ 0 ];
        int y = click[ 1 ];

        switch ( result[ x ][ y ] ) {
            case 'M': {
                result[ x ][ y ] = 'X';
                break;
            }

            case 'E': {
                queue< pair< int, int > > q;
                q.push( make_pair( x, y ) );
                set< pair< int, int > > ss;
                ss.insert(make_pair(x, y));
                while( !q.empty() ) {
                    int count = 0;
                    int _x = q.front().first;
                    int _y = q.front().second;
                    q.pop();
                    vector< pair< int, int > > v;
                    for ( int i = -1; i <= 1; i++ ) {
                        for ( int j = -1; j <= 1; j++ ) {
                            if ( ( i == 0 && j == 0 ) || ( _x + i < 0 ) || ( _x + i >= result.size() ) || ( _y + j <0 ) || ( _y + j >= result[ 0 ].size() ) ) continue;
                            if ( result[ _x + i ][ _y + j ] == 'M' ) {
                                ++count;
                            }

                            if ( result[ _x + i ][ _y + j ] == 'E' ) {
                                if (ss.find(make_pair(_x+i, _y + j)) == ss.end()) {
                                    v.push_back( make_pair( _x + i, _y + j ) );
                                }
                            }
                        }
                    }

                    if ( count > 0 ) {
                        result[ _x ][ _y ] = to_string( count )[ 0 ];
                    } else {
                        result[ _x ][ _y ] = 'B';
                        for ( pair< int, int > p: v ) {
                            q.push( p );
                            ss.insert( p );
                        }
                        v.clear();
                    }
                }
            }
        }

        return result;
    }
};
