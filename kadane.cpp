#include <iostream>
#include <climits>

using namespace std;

int main() {
  int n;
  cin >> n;
  for( int i = 0; i < n; i++ ) {
    int k;
    cin >> k;
    int maxSoFar = INT_MIN;
    int currentSum = INT_MIN;
    for ( int j = 0; j < k; j++ ) {
      int x;
      cin >> x;
      if ( j == 0 ) {
        currentSum = x;
        maxSoFar = x;
        continue;
      }
      if ( currentSum + x <= 0 ) {
        currentSum = x;
      } else {
        if ( currentSum < 0 )
          currentSum  = 0;
        currentSum += x;
      }
      if ( currentSum > maxSoFar ) {
        maxSoFar = currentSum;
      }
    }
    cout << maxSoFar << endl;
  }
  return 0;
}
