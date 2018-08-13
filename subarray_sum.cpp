// Given an unsorted array of non-negative integers, find a continuous
// sub-array which adds to a given number.

#include<iostream>

using namespace std;

int main() {
  int T;
  cin >> T;
  for ( int i = 0; i < T; i++ ) {
    int N;
    int target;
    cin >> N >> target;
    int sumTrack = 0;
    int ii = 0;
    int jj = 0;
    int* arr = new int[N];
    for ( int j = 0; j < N; j++ ) {
      int x;
      cin >> x;
      arr[ j ] = x;
      sumTrack += x;
      jj = j;
      if ( sumTrack > target ) {
        while( sumTrack > target ) {
          ii++;
          sumTrack -= arr[ ii - 1 ];
        }
      }
      if ( sumTrack == target )
        break;
    }
    cout << ii + 1 << " " << jj + 1 << endl;
  }
  return 0;
}
