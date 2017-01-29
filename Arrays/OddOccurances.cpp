
//
// https://codility.com/programmers/lessons/2-arrays/odd_occurrences_in_array/

#include <vector>
#include <algorithm>
#include <iostream>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

using namespace std;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)

    sort( A.begin(), A.end() );
    int cnt;
    
    for( unsigned int i = 0 ; i< A.size() ; ) {
        cnt = 1;
        int curr = A[i++];
        for( ; i<A.size() && curr == A[i] ; i++, cnt++ ) ;

        //cout << "Found sequence : " << cnt << endl;
        
        if( 1 & cnt )
            return A[i-1];
    }
    return 0;
}

int main( int argc, char ** argv )
{
	return 0;
}
