/**
 * Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
 *
 * Your algorithm should run in O(n) complexity.
 */

class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        int result = 0;
        unordered_set< int > s;
        for ( int i = 0; i < nums.size(); i++ ) {
            s.insert( nums[ i ] );
        }

        for ( unordered_set< int >::iterator it = s.begin();\
            it != s.end(); ++it ) {
            if ( s.find( *it - 1 ) == s.end() ) {
                int curr_number = *it;
                int seq_len = 1;

                while ( s.find( curr_number + 1 ) != s.end() ) {
                    seq_len++;
                    curr_number++;
                }
                result = max( result, seq_len );
            }
        }

        return result;
    }
};
