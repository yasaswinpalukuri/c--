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
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<int>> g(n);
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            g[b].emplace_back(a);
        }
        vector<int> safe(n, 1);
        for (int i = 0; i < n; i++) {
            queue<int> que;
            set<int> st;
            que.emplace(i);
            st.emplace(i);
            while (!que.empty() && st.size() < 22) {
                int v = que.front();
                que.pop();
                for (int j : g[v]) {
                    if (st.size() > 22) {
                        break;
                    }
                    if (st.count(j)) {
                        continue;
                    }
                    st.emplace(j);
                    que.emplace(j);
                }
            }
            if ((int) st.size() <= k) {
                for (int j : st) {
                    safe[j] = 0;
                }
            }
        }
        int ans = accumulate(safe.begin(), safe.end(), 0);
        cout << ans << '\n';
    }
    return 0;
}