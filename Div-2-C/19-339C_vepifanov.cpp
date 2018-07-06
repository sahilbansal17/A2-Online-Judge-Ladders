#include <bits/stdc++.h>

using namespace std;

/* Template file for Online Algorithmic Competitions */
/* Typedefs */
    /* Basic types */
    typedef long long           ll;
    typedef unsigned long long ull;
    /* STL containers */
    typedef vector <int>    vi;
    typedef vector <ll>     vll;
    typedef pair <int, int> pii;
    typedef pair <ll, ll>   pll;
    typedef vector < pii >  vpii;
    typedef vector < pll >  vpll;
    typedef vector <string> vs;
    typedef vector < vi >   vvi;
/* Macros */
    /* Loops */
    #define fl(i, a, b)     for(int i(a); i<(b); i++)
    #define rep(i, n)       fl(i, 0, n)
    #define rep1(i, n)      fl(i, 1, n)
    #define rfl(i, a, b)    for(int i(a);i>=(b);i--)
    /* Algorithmic functions */
    #define srt(v)          sort((v).begin(),(v).end())
    /* STL container methods */
    #define pb              push_back
    #define mp              make_pair
    /* String methods */
    #define slen(s)         s.length()
    /* Shorthand notations */
    #define F               first
    #define S               second
    #define MOD             1000000007
    #define MAX             100010
    #define re              return 
    #define sz(x)           ((int) (x).size())
    #define all(x)          ((x).begin(), (x).end())
    #define sqr(x)          ((x) * (x))
    #define fill(x, y)      memset(x, y, sizeof(x))
/* Templates */
template<class T> T abs(T x) { re x > 0 ? x : -x; }

int n;
int m;
int x[1000];
int was[1000][11][11];
string s;

// i : current step no. 
// diff : balance on the scales 
// last : last weight used
int solve(int i, int diff, int last) {
    if(i > 0 && (diff <= 0 || diff > 10)){
        re 0;
    }
    if(i == m){
        cout << "YES\n";
        for(int j = 0; j < m; j++){
            cout << x[j] << " ";
        }
        cout << "\n";
        re 1;
    }
    if(was[i][diff][last]){
        re 0;  
    } 
    was[i][diff][last] = 1;
    for(int j = 0; j < 10; j++){
        if(s[j] == '1' && j != last){
            x[i] = j + 1;
            if(solve(i + 1, j + 1 - diff, j)){
                re 1;
            }
        }   
    }
    re 0;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/Users/sahilbansal/Desktop/input.txt","r",stdin);
    freopen("/Users/sahilbansal/Desktop/output.txt","w",stdout);
    #endif

    cin >> s;
    cin >> m;
    if(!solve(0, 0, 10)){
        cout << "NO\n";
    }
    return 0;
}