/**
 * Given an unsorted array of integers, find the length of longest increasing subsequence.
 */

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if ( n == 0 ) return 0;
        vector< int > dp( n + 1 );

        dp[ 0 ] = 0;
        for ( int i = 1; i <= n; i++ ) {
            int max_so_far = 0;
            for ( int k = 0; k <= i - 1; k++ ) {
                if ( nums[ k ] <= nums[ i ] ) {
                    if ( dp[ k ] + 1 >= max_so_far ) {
                        max_so_far = dp[ k ] + 1;
                    }
                }
            }

            dp[ i ] = max_so_far;
        }

        return max_element( dp.begin(), dp.end() );
    }
};
