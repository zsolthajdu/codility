
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// Solution for lesson
// https://codility.com/programmers/lessons/92-tasks_from_indeed_prime_2016_college_coders_challenge/socks_laundering/

int solution(int K, vector<int> &C, vector<int> &D)
{
    auto	pairs = 0, i = 0;

	sort( C.begin(), C.end() );
	sort( D.begin(), D.end() );

	bool finishedClean = false;
	vector<int> unpairedClean;
	if( C.size() > 0 ) {
		for( i=1 ; i<C.size() ; i++ ) {
			if( C[i] == C[i-1] ) {
				pairs++;
				i++;
				if( i == C.size() ) { finishedClean = true; 	break; 	}
			}
			else
				unpairedClean.push_back( C[i-1] );
		}
		if( !finishedClean )
			unpairedClean.push_back( C[i-1] );
	}

	if( 0 != K ) {
        // Stores remaining dirty socks that weren't paired up with clean ones.
        vector<int> remainingDirty;
		size_t c, d, k=0;
		for(c=0,d=0 ; c<unpairedClean.size() && d<D.size() && k<K ; c++) {
			// Try to find pair for unpairedClean[c]
            for( ; d<D.size() && D[d] < unpairedClean[c] ; d++ )
                remainingDirty.push_back(D[d]);

			if( d<D.size() && unpairedClean[c] == D[d] )  {
				pairs++;
				k++;
				d++;
			}
            for( ; d<D.size() && D[d] == unpairedClean[c] ; d++ )
                remainingDirty.push_back(D[d]);
		}

		for( ; d<D.size() ; d++ )
            remainingDirty.push_back(D[d]);

		// Try to clean pairs of dirty socks if we can
        for( d=1 ;  (K-k > 1) && d<remainingDirty.size() ; d++) {
            if( remainingDirty[d-1] == remainingDirty[d] ) {
				// Found pair
				pairs++;
				k += 2;
				d++;
                if( d == remainingDirty.size() )
					break;
			}
		}

	}
	cout << "All pairs : " << pairs << endl;

	return pairs;
}

int main( int argc, char ** argv )
{
	vector<int>  c{ 1,2,1,1 }, d{1,4,3,2,4};

	if( 3 == solution( 2, c, d ) )
		cout << "TEST 1 : OK" << endl;
	else {
		cout << "TEST 1 : FAILED" << endl;
		return -1;
	}
	vector<int>  c1{1 }, d1{3,2,5,5};

	if( 1 == solution( 2, c1, d1 ) )
		cout << "TEST 2 : OK" << endl;
	else {
		cout << "TEST 2 : FAILED" << endl;
		return -1;
	}

	vector<int>  c2{ 1,2 }, d2{ 8,8,8,8, 9 };

	if( 1 == solution( 3, c2, d2 ) )
		cout << "TEST 3 : OK" << endl;
	else {
		cout << "TEST 3 : FAILED" << endl;
		return -1;
	}

}
