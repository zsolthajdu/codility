
#include <vector>
#include <iostream>

using namespace std;

//
// Solution for 
// https://codility.com/programmers/lessons/4-counting_elements/max_counters/

vector<int> solution(int N, vector<int> &A) {
	
	int newMax = 0;  // Keeps track of max value since last 'all max' fill
	int lastMax = 0;  // The max value at last 'all max' fill

	vector<int> values(N,0);

	for( auto & a : A ) {
		a--; // A[] values are 1-based
		if( a >= N )  // From now on newMax->lastMax is used as base of increment
			lastMax = newMax; // vector elements are not changed !
		else {
			// Counter is incremented.
			// Base value is lastMax, if current counter is smaller (meaning
			// that lastMax should be there really )
			values[a] = max<int>( lastMax, values[a]) + 1;
			newMax = max<int>( values[a], newMax );
		}
	}
	// Update counter values that weren't updated with max value at the time
	// of lst 'all max' fill operation.
	for( auto & a : values )
		a = max<int>( a, lastMax );

	return values;
}

int main( int argc, char ** argv )
{
	vector< int > In{ 3,4,4,6,1,4,4};
	vector<int> result( solution( 5, In ));

	cout << "Final sequence : " << endl;
	for( auto & a : result )
		cout << a << ", ";
	cout << endl;

	return 0;
}
