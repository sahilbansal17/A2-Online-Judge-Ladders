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

int main(){

	#ifndef ONLINE_JUDGE
	freopen("/Users/sahilbansal/Desktop/input.txt","r",stdin);
	freopen("/Users/sahilbansal/Desktop/output.txt","w",stdout);
	#endif

	int n;

	cin >> n;

	vi a(n);

	rep(i, n){
		cin >> a[i];
	}		

	srt(a);

	if(n == 1){
		cout << "-1";
	}
	else if(n == 2){
		if(a[0] == a[1]){
			cout << "1\n";
			cout << a[0];
		}
		else if((a[0] + a[1]) % 2 == 0){
			cout << "3\n";
			cout << a[0] - ( a[1] - a[0] ) << " ";
			cout << (a[0] + a[1])/2 << " ";
			cout << a[1] + ( a[1] - a[0] );
		}
		else{
			cout << "2\n";
			cout << a[0] - ( a[1] - a[0] ) << " ";
			cout << a[1] + ( a[1] - a[0] );
		}
	}
	else{
		int commond_diff_1 = a[1] - a[0];
		int commond_diff_2 = a[n - 1] - a[n - 2];
		int to_add;
		int count = 0;
		if(commond_diff_1 == commond_diff_2){
			fl(i, 2, n - 1){
				int current_common_diff = a[i] - a[i - 1];
				if(current_common_diff != commond_diff_1){
					if(current_common_diff == 2*commond_diff_1){
						to_add = a[i - 1] + commond_diff_1;
						count ++;
					}
					else{
						cout << "0";
						return 0;
					}
					if(count > 1){
						cout << "0";
						return 0;
					}
				}
			}
			if(count == 0 && commond_diff_1 != 0){
				cout << "2\n";
				cout << a[0] - commond_diff_1 << " ";
				cout << a[n - 1] + commond_diff_1;
			}
			else if(commond_diff_1 == 0 && count == 0){
				cout << "1\n";
				cout << a[0];
			}
			else{
				cout << "1\n";
				cout << to_add;
			}
		}
		else{
			if(commond_diff_1 > commond_diff_2){
				if(commond_diff_1 == 2*commond_diff_2){
					to_add = a[0] + commond_diff_2;
					count = 1;
				}
				else{
					cout << "0";
					return 0;
				}
				fl(i, 2, n - 1){
					int current_common_diff = a[i] - a[i - 1];
					if(current_common_diff != commond_diff_2){
						cout << "0";
						return 0;
					}
				}
				cout << "1\n" << to_add;
			}
			else{
				if(commond_diff_2 == 2*commond_diff_1){
					to_add = a[n - 2] + commond_diff_1;
					count = 1;
				}
				else{
					cout << "0";
					return 0;
				}
				fl(i, 2, n - 1){
					int current_common_diff = a[i] - a[i - 1];
					if(current_common_diff != commond_diff_1){
						cout << "0";
						return 0;
					}
				}
				cout << "1\n" << to_add;
			}
		}
	}

	return 0;
}