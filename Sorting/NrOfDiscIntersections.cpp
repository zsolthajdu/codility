
// Disc intersetion challenge
// https://codility.com/programmers/lessons/6-sorting/number_of_disc_intersections/
// 100% solution

#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

const int MYMAX = 10000000;

int solution(vector<int> &A) {
    auto cntIntersections = 0;

    vector<long long> left;
    vector<long long> right;
	for( unsigned int i=0 ; i<A.size() ; i++ ) {
        left.push_back( (long long)i - A[i] );
        right.push_back( (long long)i + A[i] );
	}
	sort( left.begin(), left.end() );
	sort( right.begin(), right.end() );

    auto discCount = 1;
    size_t lPos = 0, rPos = 0;
    for( lPos = 1 ; lPos<left.size() && rPos<right.size() ; ) {
        if( left[lPos] <= right[rPos] ) {
            // New disc starting
            cntIntersections += discCount;
            discCount++;
            lPos++;

            if( cntIntersections > MYMAX )
                return -1;
        }
        else if( right[rPos] < left[lPos]) {
            // A disk ended
            discCount--;
            rPos++;
        }
        else if( right[rPos] == left[lPos] ) {
            // One ended, another one starting
            lPos++;
            rPos++;
        }

    }
    return cntIntersections;
}

int main( int argc, char ** argv )
{
    vector<int> A{ 1,5,2,1,4,0 };

	cout << "Intersections : " << solution( A ) << endl;
    cout << "Correct answer is : 11" << endl;

    vector<int> B{ 1, 2147483647, 0 };

    cout << "Intersections : " << solution( B ) << endl;
    cout << "Correct answer is : 2" << endl;

	return 0;
}


