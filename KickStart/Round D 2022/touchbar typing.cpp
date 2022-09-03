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
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int m;
        cin >> m;
        vector<int> b(m);
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }
        vector<int> dp(m);
        const int inf = (int) 1e9;
        for (int x : a) {
            for (int i = 1; i < m; i++) {
                dp[i] = min(dp[i], dp[i - 1] + 1);
            }
            for (int i = m - 2; i >= 0; i--) {
                dp[i] = min(dp[i], dp[i + 1] + 1);
            }
            for (int i = 0; i < m; i++) {
                if (b[i] != x) {
                    dp[i] = inf;
                }
            }
        }
        cout << *min_element(dp.begin(), dp.end()) << '\n';
    }
    return 0;
}