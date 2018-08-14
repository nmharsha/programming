/* Given an array of n positive integers. Write a program to find the sum
 * of maximum sum subsequence of the given array such that the intgers in
 * the subsequence are sorted in increasing order. For example, if input
 * is {1, 101, 2, 3, 100, 4, 5}, then output should be 106 (1 + 2 + 3 + 100),
 * if the input array is {3, 4, 5, 10}, then output should be 22 (3 + 4 + 5 + 10)
 * and if the input array is {10, 5, 4, 3}, then output should be 10
*/


#include <iostream>
#include <climits>

using namespace std;

int lis( int* arr, int N );

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
        cout << lis( arr, N ) << endl;
        free( arr );
    }
    return 0;
}

int lis( int* arr, int N ) {
    int* res = new int[ N ];
    for ( int i = 0; i < N; i++ ) {
       res[ i ] = arr[ i ];
    }
    for ( int i = 0; i < N; i++ ) {
        for ( int j = 0; j < i; j++ ) {
            if ( ( arr[ i ] > arr[ j ] ) && ( res[ j ] + arr[ i ] > res[ i ] ) ) {
                res[ i ] = res[ j ] + arr[ i ];
            }
        }
    }
    int maxSoFar = INT_MIN;
    for ( int i = 0; i < N; i++ ) {
        if ( res[ i ] > maxSoFar ) {
            maxSoFar = res[ i ];
        }
    }
    return maxSoFar;
}
