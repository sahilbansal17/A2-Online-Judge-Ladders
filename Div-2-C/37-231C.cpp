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
/* Constants */
    const ll MOD = 1000000007LL;
    const ll MAX = 10010LL;
/* Templates */
template<class T> T abs(T x) { re x > 0 ? x : -x; }
template<typename T> T gcd(T a, T b){ if(b == 0) return a; return gcd(b, a % b); }
template<typename T> T power(T x, T y, ll m = MOD){T ans = 1; while(y > 0){ if(y & 1LL) ans = (ans * x)%m; y >>= 1LL; x = (x*x)%m; } return ans%m; }

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/Users/sahilbansal/Desktop/input.txt","r",stdin);
    freopen("/Users/sahilbansal/Desktop/output.txt","w",stdout);
    #endif

    int n, k;
    cin >> n >> k;

    vll a(n, 0), prefix_sum(n + 1, 0);
    rep (i, n) {
        cin >> a[i];
    }

    // sort in non-decreasing order
    srt(a);

    rep1 (i, n + 1) {
        prefix_sum[i] = prefix_sum[i - 1] + a[i - 1];
    }

    // we check how many maximum a[i] we can get by incrementing 
    // smaller numbers than a[i] till possible
    // and then find the one which is smallest a[i] and 
    // can have maximum possible occurrences

    // use binary search approach
    // the no of operations to make "cnt" occurrences of a[i]
    // = (a[i] * cnt) - sum (a[j]) [ j=(i - cnt + 1) to (i) ]
    // this is the difference which if smaller than k, then
    // it is possible to have "cnt" occurrences of a[i]

    // by pre-computing prefix sums
    // we can directly find the sum in the above equation
    // sum (a[j]) where j = (i - cnt + 1) to (i)
    // as = (prefix_sum[i + 1] - prefix_sum[i - cnt + 1])

    int max_occ = 0, min_ele = a[0];
    rep (i, n) {
        int low = 1, high = i + 2; // since maximum occurrences can't be more than the no. of elements before it
        while (low + 1 < high) {
            int mid = (low + high)/2;
            ll sum_left = a[i] * mid;
            ll sum_right = prefix_sum[i + 1] - prefix_sum[i - mid + 1];
            if ((sum_left - sum_right) > k) {
                // need smaller value for mid aka 'cnt'
                high = mid;
            }
            else if ((sum_left - sum_right) <= k) {
                // higher value for mid can work
                low = mid;
            }
        }
        if (low > max_occ) {
            max_occ = low;
            min_ele = a[i];
        }
    }

    cout << max_occ << " " << min_ele << endl;
    return 0;
}