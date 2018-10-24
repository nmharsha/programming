/**
 * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 *
 * (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
 *
 * You are given a target value to search. If found in the array return its index, otherwise return -1.
 *
 * You may assume no duplicate exists in the array.
 *
 * Your algorithm's runtime complexity must be in the order of O(log n).
 */

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        int mid = ( l + r ) / 2;

        int pivot_index = -1;

        while ( l <= r ) {
            if ( nums[ l ] <= nums[ r ] ) {
                if ( nums[ ( l - 1 + nums.size() ) % nums.size() ] > nums[ l ] ) {
                    pivot_index = l;
                    break;
                }

                if ( nums[ ( r + 1 ) % nums.size() ] < nums[ r ] ) {
                    pivot_index = ( r + 1 ) % nums.size();
                    break;
                }
            }
            if ( nums[ l ] > nums[ mid ] ) {
                r = mid - 1;
            } else if ( nums[ r ] < nums[ mid ] ) {
                l = mid + 1;
            }
        }

        int new_arr[ nums.size() ];
        for ( int i = 0; i < nums.size(); i++ ) {
            new_arr[ i ] = nums[ ( i + pivot_index ) % nums.size() ];
        }

        for ( int num : new_arr ) {
            cout << num << " ";
        }

        l = 0;
        r = nums.size();

        while ( l <= r ) {
            int mid = ( l + r ) / 2;
            if ( new_arr[ l ] == target ) {
                return ( l + pivot_index ) % nums.size();
            }

            if ( new_arr[ r ] == target ) {
                return ( r + pivot_index ) % nums.size();
            }

            if ( new_arr[ mid ] < target ) {
                cout << "Larger" << endl;
                l = mid + 1;
            } else {
                cout << "Lesser" << endl;
                r = mid - 1;
            }
        }

        return -1;
    }
};
