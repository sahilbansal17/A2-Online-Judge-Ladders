#include <bits/stdc++.h>

using namespace std;

/* Template file for Online Algorithmic Competitions */
/* Typedefs */
    /* Basic types */
    typedef long long           ll;
    typedef long double         ld;
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
    typedef vector < vll >  vvll;
    typedef vector < vpii > vvpii;
    typedef set <int>       si;
typedef complex <double>    pnt;
typedef vector <pnt>        vpnt;
typedef priority_queue <pii, vpii, greater<pii> > spq;
/* Macros */
    /* Loops */
    #define fl(i, a, b)     for(int i(a); i < (b); i ++)
    #define rep(i, n)       fl(i, 0, n)
    #define rep1(i, n)      fl(i, 1, n)
    #define rfl(i, a, b)    for(int i(a); i >= (b); i --)
    /* Algorithmic functions */
    #define srt(v)          sort((v).begin(), (v).end())
    /* STL container methods */
    #define pb              push_back
    #define mp              make_pair
    #define eb              emplace_back
    #define mt              make_tuple
    /* String methods */
    #define slen(s)         s.length()
    /* Shorthand notations */
    #define F               first
    #define S               second
    #define re              return 
    #define sz(x)           ((int) (x).size())
    #define all(x)          (x).begin(), (x).end()
    #define sqr(x)          ((x) * (x))
    #define fill(x, y)      memset(x, y, sizeof(x))
    #define endl            '\n'
    /* Mathematical */
    #define oo              0x3f3f3f3f
    #define LLINF           1000111000111000111LL
    #define PI              3.14159265358979323
    /* Debugging purpose */
    #define trace1(x)                cerr << #x << ": " << x << endl
    #define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl
    #define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl
    #define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl
    #define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl
    #define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl
    /* Fast Input Output */
    #define FAST_IO                  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
/* Constants */
    const ll MOD = 1000000009LL;
    const ll MAX = 100010LL;
/* Templates */
template<class T> T abs(T x) { re x > 0 ? x : -x; }
template<typename T> T gcd(T a, T b){ if(b == 0) return a; return gcd(b, a % b); }
template<typename T> T power(T x, T y, ll m = MOD){T ans = 1; x %= m; while(y > 0){ if(y & 1LL) ans = (ans * x)%m; y >>= 1LL; x = (x*x)%m; } return ans%m; }

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/Users/sahilbansal/Desktop/input.txt","r",stdin);
    freopen("/Users/sahilbansal/Desktop/output.txt","w",stdout);
    freopen("/Users/sahilbansal/Desktop/error.txt","w",stderr);
    #endif

    FAST_IO;
    
    int n, l, r, ql, qr;
    cin >> n >> l >> r >> ql >> qr;

    int a[MAX];
    rep (i, n) {
        cin >> a[i];
    }
    
    /*/
    
    PICKING BEST AT THE CURRENT STEP STRATEGY DOESN'T WORK

    int i = 0, j = n - 1;
    bool left = false;
    ll energy = min (a[i] * l, a[j] * r), left_arm = 0, right_arm = 0;

    if (a[i] * l < a[j] * r) {
        i ++;
        left = true;
    }
    else {
        j --;
    }

    while (i <= j) {
        if (left) {
            left_arm = a[i] * l + ql;
            right_arm = a[j] * r;
        }    
        else {
            left_arm = a[i] * l;
            right_arm = a[j] * r + qr;
        }

        if (left_arm > right_arm) {
            energy += right_arm;
            left = false;
            j --;
        }
        else {
            energy += left_arm;
            left = true;
            i ++;
        }
    }

    cout << energy << endl;
    //*/

    int sum_left[MAX], sum_right[MAX];
   
    sum_left[0] = 0;
    sum_right[0] = 0;

    rep1 (i, n + 1) {
        sum_left[i] = sum_left[i - 1] + a[i - 1];
    }

    rep1 (i, n + 1) {
        sum_right[i] = sum_right[i - 1] + a[n - i];
    }

    ll min_energy = LLINF;

    rep (i, n + 1) {
        // i = the no. of items picked by left operations 
        // n - i = no. of items picked by right operations
        ll current_energy = sum_left[i]*l + sum_right[n - i]*r;

        // handle the case when consecutive operations will be same
        if (i > n - i) {
            // pick in the order : LRLRLRLRLR....LLL
            current_energy += (2*i - n - 1) * ql;
        }
        if (i < n - i) {
            // pick in the order : RLRLRLRLRL....RRR
            current_energy += (n - 2*i - 1) * qr;
        }
        min_energy = min (min_energy, current_energy);
    }

    cout << min_energy << endl;
    return 0;
}