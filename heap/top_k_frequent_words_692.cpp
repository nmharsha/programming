/**
 * Given a non-empty list of words, return the k most frequent elements.
 *
 * Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.
 *
 */

class custom_comparator {
public:
    bool operator() ( pair< string, int > &lhs, pair< string, int > &rhs ) {
        if ( lhs.second == rhs.second ) {
            return ( lhs.first < rhs.first );
        }
        return lhs.second < rhs.second;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector< string > result( k );
        unordered_map< string, int > freq_map;

        for ( string word : words ) {
            if ( freq_map.find( word ) == freq_map.end() ) {
                freq_map[ word ] = 1;
            } else {
                freq_map[ word ]++;
            }
        }

        priority_queue< pair< string, int >, vector< pair< string, int > >, custom_comparator > pq( freq_map.begin(), freq_map.end() );
        for ( int i = 0; i < k; i++ ) {
            result[ i ] = pq.top().first;
            pq.pop();
        }

        return result;
    }
};
