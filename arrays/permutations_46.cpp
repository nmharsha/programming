/**
 * Given a collection of distinct integers, return all possible permutations.
 */

class Solution {
public:

    void swap( vector< int > &arr, int i, int j ) {
        int temp = arr[ i ];
        arr[ i ] = arr[ j ];
        arr[ j ] = temp;
    }

    void permute( vector< int > &nums, vector< vector< int > > &result, int l, int r ) {
        if ( l == r ) {
            result.push_back( nums );
        }
        for ( int i = l; i <= r; i++ ) {
            swap( nums, l, i );
            permute( nums, result, l + 1, r );
            swap( nums, l, i );
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector< vector< int > > result;
        permute( nums, result, 0, nums.size() - 1 );
        return result;
    }
};
