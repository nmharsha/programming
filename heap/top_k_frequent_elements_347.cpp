/**
 * Given a non-empty array of integers, return the k most frequent elements.
 */

class custom_comparison {
public:
    bool operator() ( const pair< int, int > &lhs, const pair< int, int > &rhs ) {
        return ( lhs.second < rhs.second );
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector < int > result;
        unordered_map< int, int > m;
        for ( int num: nums ) {
            if ( m.find( num ) == m.end() ) {
                m[ num ] = 1;
            } else {
                m[ num ] = m[ num ] + 1;
            }
        }

        priority_queue< pair< int, int >, vector< pair < int, int > >, custom_comparison > pq( m.begin(), m.end() );

        for ( int i = 0; i < k; i++ ) {
            result.push_back( pq.top().first );
            pq.pop();
        }
        return result;
    }
};
