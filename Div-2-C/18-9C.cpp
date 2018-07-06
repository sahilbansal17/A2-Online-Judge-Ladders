#include <bits/stdc++.h>

using namespace std;

/* Template file for Online Algorithmic Competitions */
/* Typedefs */
	/* Basic types */
	typedef long long ll;
	typedef unsigned long long ull;
	/* STL containers */
	typedef vector <int> vi;
	typedef vector <ll> vll;
	typedef pair <int,int> pii;
	typedef pair <ll,ll> pll;
	typedef vector < pii > vpii;
	typedef vector < pll > vpll;
/* Macros */
	/* Loops */
	#define fl(i,a,b) for(int i(a);i<(b);i++)
	#define rep(i,n) fl(i,0,n)
	#define rfl(i,a,b) for(int i(a);i>=(b);i--)
	/* Algorithmic functions */
	#define srt(v) sort((v).begin(),(v).end())
	/* STL container methods */
	#define pb push_back
	#define mp make_pair
	/* String methods */
	#define slen(s) s.length()
	/* Shorthand notations */
	#define F first
	#define S second
	#define MOD 1000000007
	#define MAX 100010

int intToBinary(int n){
	
	int res = 0;
	/*/
	int max = pow(2, 9);
	if(n > max){
		return -1;
	}
	//*/
	rfl(j, 31, 0){
		if(n & (1 << j)){
			res *= 10;
			res += 1;
		}
		else{
			res *= 10;
		}
	}
	return res;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("/Users/sahilbansal/Desktop/input.txt","r",stdin);
	freopen("/Users/sahilbansal/Desktop/output.txt","w",stdout);
	#endif

	int n;

	cin >> n;

	// answer is just the number of binary numbers from 1 to n

	int start = 1;

	// cout << intToBinary(n);

	int ans = 0;
	while(start <= 512){
		if(intToBinary(start) <= n){
			ans ++;
		}
		else{
			break;
		}
		start ++;
	}

	cout << ans;
	return 0;
}