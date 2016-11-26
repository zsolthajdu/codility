
//
// Description
// https://codility.com/programmers/lessons/10-prime_and_composite_numbers/min_perimeter_rectangle/
//

#include <cmath>
#include <iostream>

using namespace std;

int solution(int N) {
	int max = (int)sqrt( (double)N );
	max++;
	int minper = 2 * N + 2;

	if( N == 1 )
		return 4;

	int c , x;
	for( c=2 ; c<max ; c++ ) {
		if( 0 == (N % c) ) {
			x = N/c;
			if( (2*c + 2*x) < minper )
				minper = 2*c + 2*x;
		}
	}
	return minper;
}

int main( int argc, char ** argv )
{
	auto area = 30;

	cout << "For area " << area << " minimum perimeter is " << solution( area ) << endl;

	return 0;
}

