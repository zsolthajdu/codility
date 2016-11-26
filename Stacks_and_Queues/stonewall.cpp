
// Stonewall lesson from Codility.com
// 11 - 23 - 16
// https://codility.com/programmers/lessons/7-stacks_and_queues/stone_wall/
// 100 % solution

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int solution(vector<int> &H) {
    auto cnt = 1;
    auto i = 0;
    stack<int>  stk;
    
    if( H.size() == 1 )
        return 1;

	stk.push( H[0] );

	for( i=1 ; i<H.size() ; i++ ) {
		if( H[i] < stk.top() ) {
			while( !stk.empty() && (stk.top() > H[i]) )
				stk.pop();
			if( stk.empty() || stk.top() != H[i] ) {
				cnt++;
				stk.push( H[i] );
			}
		}
		else if( H[i] > stk.top() ) {
         cnt++;
         stk.push( H[i] );
		}
		//cout << "At " << H[i] << " "<< cnt <<" "<< stk.size() << endl;
	}
	return cnt;
}

int main( int argc, char ** argv )
{
	vector<int> A;

	A.push_back( 8 );
	A.push_back( 8 );
	A.push_back( 5 );
	A.push_back( 7 );
	A.push_back( 9 );
	A.push_back( 8 );
	A.push_back( 7 );
	A.push_back( 4 );
	A.push_back( 8 );

	cout << "Minimum blocks needed : " << solution( A ) << endl;

	return 0;
}


