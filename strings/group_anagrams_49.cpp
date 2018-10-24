/**
 * Given an array of strings, group anagrams together.
 */

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map< string, vector< int > > hash_map;
        vector< vector< string > > result;

        for ( int  i = 0; i < strs.size(); i++ ) {
            string key = "";
            int char_counts[ 26 ] = { 0 };
            for ( char ch : strs[ i ] ) {
                char_counts[ ch - 'a' ]++;
            }

            for ( int j = 0; j < 26; j++ ) {
                key += to_string( char_counts[ j ] ) + "#";
            }

            if ( hash_map.find( key ) == hash_map.end() ) {
                vector< int > v;
                v.push_back( i );
                hash_map[ key ] = v;
            } else {
                hash_map[ key ].push_back( i );
            }
        }

        for ( auto it = hash_map.begin(); it != hash_map.end(); it++ ) {
            vector< string > group;
            for ( int ind: it->second ) {
                group.push_back( strs[ ind ] );
            }
            result.push_back( group );
        }

        return result;
    }
};
