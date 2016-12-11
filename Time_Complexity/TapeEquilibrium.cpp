
// https://codility.com/programmers/lessons/3-time_complexity/tape_equilibrium/
// O(N) 100 % solution

#include <climits>
#include <vector>
#include <iostream>

using namespace std;


int solution(vector<int> &A) {
    
	auto leftSum = 0;
	auto rightSum = 0;
	auto minDiff = INT_MAX;

	if( A.size() < 2 )
		return -1;

	auto i=A.begin();
	for( ; i != A.end() ; ++i ) 
        rightSum += *i;

	for( i = A.begin() ; i != (A.end()-1) ; ++i ) {
		leftSum += *i;
		rightSum -= *i;
		if( abs( leftSum - rightSum ) < minDiff )
			minDiff = abs( leftSum - rightSum );
    }
    return minDiff;
}


int main( int argc, char** argv )
{
	vector<int> a;

	a.push_back( 3 );
	a.push_back( 1 );
	a.push_back( 2 );
	a.push_back( 4 );
	a.push_back( 3 );

	cout << "Minimal difference = " << solution( a ) << endl;	
	return 0;
}


