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
    const ll MOD = 100000000LL;
    const ll MAX = 10010LL;
/* Templates */
template<class T> T abs(T x) { re x > 0 ? x : -x; }
template<typename T> T gcd(T a, T b){ if(b == 0) return a; return gcd(b, a % b); }
template<typename T> T power(T x, T y, ll m = MOD){T ans = 1; while(y > 0){ if(y & 1LL) ans = (ans * x)%m; y >>= 1LL; x = (x*x)%m; } return ans%m; }

void getDivisors(string s, vs & v){

    int n = slen(s);

    string temp;

    rep(i, n / 2){
        temp += s[i];
        if(n % (i + 1) == 0){
            bool flag = 1;

            for(int j = i + 1; j < n; j += i + 1){
                int l = 0;
                for(int k = j; k < j + i + 1; k ++){
                    if(s[k] != temp[l]){
                        flag = 0;
                        break;
                    }
                    else{
                        l ++;
                    }
                }
            }

            if(flag == 1){
                v.pb(temp);
            }
        }
    }
    // string itself is its divisor
    v.pb(s);
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/Users/sahilbansal/Desktop/input.txt","r",stdin);
    freopen("/Users/sahilbansal/Desktop/output.txt","w",stdout);
    #endif

    string s1, s2;
    cin >> s1 >> s2;

    vs divisors_s1, divisors_s2;
    getDivisors(s1, divisors_s1);
    getDivisors(s2, divisors_s2);    

    int n1 = sz(divisors_s1);
    int n2 = sz(divisors_s2);

    /*/
    rep(i, n1){
        cout << divisors_s1[i] << " ";
    }
    cout << endl;
    rep(i, n2){
        cout << divisors_s2[i] << " ";
    }
    //*/
 
    // find the intersection of the two vectors 
    int common_divisors = 0;

    int i = 0, j = 0;
    while(i < n1 && j < n2){
        if(divisors_s1[i] < divisors_s2[j]){
            i ++;
        }
        else if(divisors_s1[i] > divisors_s2[j]){
            j ++;
        }
        else{
            i ++, j ++;
            common_divisors ++;
        }
    }

    cout << common_divisors;
    
    return 0;
}