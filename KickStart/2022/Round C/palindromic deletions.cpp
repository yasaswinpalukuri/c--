#include <bits/stdc++.h>
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
	*this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
// debug & operator << (debug & dd, P p) { dd << "(" << p.x << ", " << p.y << ")"; return dd; }

const int mod = 1e9 + 7;

const int nax = 1005;
int C[nax][nax];

int my_pow(int a, int b) {
	int r = 1;
	while(b) {
		if(b % 2) {
			r = (long long) r * a % mod;
		}
		a = (long long) a * a % mod;
		b /= 2;
	}
	return r;
}
int my_inv(int a) {
	return my_pow(a, mod - 2);
}

void add_self(int& a, int b) {
	a += b;
	if(a >= mod) {
		a -= mod;
	}
}

void test_case() {
	int n;
	scanf("%d", &n);
	char s[605];
	scanf("%s", s);
	int answer = 1;
	for(int start : {1, 2}) {
		vector<vector<int>> dp(n, vector<int>(n));
		if(start == 1) {
			for(int i = 0; i < n; ++i) {
				dp[i][i] = 1;
			}
		}
		if(start == 2) {
			for(int i = 0; i < n; ++i) {
				for(int j = i + 1; j < n; ++j) {
					if(s[i] == s[j]) {
						dp[i][j] = 1;
					}
				}
			}
		}
		int len = start;
		for(int rep = 0; rep <= n / 2; ++rep) {
			// add to answer
			int total = 0;
			for(int i = 0; i < n; ++i) {
				for(int j = i; j < n; ++j) {
					add_self(total, dp[i][j]);
				}
			}
			if(total > 0 && len < n) {
				int tmp = (long long) total * my_inv(C[n][len]) % mod;
				debug() << imie(len) imie(total) imie(tmp);
				add_self(answer, tmp);
			}
			
			len += 2;
			vector<vector<int>> new_dp(n, vector<int>(n));
			for(int L = n - 1; L >= 0; --L) {
				for(int R = L; R < n; ++R) {
					if(L >= 1) add_self(dp[L-1][R], dp[L][R]);
				}
			}
			for(int L = n - 1; L >= 0; --L) {
				for(int R = L; R < n; ++R) {
					if(R != n - 1) add_self(dp[L][R+1], dp[L][R]);
				}
			}
			for(int L = n - 1; L >= 0; --L) {
				for(int R = L; R < n; ++R) {
					if(L != 0 && R != n - 1 && s[L-1] == s[R+1]) {
						add_self(new_dp[L-1][R+1], dp[L][R]);
					}
				}
			}
			dp = new_dp;
		}
	}
	printf("%d\n", answer);
}

int main() {
	for(int i = 0; i < nax; ++i) {
		C[i][0] = C[i][i] = 1;
		for(int j = 1; j < i; ++j) {
			C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
		}
	}
	int T;
	scanf("%d", &T);
	for(int nr = 1; nr <= T; ++nr) {
		printf("Case #%d: ", nr);
		test_case();
	}
}
