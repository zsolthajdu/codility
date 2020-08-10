#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countDiv( int A, int B, int K )
{
	int r = 0;

	int ad = A/K, ar = A%K;
	int bd = B/K;
	r = bd - ad;
	if( ar == 0 )
		r++;

	return r;
}

int main( int argc, char ** argv )
{
	cout << "COuntDiv 6-11 , 2 : " <<  countDiv( 6,11,2 ) << endl;
	cout << "COuntDiv 6-11 , 100 : " <<  countDiv( 6,11,100 ) << endl;
	cout << "COuntDiv 0-11 , 10 : " <<  countDiv( 0,11,10 ) << endl;
	cout << "COuntDiv 0-2000000000 , 2000000000 : " <<  countDiv( 0,2000000000,2000000000 ) << endl;

	return 0;
}
