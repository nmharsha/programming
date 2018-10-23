/** Given a non-empty array of numbers, a0, a1, a2, … , an-1, where 0 ≤ ai < 231.
 * Find the maximum result of ai XOR aj, where 0 ≤ i, j < n.
 * Could you do this in O(n) runtime?
 */

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int max = 0;
        int mask = 0;
        for ( int i = 31; i >= 0; i-- ) {
            mask = mask | ( 1 << i );
            set<int> s;
            for ( int j = 0; j < nums.size(); j++ ) {
                s.insert( mask & nums[ j ] );
            }

            int tmp = max | ( 1 << i );
            for ( set<int>::iterator it = s.begin(); it != s.end(); ++it ) {
                if ( s.find( tmp ^ *it ) != s.end() ) {
                    max = tmp;
                    break;
                }
            }

        }
        return max;
    }
};


