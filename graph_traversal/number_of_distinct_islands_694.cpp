**
 * Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.
 *
 * Count the number of distinct islands. An island is considered to be the same as another if and only if one island can be translated (and not rotated or reflected) to equal the other.
 *
 */

class Solution {
public:

    typedef vector< vector< int > > vvi;

    vector< int > explore( int i, int j, vvi &grid, vvi &visited ) {
        vector< int > dfs_path;
        stack< tuple< int, int, int > > s;
        s.push( make_tuple( i, j, 0 ) );

        while ( !s.empty() ) {
            int x = get< 0 >( s.top() );
            int y = get< 1 >( s.top() );
            int label = get< 2 >( s.top() );
            s.pop();
            if ( x < 0 || y < 0 || x >= grid.size() || y >= grid[ 0 ].size() || visited[ x ][ y ] || grid[ x ][ y ] == 0 ) continue;
            s.push( make_tuple( x + 1, y, 1 ) );
            s.push( make_tuple( x - 1, y, 2 ) );
            s.push( make_tuple( x, y + 1, 3 ) );
            s.push( make_tuple( x, y - 1, 4 ) );
            dfs_path.push_back( label );
            visited[ x ][ y ] = 1;
        }
        return dfs_path;
    }

    int numDistinctIslands(vector<vector<int>>& grid) {
        unordered_set< vector< int > > unique_islands;
        vector< vector< int > > visited( grid.size(), vector< int >( grid[ 0 ].size() );

        for ( int  i= 0; i < grid.size(); i++ ) {
            for ( int j = 0; j < grid[ 0 ].size(); j++ ) {
                if ( !visited[ i ][ j ] ) {
                    if ( grid[ i ][ j ] == 0 ) {
                        visited[ i ][ j ] = 1;
                        continue;
                    } else {
                        unique_islands.insert( explore( i, j ) );
                    }
                }
            }
        }
        return unique_islands.size();
    }
};
