/* Given an array and an integer k, find the maximum for each
 * and every contiguous subarray of size k
 */

#include <iostream>
#include <climits>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;
    for ( int i = 0; i < T; i++ ) {
        int N, k;
        cin >> N >> k;
        int* arr = new int[ N ];
        int primary = INT_MIN;
        int secondary = INT_MIN;
        for ( int j = 0; j < N; j++ ) {
           cin >> arr[ j ];
           if ( j >= k - 1 ) {
               if ( j == k - 1 ) {
                   if ( arr[ j ] > primary ) {
                       secondary = primary;
                       primary = arr[ j ];
                   } else if ( arr[ j ] > secondary ) {
                       secondary = arr[ j ];
                   }
                   cout << primary << " ";
               } else {
                   if ( arr[ j ] > primary ) {
                       secondary = primary;
                       primary = arr[ j ];
                   } else if ( arr[ j ] > secondary ) {
                       secondary = arr[ j ];
                   }
                   cout << primary << " ";
               }
           } else {
               if ( arr[ j ] > primary ) {
                   secondary = primary;
                   primary = arr[ j ];
               } else if ( arr[ j ] > secondary ) {
                   secondary = arr[ j ];
               }
           }
        }
        cout << endl;
    }
    return 0;
}
