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
    int minMeetingRooms( vector<Interval> &intervals ) {
        int numRooms = 0;
        typedef priority_queue< Interval, vector<Interval>, mycomparison > my_pqtype;
        my_pqtype pq( intervals.begin(), intervals.end() );
        sort( intervals.begin(), intervals.end(), myfunction );
        for( vector<Interval>::iterator it = intervals.begin(); it != intervals.end(); ++it ) {
            cout << "The value is: " << ( *it ).start << endl;
            if ( (*it).start < pq.top().end ) {
                numRooms++;
            } else {
                pq.pop();
            }
        }

        return numRooms;
    }
};
