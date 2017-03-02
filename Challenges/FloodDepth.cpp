
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

//
// Solution for
// https://codility.com/programmers/lessons/90-tasks_from_indeed_prime_2015_challenge/flood_depth/


int solution( vector<int> &A)
{
	int	maxElev = 0;	// Location of previous - left - peak
	int	minElev = 0;	// Location if deepes point
	int	maxDepth = 0;	// Maximum depth found so far

	for( int i = 1 ; i<A.size() ; i++ ) {

		if( A[i] > A[maxElev] ) {
			// Found next - right - peak

			// Check if depth of this valley is larger then prev max
			maxDepth = std::max( A[maxElev]-A[minElev], maxDepth );

			// This new peak will be beginning of next valley
			minElev = maxElev = i;
		}
		else if( A[i] > A[minElev] ) { // Going UP
			// Going out of the valley. Check if depth increased
			maxDepth = std::max(A[i] - A[minElev], maxDepth );
		}
		else if( A[i] < A[minElev] )
			// Going further down
			minElev = i;
	}
	return maxDepth;
}

int main( int argc, char ** argv )
{
	vector< int > In{ 1,3,2,1,2,1,5,3,3,4,2 };
	cout << "TEST 1 : " << (( 2 == solution( In ) ) ? "OK" : "FAIL") << endl;

	vector< int > In2{ 1,5,4,3,2,3,4,5 };
	cout << "TEST 2 : " << (( 3 == solution( In2 ) ) ? "OK" : "FAIL") << endl;

	vector< int > In3{1, 9, 8, 7, 4, 8, 7, 10, 31, 2};
	cout << "TEST 3 : " << (( 5 == solution( In3 ) ) ? "OK" : "FAIL") << endl;

	vector< int > In4{1, 4, 5, 4, 3, 4, 1, 2, 3, 1 };
	cout << "TEST 4 : " << (( 2 == solution( In4 ) ) ? "OK" : "FAIL") << endl;

	vector< int > In5{2, 1, 3};
	cout << "TEST 5 : " << (( 1 == solution( In5 ) ) ? "OK" : "FAIL") << endl;

	vector< int > In6{2, 4, 3};
	cout << "TEST 6 : " << (( 0 == solution( In6 ) ) ? "OK" : "FAIL") << endl;

	return 0;
}
