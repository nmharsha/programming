/**
 * Given an undirected graph, return true if and only if it is bipartite.
 *
 * Recall that a graph is bipartite if we can split it's set of nodes into two independent subsets A and B such that every edge in the graph has one node in A and another node in B.
 *
 * The graph is given in the following form: graph[i] is a list of indexes j for which the edge between nodes i and j exists.  Each node is an integer between 0 and graph.length - 1.  There are no self edges or parallel edges: graph[i] does not contain i, and it doesn't contain any element twice.
 */

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        unordered_set< int > partition_1[ 2 ];
        queue< pair< int, int > > q;
        q.push( make_pair( 0, 0 ) );

        int visited[ graph.size() ];
        visited[0] = 0;

        fill_n( visited, graph.size(), -1 );

        for ( int i = 0; i < graph.size(); i++ ) {
            if ( visited[i] == -1) {
                q.push(make_pair(i, 0));
            }

            while ( !q.empty() ) {
				int node = q.front().first;
				int level = q.front().second;
				q.pop();
				if ( visited[ node ] == -1 ) {
					visited[ node ] = level;

					for ( int node_t : graph[ node ] ) {
						q.push( make_pair( node_t, (level + 1)%2) );
					}
				} else {
					if ( visited[ node ] != level ) {
						return false;
					}
				}
        	}
        }
        return true;
    }
};

