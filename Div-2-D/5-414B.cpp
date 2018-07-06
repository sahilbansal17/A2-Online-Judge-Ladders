#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

// dp[i][j] = no of sequences of length j having i as the first element
int dp[2005][2005];

int main(){

	#ifndef ONLINE_JUDGE
    freopen("/Users/sahilbansal/Desktop/input.txt","r",stdin);
    freopen("/Users/sahilbansal/Desktop/output.txt","w",stdout);
    #endif

	int n, k;

	cin >> n >> k;

	long long ans = 0;

	for(int i = 1; i <= n; i ++){
		dp[i][1] = 1;
	}

	for(int l = 2; l <= k; l ++){
		for(int first = 1; first <= n; first ++){
			dp[first][l] = 0;
			for(int mul = 1; mul*first<= n; mul ++){
				int next = first*mul;
				dp[first][l] += dp[next][l - 1];
				dp[first][l] %= MOD;
			}
		}
	}

	for(int first = 1; first <= n; first ++){
		ans += dp[first][k];
		ans %= MOD;
	}

	cout << ans;

	return 0;
}