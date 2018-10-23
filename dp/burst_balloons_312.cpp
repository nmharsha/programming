/**
 * Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums.
 * You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins.
 * Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.
 *
 * Find the maximum coins you can collect by bursting the balloons wisely.
 *
 * Note:
 *
 * You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
 * 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100
 */

class Solution {
public:
    int maxCoins( vector< int >& nums ) {
        int n = 1;
        int nums_arr[ nums.size() + 2 ];
        for ( int x : nums ) if ( x > 0 ) nums_arr[ n++ ] = x;
        nums_arr[ 0 ] = nums_arr[ n++ ] = 1;

        int dp[ n ][ n ] = {};

        for ( int k = 2; k < n; k++ ) {
            for ( int left = 0; left < n-k; left++ ) {
                int right = left + k;
                for ( int i = left + 1; i < right; i++ ) {
                    dp[ left ][ right ] = max( dp[ left ][ right ],\
                        nums_arr[ left ] * nums_arr[ i ] * nums_arr[ right ] + dp[ left ][ i ] + dp[ i ][ right ] );
                }
            }
        }

        return dp[ 0 ][ n - 1 ];
    }
};
