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

int dir_x[4] = {0, -1, 1, 0};
int dir_y[4] = {-1, 0, 0, 1};
bool visited[505][505];
int s = 0; // total free cells
int k; // extra walls needed
int count_visited = 0;
char maze[505][505];

void dfs(int x, int y, int n, int m){
    if(count_visited == s - k){
        /*/
        rep(i, n){
            rep(j, m){
                cout << visited[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
        //*/
        return;
    }
    visited[x][y] = true;
    count_visited ++;
    rep(k, 4){
        int new_x = x + dir_x[k];
        int new_y = y + dir_y[k];   
        if(new_x >= 0 && new_x < n && new_y >= 0 && new_y < m){
            // the k inside the loop is different from global k, it messed up the things
            if(maze[new_x][new_y] == '.' && !visited[new_x][new_y]){
                dfs(new_x, new_y, n, m);
            }
        }
    }
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/Users/sahilbansal/Desktop/input.txt","r",stdin);
    freopen("/Users/sahilbansal/Desktop/output.txt","w",stdout);
    #endif

    int n, m;
    cin >> n >> m >> k;

    int first_free_x = -1, first_free_y = -1;

    rep(i, n){
        rep(j, m){
            cin >> maze[i][j];
            if(maze[i][j] == '.'){
                s ++;
                if(first_free_x == -1){
                    first_free_x = i;
                }
                if(first_free_y == -1){
                    first_free_y = j;
                }
            }
        }
    }

    dfs(first_free_x, first_free_y, n, m);

    rep(i, n){
        rep(j, m){
            // cout << visited[i][j] << ' ';
            if(visited[i][j]){
                cout << ".";
            }
            else if(maze[i][j] == '.'){
                cout << "X";
            }
            else{
                cout << "#";
            }
        }
        cout << "\n";
    }
    re 0;
}