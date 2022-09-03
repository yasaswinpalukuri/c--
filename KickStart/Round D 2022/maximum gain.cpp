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
        int k;
        cin >> k;
        auto Do = [&](vector<int> c) {
            int sz = (int) c.size();
            vector<long long> res(sz + 1);
            long long s = 0;
            for (int i = 0; i < sz; i++) {
                long long t = s;
                res[i] = max(res[i], s);
                for (int j = sz - 1; j >= i; j--) {
                    t += c[j];
                    res[i + sz - j] = max(res[i + sz - j], t);
                }
                s += c[i];
            }
            return res;
        };
        auto x = Do(a);
        auto y = Do(b);
        long long ans = 0;
        for (int i = 0; i <= k; i++) {
            ans = max(ans, x[min(n, i)] + y[min(m, k - i)]);
        }
        cout << ans << '\n';
    }
    return 0;
}