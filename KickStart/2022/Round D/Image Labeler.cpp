#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    for (int qq = 1; qq <= tt; qq++) {
        cout << "Case #" << qq << ": ";
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        double ans = 0;
        for (int i = 0; i < m - 1; i++) {
            ans += a[n - 1 - i];
        }
        ans += (a[(n - m + 1) / 2] + a[(n - m) / 2]) / 2.0;
        cout << fixed << setprecision(12);
        cout << ans << '\n';
    }
    return 0;
}