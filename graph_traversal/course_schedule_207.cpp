/**
 * There are a total of n courses you have to take, labeled from 0 to n-1.
 *
 * Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
 *
 * Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?
 */

class Solution {
public:

    int dfs( unordered_map< int, vector< int > > &adj_list, int vertex, int* visited ) {
        visited[ vertex ] = 1;

        if ( adj_list.find( vertex ) == adj_list.end() ) {
            visited[ vertex ] = 2;
            return 0;
        }

        for ( int k : adj_list[ vertex ] ) {
            if ( visited[ k ] == 0 ) {
                dfs( adj_list, k, visited );
            } else if ( visited[ k ] == 1 ) {
                return -1;
            }
        }

        visited[ vertex ] = 2;
    }

    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        unordered_map< int, vector< int > > adj_list;

        for ( pair< int, int > prereq : prerequisites ) {
            if ( adj_list.find( prereq ) == adj_list.end() ) {
                vector< int > v;
                v.push_back( prereq.second );
                adj_list[ prereq.first ] = v;
            } else {
                adj_list[ prereq.first ].push_back( prereq.socond );
            }
        }

        int visited[ numCourses ] = { 0 };

        for ( int i = 0; i < numCourses; i++ ) {
            if ( visited[ i ] !=  2 ) {
                if ( dfs( adj_list, i, visited ) == -1 ) {
                    return false;
                }
            }
        }

        return true;
    }
};
