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

#define eps 10e-9

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/Users/sahilbansal/Desktop/input.txt","r",stdin);
    freopen("/Users/sahilbansal/Desktop/output.txt","w",stdout);
    #endif

    int n, k, d;

    cin >> n >> k >> d;

    // consider the sequence of buses taken by any student 
    // on each day out of 'd', he can choose any of the 'k' buses
    // so total 'k^d' possible sequences

    // now, if total students, n > k^d, atleast one sequence 
    // has to be the same, by pigeonhole principle, 
    // so the answer is -1 in this case.

    // in the other case, n <= k^d
    // we can assign the buses to each of the students for d days
    // by using the first n numbers containing 'd-digits'
    // and in the 'base-k' representation

    // this ensures that all the sequences are distinct

    bool poss = false;
    int k_power_d = 1;
    rep(i, d){
        k_power_d *= k;
        if(k_power_d >= n){
            poss = 1;
            break;
        }
    }

    if(!poss){
        cout << "-1\n";
        re 0;
    }
    
    // n*d matrix initialized to all 1
    vvi student_x_day(n, vi(d, 1)); 

    rep1(i, n){
        student_x_day[i] = student_x_day[i - 1];
        rfl(j, d - 1, 0){
            if(student_x_day[i - 1][j] < k){
                student_x_day[i][j] = student_x_day[i - 1][j] + 1;
                break;
            }
            else{
                student_x_day[i][j] = 1;
                rfl(l, j - 1, 0){
                    if(student_x_day[i][l] == k){
                        student_x_day[i][l] = 1;
                    }
                    else{
                        student_x_day[i][l] ++;
                        break;
                    }
                }
                break;
            }
        }
    }

    rep(i, d){
        rep(j, n){
            cout << student_x_day[j][i] << " ";
        }
        cout << "\n";
    }
    re 0;
}