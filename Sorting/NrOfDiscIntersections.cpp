
// Disc intersetion challenge
// https://codility.com/programmers/lessons/6-sorting/number_of_disc_intersections/
//

#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

const int MYMAX = 10000000;

int solution(vector<int> &A) {
	auto cnt = 0;    

	vector<int> left;
	vector<int>  right;
	for( unsigned int i=0 ; i<A.size() ; i++ ) {
		left.push_back( i - A[i] );
		right.push_back( i + A[i] );
	}
	sort( left.begin(), left.end() );
	sort( right.begin(), right.end() );

	// Current left/right position values, as we step through the
	// sorted positions and sum current overlaps
	int cLeft = 0, cRight = 0;
	// Indices into the sorted left/right end pos arrays
	auto iRight = 0, iLeft=0;
	auto leftIndexAdjust = 1;

	for( iRight=0 ; iRight < right.size() ; ++iRight ) {
		cRight = right[iRight];
		
		for( ; iLeft < left.size() && cLeft <= cRight ; ++iLeft ) {
			cLeft = left[ iLeft ];
		}
		if( iLeft == left.size() && cLeft <= cRight ) {
			// Done with left edges, 
			leftIndexAdjust = 0;
		}

		// -1 is to account for left edge of cRight which is not
		// an overlap
		cnt += ( iLeft - 1 - leftIndexAdjust - iRight );
		
		if( cnt > MYMAX )
			return -1;
	}
	return cnt;
}

int main( int argc, char ** argv )
{
	vector<int> A;

	A.push_back( 1 );
	A.push_back( 5 );
	A.push_back( 2 );
	A.push_back( 1 );
	A.push_back( 4 );
	A.push_back( 0 );

	cout << "Intersections : " << solution( A ) << endl;

	return 0;
}


