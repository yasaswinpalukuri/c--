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



void test_case() {
	int n, x, y;
	scanf("%d%d%d", &n, &x, &y);
	int sum = n * (n + 1) / 2;
	if(sum % (x + y) == 0) {
		int times = sum / (x + y);
		x *= times;
		y *= times;
		assert(x + y == sum);
		vector<int> a, b;
		for(int i = n; i >= 1; --i) {
			if(x >= i) {
				x -= i;
				a.push_back(i);
			}
			else {
				y -= i;
				b.push_back(i);
			}
		}
		puts("POSSIBLE");
		printf("%d\n", (int) a.size());
		for(int i = 0; i < (int) a.size(); ++i) {
			printf("%d", a[i]);
			if(i != (int) a.size() - 1) {
				printf(" ");
			}
		}
		puts("");
		return;
	}
	puts("IMPOSSIBLE");
}

int main() {
	int T;
	scanf("%d", &T);
	for(int nr = 1; nr <= T; ++nr) {
		printf("Case #%d: ", nr);
		test_case();
	}
}
