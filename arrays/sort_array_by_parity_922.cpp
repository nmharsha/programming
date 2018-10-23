class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        vector< int > odds;
        vector< int > evens;

        for ( int i = 0; i < A.size(); i++ ) {
            if ( A[ i ] %2 == 0 ) {
                evens.push_back( A[ i ] );
            } else {
                odds.push_back( A[ i ] );
            }
        }

        vector< int > result;
        while( !odds.empty() || !evens.empty() ) {
            int odd = odds.back();
            odds.pop_back();
            result.push_back( odd );

            if ( !evens.empty() ) {
                int even = evens.back();
                evens.pop_back();
                result.push_back( even );
            }
        }

        return result;
    }
};
