// Given a sorted integer array without duplicates, return the summary of its ranges.
//

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector< string > result;

        if ( nums.size() == 0 )
            return result;

        int prev = nums[ 0 ];
        int length = 1;
        for ( int i = 1; i < nums.size(); i++ ) {
            if ( length == 0 ) {
                prev = nums[ i ];
                length++;
                continue;
            }
            if ( nums[ i ] == nums[ i - 1 ] + 1 ) {
                length++;
                continue;
            } else {
                if ( length > 1 ) {
                    result.push_back( to_string( prev ) + "->" + to_string( nums[ i - 1 ] ) );
                } else {
                    result.push_back( to_string( prev ) );
                }
                prev = nums[ i ];
                length = 1;
            }
        }
        if ( length > 1 ) {
            result.push_back( to_string( prev ) + "->" + to_string( nums[ nums.size() - 1 ] ) );
        } else {
            result.push_back( to_string( nums[ nums.size() -1 ] ) );
        }
        return result;
    }
};
