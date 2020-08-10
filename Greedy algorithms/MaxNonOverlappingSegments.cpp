
// https://app.codility.com/programmers/lessons/16-greedy_algorithms/max_nonoverlapping_segments/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxNonOverlappingSegments(vector<int> &A, vector<int> &B)
{
	if( A.empty() || B.empty() || A.size() != B.size()  )
		return 0;

	// Segments sorted on B (endings)
	// Just keep track of end of 'current' segment and take the next one
	// that start after it.
	int cnt = 1, current = 0;
	for( int i = 1 ; i < A.size() ; i++ ) {
		if( A[i] > B[current] ) {
			cnt++;
			current = i;
		}
	}
	return cnt;
}

int main( int argc, char ** argv )
{
	vector<int> a = { 1,3,7,9,9 };
	vector<int> b = { 5,6,8,9,10 };

	cout << "non overlap : " << maxNonOverlappingSegments( a,b ) << endl;
}

