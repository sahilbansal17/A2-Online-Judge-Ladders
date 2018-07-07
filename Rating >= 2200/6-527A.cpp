#include <bits/stdc++.h>
using namespace std;

long long count_squares = 0;

void gcd_counter(long long x, long long y){

	if(y == 0){
		return ;
	}
	count_squares += x / y;
	gcd_counter(y, x % y);
}

int main(){

	long long longer_side, shorter_side;
	scanf("%lld %lld", &longer_side, &shorter_side);

	// the longer side is 'a'
	// the shorter side is 'b'
	// (b * a) = (b * (a - b)) + (b * b)
	// i.e. we obtain a square of length equal to shorter side
	// and the longer side reduces by that length
	// so, till the difference (a - b) would be more than b, we continue 
	// getting same size square of length b
	// no. of such squares = (a / b)
	// the next shorter side would be a % b.
	// this is similar to the gcd routine, except that we want the sum of
	// integer division performed on arguments on gcd function 
	// till we reach the last call of the gcd routine

	gcd_counter(longer_side, shorter_side);

	cout << count_squares;
	return 0;
}