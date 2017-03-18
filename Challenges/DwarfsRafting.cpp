
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

//
// Solution for
// https://codility.com/programmers/lessons/91-tasks_from_indeed_prime_2016_challenge/dwarfs_rafting/

// Keep track of free spaces in the four quadrants.
int	freeSpaces[4]  ;

// Keep track of weight - dwarfs - in the four quadrants.
int	dwarfs[4];

pair<int,int> getPos( string & pos )
{
	int  col, row;

	if( pos.length() == 3 ) {
		row = 10*(pos[0]-'0') + pos[1]-'0' ;
		col = pos[2] - 'A';
	}
	else {
		row = pos[0] - '0' ;
		col = pos[1] - 'A';
	}
	return pair<int,int>( row, col );
}

/**
 * @brief fixDiag Try to balance two diagonal quadrants
 * @param a  Quadrant nr
 * @param b  Quadrant nr
 * @return  Number of dwarfs added to achieve balance. 0 means failure.
 */
int fixDiag(int a, int b )
{
	int change = 0;

	if( dwarfs[a] < dwarfs[b] ) {
		int diff = dwarfs[b] - dwarfs[a];
		if( freeSpaces[a] >= diff ) {
			freeSpaces[a] -= diff;
			dwarfs[a] += diff;
			change += diff;
		}
	}
	else {
		int diff = dwarfs[a] - dwarfs[b];
		if( freeSpaces[b] >= diff ) {
			freeSpaces[b] -= diff;
			dwarfs[b] += diff;
			change = diff;
		}
	}
	return change;
}

int solution( int N, string& S, string &T )
{
	auto	allSpaces  = N*N;
	auto	res = 0;

	if( N < 2 || N > 26 )
		return -1;
	for( int i=0 ; i<4 ; i++ ) {
		freeSpaces[i] = allSpaces/4;
		dwarfs[i] = 0;
	}

	// Read barrel positions
	size_t posstart = 0, posend;
	if( S.length() > 0 )
		for( bool done = false ; !done ; posstart = posend+1 ) {
			posend = S.find_first_of(' ', posstart );
			if( string::npos == posend ) {
				done = true;
				posend = S.length();
			}
			string pos = S.substr( posstart, posend-posstart );
			pair<int,int> barrel{ getPos(pos) };
			if ( barrel.first <= N/2 ) {
				if( barrel.second < N/2 )  freeSpaces[0]--;
				else	freeSpaces[1]--;
			}
			else {
				if( barrel.second < N/2 ) 		freeSpaces[2]--;
				else	freeSpaces[3]--;
			}
		}
	// Read dwarf positions
	posstart = 0;
	if( T.length() > 0 )
		for( bool done = false ; !done ; posstart = posend+1 ) {
			posend = T.find_first_of(' ', posstart );
			if( string::npos == posend ) {
				done = true;
				posend = T.length();
			}
			string pos = T.substr( posstart, posend-posstart );
			pair<int,int> dwarf{ getPos(pos) };
			if ( dwarf.first <= N/2 ) {
				if( dwarf.second < N/2 ) { freeSpaces[0]--;  dwarfs[0]++;  }
				else {  freeSpaces[1]--;   dwarfs[1]++; }
			}
			else {
				if( dwarf.second < N/2 )  { freeSpaces[2]--; dwarfs[2]++; }
				else { freeSpaces[3]--; dwarfs[3]++;  }
			}
		}

	// First just add enough dwarfs to balance current situation
	if( dwarfs[0] != dwarfs[3] ) {
		int n = fixDiag(0,3);
		if( 0 == n )  	return -1;
		else    	res += n;
	}
	if( dwarfs[1] != dwarfs[2] ) {
		int n = fixDiag( 1,2 );
		if( 0 == n ) return -1;
		else    res += n;
	}

	// Figure out how many more can we add with keeping
	// it balanced.
	int Diag1Spaces = min( freeSpaces[0], freeSpaces[3]);
	int Diag2Spaces = min( freeSpaces[2], freeSpaces[1]);

	res += 2*Diag1Spaces + 2*Diag2Spaces;
	return res;
}

int main( int argc, char ** argv )
{
	string test1[] = { { "1B 1C 4B 1D 2A" } , { "3B 2D" } };
	cout << "TEST 1 : " << (( 6 == solution( 4, test1[0], test1[1] ) ) ? "OK" : "FAIL") << endl;
	string test2[] = { { "1B 1C 4B 2A" } , { "4C 1D 2D" } };
	cout << "TEST 2 : " << (( 7 == solution( 4, test2[0], test2[1] ) ) ? "OK" : "FAIL") << endl;
	string test3[] = { { "" } , { "" } };
	cout << "TEST 3 : " << (( 4 == solution( 2, test3[0], test3[1] ) ) ? "OK" : "FAIL") << endl;
	cout << "TEST 4 : " << (( 16 == solution( 4, test3[0], test3[1] ) ) ? "OK" : "FAIL") << endl;

	return 0;
}
