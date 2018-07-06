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

bool abs_value_cmp(pii p1, pii p2){
    int x1 = p1.F;
    int x2 = p2.F;
    int y1 = p1.S;
    int y2 = p2.S;
    re(abs(x1) + abs(y1) <= abs(x2) + abs(y2));
}
int main(){

    #ifndef ONLINE_JUDGE
    freopen("/Users/sahilbansal/Desktop/input.txt","r",stdin);
    freopen("/Users/sahilbansal/Desktop/output.txt","w",stdout);
    #endif

    int n, x, y;

    cin >> n;

    vpii pts;
    rep(i, n){
        cin >> x >> y;
        pts.pb(mp(x, y));
    }
    // sort based on x-coordinates
    sort(pts.begin(), pts.end(), abs_value_cmp);

    /*/
    rep(i, n){
        cout << pts[i].F << " " << pts[i].S << "\n";
    }
    //*/

    vs robo_actions;
    int steps = 0;
    rep(i, n){
        int c_pt_x = pts[i].F;
        int c_pt_y = pts[i].S;
        bool moved_left = false, moved_up = false;
        bool x_moved = true, y_moved = true;
        // reach the point
        // x-coordinate
        if(c_pt_x < 0){
            robo_actions.pb("1 " + to_string(abs(c_pt_x)) + " L\n"); 
            moved_left = true;
            steps ++;
        }
        else if(c_pt_x > 0){
            robo_actions.pb("1 " + to_string(abs(c_pt_x)) + " R\n"); 
            steps ++;    
        }
        else{
            x_moved = false;
        }
        // y-coordinate
        if(c_pt_y < 0){
            robo_actions.pb("1 " + to_string(abs(c_pt_y)) + " D\n");
            steps ++;
        }
        else if(c_pt_y > 0){
            robo_actions.pb("1 " + to_string(abs(c_pt_y)) + " U\n");
            moved_up = true;
            steps ++;
        }
        else{
            y_moved = false;
        }
        // pick up the bomb
        robo_actions.push_back("2\n");
        // move back to (0, 0)
        // y-coordinate
        if(moved_up && y_moved){
            robo_actions.pb("1 " + to_string(abs(c_pt_y)) + " D\n");
            steps ++;
        }
        else if(y_moved){
            robo_actions.pb("1 " + to_string(abs(c_pt_y)) + " U\n");
            steps ++;
        }
        // x-coordinate
        if(x_moved && moved_left){
            robo_actions.pb("1 " + to_string(abs(c_pt_x)) + " R\n"); 
            steps ++;
        }
        else if(x_moved){
            robo_actions.pb("1 " + to_string(abs(c_pt_x)) + " L\n"); 
            steps ++;
        }   
        // destroy the bomb
        robo_actions.push_back("3\n");
        // for both picking up and discarding
        steps += 2;
    }

    cout << steps << "\n";
    //*/
    rep(i, robo_actions.size()){
        cout << robo_actions[i];
    }
    //*/
    re 0;
}