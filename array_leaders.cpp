/* Write a program to print all the LEADERS in the array.
 * An element is leader if it is greater than all the elements
 * to its right side. The rightmost element is always a leader
 */

#include <iostream>
#include <climits>
#include <stack>

using namespace std;

int main() {
    int T;
    cin >> T;
    for ( int i = 0; i < T; i++ ) {
        int N;
        cin >> N;
        int* arr = new int[ N ];
        for ( int j = 0; j < N; j++ ) {
           cin >> arr[ j ];
        }
        int maxSoFar = INT_MIN;
        stack< int > v;
        for ( int j = N - 1; j >= 0; j-- ) {
           if ( arr[ j ] > maxSoFar ) {
              maxSoFar = arr[ j ];
              v.push( arr[ j ] );
           }
        }

        while ( !v.empty() ) {
            cout << v.top() << " ";
            v.pop();
        }
        cout << endl;
    }
    return 0;
}
