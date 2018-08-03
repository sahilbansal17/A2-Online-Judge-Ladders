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

vi adj_list[100010];
vi adj_list_transpose[100010];
vi scc[100010]; // strongly connected components

stack <int> top_sort; // topological sort of the graph
bool visited[100010];

void dfs_first_pass(int source){
    visited[source] = true;
    rep(i, sz(adj_list[source])){
        int next = adj_list[source][i];
        if(!visited[next]){
            dfs_first_pass(next);
        }
    }
    top_sort.push(source);
}

void dfs_second_pass(int source, int component_no){
    visited[source] = true;
    scc[component_no].pb(source);
    rep(i, sz(adj_list_transpose[source])){
        int next = adj_list_transpose[source][i];
        if(!visited[next]){
            dfs_second_pass(next, component_no);
        }
    }
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/Users/sahilbansal/Desktop/input.txt","r",stdin);
    freopen("/Users/sahilbansal/Desktop/output.txt","w",stdout);
    #endif

    int nodes;
    cin >> nodes;

    vi cost(nodes, 0);
    rep(i, nodes){
        cin >> cost[i];
    }    

    int edges, x, y;
    cin >> edges;

    rep(i, edges){
        cin >> x >> y;
        x --; // zero-based indexing
        y --;
        adj_list[x].pb(y); // one way road
        adj_list_transpose[y].pb(x); // transpose of the given graph 
    }

    // the min cost required can be found by
    // chosing the minimum cost for a node in each strongly connected component

    // the no of ways can be similarly found by
    // multiplying the no of ways to chose a node from each SCC

    /* FINDING THE SCCs */

    // first pass dfs, to create the topological sort stack
    rep(i, nodes){
        if(!visited[i]){
            dfs_first_pass(i);
        }
    }

    // re-initialize the visited array
    fill(visited, false);

    // fill the SCC vector using the second pass of DFS
    // the nodes being visited in the order of decreasing finish times
    // as popped from the top_sort stack

    int component_no = 1;
    rep(i, nodes){
        int next_node = top_sort.top();
        if(!visited[next_node]){
            dfs_second_pass(next_node, component_no);
            component_no ++;
        }
        top_sort.pop();
    }

    /* CALCULATING THE REQUIRED ANSWERS */
    ll min_cost = 0, no_of_ways = 1;

    int components = component_no - 1;
    rep1(i, components + 1){
        int current_min = oo, current_ways = 0;
        // loop through the current SCC
        rep(j, scc[i].size()){
            int node = scc[i][j];
            if(cost[node] < current_min){
                current_min = cost[node];
                current_ways = 1;
            }
            else if(cost[node] == current_min){
                current_ways ++;
            }
        }
        // update the answers
        min_cost += current_min;
        no_of_ways *= current_ways;
        no_of_ways %= MOD;
    }

    cout << min_cost << " " << no_of_ways;
    return 0;
}