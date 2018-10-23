/**
 * A city's skyline is the outer contour of the silhouette formed by all the buildings
 * in that city when viewed from a distance. Now suppose you are given the locations and
 * height of all the buildings as shown on a cityscape photo (Figure A), write a program
 * to output the skyline formed by these buildings collectively (Figure B).
 * The geometric information of each building is represented by a triplet of integers [Li, Ri, Hi], where Li and Ri are the x coordinates of the left and right edge of the ith building, respectively, and Hi is its height. It is guaranteed that 0 ≤ Li, Ri ≤ INT_MAX, 0 < Hi ≤ INT_MAX, and Ri - Li > 0. You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.
 *
 * For instance, the dimensions of all buildings in Figure A are recorded as: [ [2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8] ] .
 *
 * The output is a list of "key points" (red dots in Figure B) in the format of [ [x1,y1], [x2, y2], [x3, y3], ... ] that uniquely defines a skyline. A key point is the left endpoint of a horizontal line segment. Note that the last key point, where the rightmost building ends, is merely used to mark the termination of the skyline, and always has zero height. Also, the ground in between any two adjacent buildings should be considered part of the skyline contour.
 */

int myfunction( pair< int, int > &a, pair< int, int > &b ) {
    if ( a.first != b.first ) {
        return ( a.first - b.first );
    }
    return ( a.second - b.second );
}

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector< pair< int, int > > result;
        vector< pair< int, int > > heights;

        for ( int i = 0; i < buildings.size(); i++ ) {
            heights.push_back( make_pair( buildings[ i ][ 0 ], -buildings[ i ][ 2 ] ) );
            heights.push_back( make_pair( buildings[ i ][ 1 ], buildings[ i ][ 2 ] ) );
        }

        sort( heights.begin(), heights.end(), myfunction );
        multiset< int > pq;
        pq.insert( 0 );

        int prev = 0;

        for ( int i = 0; i < heights.size(); i++ ) {
            if ( heights[ i ].second < 0 ) {
                pq.insert( heights[ i ].second );
            } else {
                auto itr = pq.find( heights[ i ].second );
                if ( itr != pq.end() ) {
                    pq.erase( itr );
                }
            }

            int cur = *pq.rbegin();
            if ( prev != cur ) {
                result.push_back( make_pair( heights[ i ].first, cur ) );
                prev = cur;
            }
        }
        return result;

    }
};
