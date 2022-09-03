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

struct Ant {
	int x, dir, id;
	bool operator <(const Ant& he) const {
		return x < he.x;
	}
};

void test_case() {
	int n, len;
	scanf("%d%d", &n, &len);
	vector<pair<int,int>> events;
	vector<int> x(n), dir(n);
	vector<Ant> ants;
	for(int i = 0; i < n; ++i) {
		scanf("%d%d", &x[i], &dir[i]);
		ants.push_back(Ant{x[i], dir[i], i});
		if(dir[i] == 0) {
			events.emplace_back(x[i], 0);
		}
		else {
			events.emplace_back(len - x[i], 1);
		}
	}
	sort(events.begin(), events.end());
	sort(ants.begin(), ants.end());
	int L = 0, R = n - 1;
	vector<pair<int,int>> order;
	for(pair<int,int> event : events) {
		int who = -1;
		if(event.second == 0) {
			who = ants[L++].id;
		}
		else {
			who = ants[R--].id;
		}
		order.emplace_back(event.first, who);
	}
	sort(order.begin(), order.end());
	for(pair<int,int> p : order){ 
		printf(" %d", p.second + 1);
	}
	puts("");
}

int main() {
	int T;
	scanf("%d", &T);
	for(int nr = 1; nr <= T; ++nr) {
		printf("Case #%d: ", nr);
		test_case();
	}
}
