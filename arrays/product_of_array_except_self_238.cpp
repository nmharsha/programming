/**
 * Given an array nums of n integers where n > 1,  return an array output such that output[i]
 * is equal to the product of all the elements of nums except nums[i].
 */

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector< int > result( nums.size()  );

        if ( nums.size() <= 0 ) {
            return result;
        }
        int product_so_far = 1;
        result[ 0 ] = 1;
        for ( int i = 1; i < nums.size(); i++ ) {
            result[ i ] = nums[ i - 1 ] * result[ i - 1 ];
        }

        int var = 1;

        for ( int i = nums.size() - 1; i >= 0; i--  ) {
            result[ i ] = result[ i ] * var;
            var = var * nums[ i ];
        }

        return result;

    }
};
