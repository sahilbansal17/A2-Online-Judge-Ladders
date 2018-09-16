#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;
double angle[MAX];

int main () {
    int n;
    cin >> n;

    double x, y;
    for (int i = 1; i <= n; i ++) {
        cin >> x >> y;
        angle[i] = atan2l(y, x) * (180 / acosl(-1));
    }
    double ans = 500;
    sort (angle + 1, angle + n + 1);

    for (int i = 1; i <= n; i ++) {
        ans = min (ans, 360 - (angle[i + 1] - angle[i]));
    }

    ans = min (ans, angle[n] - angle[1]);
    cout << fixed << setprecision(7) << ans << endl;

    return 0;
}