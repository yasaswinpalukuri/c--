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
	static char tmp[100005];
	int n;
	scanf("%d", &n);
	scanf(" %s", tmp);
	string s(tmp);
	bool small = false;
	bool big = false;
	bool digit = false;
	bool special = false;
	for(char c : s){ 
		if(islower(c)) small = true;
		if(isupper(c)) big = true;
		if(isdigit(c)) digit = true;
		if(c == '#' || c == '@' || c == '*' || c == '&') {
			special = true;
		}
	}
	if(!small) s += 'a';
	if(!big) s += 'A';
	if(!special) s += '#';
	if(!digit) s += '0';
	while((int) s.length() < 7) s += 'a';
	printf("%s\n", s.c_str());
}

int main() {
	int T;
	scanf("%d", &T);
	for(int nr = 1; nr <= T; ++nr) {
		printf("Case #%d: ", nr);
		test_case();
	}
}
