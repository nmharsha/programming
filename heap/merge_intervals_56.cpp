/** Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei),
 * find the minimum number of conference rooms required.
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

class mycomparison {
public:
    bool operator() (const Interval& lhs, const Interval& rhs ) const {
        return ( lhs.end > rhs.end );
    }
};

bool myfunction( Interval lhs, Interval rhs ) {
    return ( lhs.start < rhs.start );
}

class Solution {
public:
    vector< Interval > merge( vector< Interval > &intervals ) {
        vector< Interval > result;

        if ( intervals.size() == 0 ) {
            return result;
        }

        sort( intervals.begin(), intervals.end(), myfunction );
        result.push_back( intervals );

        for ( vector< Interval >::iterator it = intervals.begin(); it != intervals.end(); ++it ) {
            if ( result.back().end > (*it).start ) {
                result.back().end = max( result.back().end, (*it).end );
            } else {
                result.push_back( *it );
            }
        }

        return result;
    }
};
