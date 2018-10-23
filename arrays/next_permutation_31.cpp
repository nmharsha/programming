/**
 * Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
 * If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
 * The replacement must be in-place and use only constant extra memory.
 *
 * Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 */

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        bool next_present = false;
        if ( nums.size() <= 1 ) {
            return;
        }
        int prev = nums[ 0 ];
        for ( int i = 1; i < nums.size(); i++ ) {
            if ( nums[ i ] > prev ) {
                next_present = true;
                break;
            }
            prev = nums[ i ];
        }

        if ( next_present ) {
            int index = -1;
            for ( int i = nums.size() - 2; i >= 0; i-- ) {
                if ( nums[ i ] < nums[ i + 1 ] ) {
                    int just_greater = -1;
                    for ( int j = i + 1; j < nums.size(); j++ ) {
                        if ( nums[ j ] > nums[ i ] && ( just_greater == -1 || ( nums[ just_greater ] > nums[ j ] ) ) ) {
                            just_greater = j;
                        }
                    }
                    int temp = nums[ i ];
                    nums[ i ] = nums[ just_greater ];
                    nums[ just_greater ] = temp;
                    sort( nums.begin() + i +1, nums.end() );
                    break;
                }
            }
        } else {
            sort( nums.begin(), nums.end() );
        }
    }
};
