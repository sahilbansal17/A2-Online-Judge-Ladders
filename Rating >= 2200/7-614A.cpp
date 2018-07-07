#include <bits/stdc++.h>
using namespace std;

// maximum limit for long long
const long long oo = 9223372036854775807;

int main(){

	long long l, r, k;
	scanf("%lld %lld %lld", &l, &r, &k);

	// we need to print all powers of k that lie within the range from l to r inclusive
	// this is a simple brute force problem
	// we start with the 0th power of k and keep on multiplying k
	// as soon as the power exceeds r, we stop

	long long power = 1;
	bool power_exists = false;

	for(int power_num = 0; power < r ; power_num ++){
		if(power >= l){
			power_exists = true;
			printf("%lld ", power);
		}
		// need to avoid overflow when multiplying power with k to get next power of k

		// but the following approach of addition to calculate power will get TLE

		/*
			long long old_power = power;
			for(int ct = 0; ct < k - 1; ct ++){
				power += old_power;
				if(power > r){
					break;
				}
			}
		*/

		// WHAT TO DO NOW?
		// since we want to make sure that (power * k) should be no more than 10^18
		// that means 
		// power <= (10e18 / k)
		// otherwise we don't multiply power with k
		if(power <= oo/k){
			power *= k;
		}
		else{
			break;
		}
	}
	// its better to check for power == r after the loop
	// since r can be 10^18 and k can be 10^9
	// so power goes from 1 to 10^9 to 10^18 and then 
	// power *= k will give power = 10^18 * 10^9 resulting into overflows
	if(power == r){
		power_exists = true;
		printf("%lld ", power);
	}
	if(!power_exists){
		printf("-1\n");
	}

	return 0;
}