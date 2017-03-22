

#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// Solution for challenge
// https://codility.com/programmers/lessons/91-tasks_from_indeed_prime_2016_challenge/rectangle_builder_greater_area/

const long MAX_RES = 1000000000;

int solution(vector<int> &A, int X)
{
	vector<int> available_pieces; // Sizes that occur more than twice
	vector< bool > have4orMore;   // true for sizes that occur more than 3 times (can be used by itself)
	long count = 0, total = 0;
	int		i;

	if( A.size() < 4 )
		return 0;

	sort( A.begin(), A.end() );

	count = 1;
	for( i=1 ; i<A.size() ; i++ ) {
		if( A[i] == A[i-1] )
			count++;
		else {
			// Process previous run
			if( count > 1 ) {
				available_pieces.push_back( A[i-1] );
				have4orMore.push_back( count>3 ? true : false );
			}
			count = 1;
		}
	}
	// Process last run
	if( count > 1 ) {
		available_pieces.push_back( A[i-1] );
		have4orMore.push_back( count>3 ? true : false );
	}

	count = 0;
	// Iterate through segments that we have at least two of.
	// Pair them with other segments that form an area big enough
	for(  i=0 ; i<available_pieces.size() ; i++ ) {

		int minComplement = ceil( (double)X / available_pieces[i] );

		auto ComplementStartPos = lower_bound( available_pieces.begin(), available_pieces.end(), minComplement );
				//- available_pieces.begin();

		count += available_pieces.end()-ComplementStartPos;

		if( minComplement <= available_pieces[i] ) {
			// Take out one for pairing available_pieces[i] with itself
			count--;
			if( have4orMore[i] ) {
				// Add it back globally if it is a valid case (there's 4 of that size)
				total++;
			}
		}
		//cout << "i=" << i << ", MinC=" << minComplement << ", count = " << count << endl;
	}

	total += count / 2;
	return total < MAX_RES ? total : -1;
}



int main( int argc, char ** argv )
{
	vector<int>  v{ 1,2,5,1,1,2,3,5,1};

	if( 2 == solution( v, 5 ) )
		cout << "TEST 1 : OK" << endl;
	else {
		cout << "TEST 1 : FAILED" << endl;
		return -1;
	}

	vector<int>  v2{ 6,6,6,6,6,6 };
	if( 1 == solution( v2, 10 ) )
		cout << "TEST 2 : OK" << endl;
	else {
		cout << "TEST 2 : FAILED" << endl;
		return -1;
	}

	vector<int> v3;
	for( int i=1 ; i<=2000 ; i++ )
		v3.push_back(i);
	cout << "TEST 3 : " << (( 0 == solution( v3, 10 ) ) ? "OK" : "FAIL") << endl;
	if( 0 == solution( v3, 10 ) )
		cout << "TEST 3 : OK" << endl;
	else {
		cout << "TEST 3 : FAILED" << endl;
		return -1;
	}

	return 0;
}

