
// https://codility.com/programmers/lessons/5-prefix_sums/min_avg_two_slice/
// 

#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {

	unsigned 	int i = 0;

	if( A.size() < 2 )
		return 0;

	double min = (double)(A[0] + A[1] ) /2;
	int minPos = 0;

	for( i=1 ; i < (A.size()-1) ; i++ ) {
		double n = (double)(A[i] + A[i+1]) / 2;
		if( n < min ) {
			min = n;
			minPos = i;
		}
	}
	
	for( i=0 ; i<(A.size()-2) ; i++ ) {
		double n = (double)(A[i] + A[i+1] + A[i+2]) / 3;
		if( n < min ) {
			min = n;
			minPos = i;
		}
	}

	return minPos;
}

int main( int argc, char ** argv )
{
    vector<int> a{ 4, 2, 2, 5, 1, 5, 8 };

    cout << "Min average slice starts at " << solution( a ) << endl;
	return 0;
}
