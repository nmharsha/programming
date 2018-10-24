/**
 * Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters represent different tasks.Tasks could be done without original order. Each task could be done in one interval. For each interval, CPU could finish one task or just be idle.
 *
 * However, there is a non-negative cooling interval n that means between two same tasks, there must be at least n intervals that CPU are doing different tasks or just be idle.
 *
 * You need to return the least number of intervals the CPU will take to finish all the given tasks.
 */

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int char_counts[ 26 ] = { 0 };
        for ( char ch: tasks ) {
            char_counts[ ch - 'A' ]++;
        }

        priority_queue< int > pq;

        for ( int f : char_counts ) {
            if ( f > 0 ) {
                pq.push( f );
            }
        }

        int time = 0;

        while ( !pq.empty() ) {
            int i = 0;
            vector< int > temp;
            while ( i <= n ) {
                if ( !pq.empty() ) {
                    if ( pq.top() > 1 ) {
                        temp.push_back( pq.top() - 1 );
                        pq.pop();
                    } else {
                        pq.pop();
                    }
                }
                time++;
                if ( pq.empty() && temp.size() == 0 ) {
                    break;
                }
                i++;
            }

            for ( int l : temp ) {
                pq.push( l );
            }
        }

        return time;
    }
};
