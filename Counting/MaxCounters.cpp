
#include <algorithms>
#include <vector>

//
// Solution for 
// https://codility.com/programmers/lessons/4-counting_elements/max_counters/

vector<int> solution(int N, vector<int> &A) {
	
    int maximum = 0;

    vector<int> values(N,0);
    
    for( size_t i=0 ; i< A.size() ; i++ ) {
        if( A[i] > N ) {
            for( size_t j=0 ; j <  N ; j++ )
                values[j] = maximum;
        }
        else {
            if( (++values[ A[i]-1 ]) > maximum )
                maximum = values[ A[i]-1 ];
        }
    }
    
    return values;
}


