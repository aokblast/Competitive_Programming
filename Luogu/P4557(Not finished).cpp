#include <bits/stdc++.h>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif


#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAXN = 3e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPointS = 1e-9;

struct Point{
	int x, y;
	long operator^(const Point &p) const {
		return (long)x * p.y - (long)y * p.x;
	}
	bool operator<(const Point &p) const {
		return x == p.x ? y < p.y : x < p.x;
	}
	const Point operator-(const Point &p) const {
		return {x - p.x, y - p.y};
	}

	const Point operator+(const Point &p) const {
		return {x + p.x, y + p.y}; 
	}

	Point() = default;
};

bool cmp(const Point &p1, const Point &p2){
	return (p1 ^ p2) > 0 || (p1 ^ p2) == 0 && ((long)p1.x * p1.x + (long)p1.y * p1.y) < ((long)p2.x * p2.x + (long)p2.y * p2.y);
}


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	
	int n, m, q;

	cin >> n >> m >> q;

	Point s1[n], s2[m], tmp[max(m, n)], v1[n], v2[m], cur[n + m];
	
	for(int i = 0; i < n; ++i)
		cin >> s1[i].x >> s1[i].y;

	for(int i = 0; i < m; ++i)
		cin >> s2[i].x >> s2[i].y, s2[i].x = -s2[i].x, s2[i].y = -s2[i].y;

	auto andrew = [&](Point *s, int n){
		sort(s, s + n);
		int idx = 0;
		for(int i = 0; i < n; ++i){
			while(idx >= 2 && ((tmp[idx - 1] - tmp[idx - 2]) ^ (s[i] - tmp[idx - 1])) <= 0)
				--idx;
			tmp[idx++] = s[i];
		}

		int lim = idx;

		for(int i = n - 2; i >= 0; --i){
			while(idx > lim && ((tmp[idx - 1] - tmp[idx - 2]) ^ (s[i] - tmp[idx - 1])) <= 0)
				--idx;
			tmp[idx++] = s[i];
		}

		for(int i = 0; i < idx; ++i)
			s[i] = tmp[i];
		return idx;
	};

	n = andrew(s1, n);
	m = andrew(s2, m);

	for(int i = 0; i < n - 1; ++i)
		v1[i] = s1[i + 1] - s1[i];

	v1[n - 1] = s1[0] - s1[n - 1];

	for(int i = 0; i < m - 1; ++i)
		v2[i] = s2[i + 1] - s2[i];

	v2[m - 1] = v2[0] - v2[m - 1];

	int a = 0, b = 0;
	int tot = 0;
	cur[tot++] = s1[0] + s2[0];
	while(a < n && b < m)
		cur[tot] = cur[tot - 1] + ((v1[a] ^ v2[b]) < 0 ? v2[b++] : v1[a++]), ++tot;

	while(a < n)
		cur[tot] = cur[tot - 1] + v1[a++], ++tot;

	while(b < m)
		cur[tot] = cur[tot - 1] + v2[b++], ++tot;

	tot = andrew(cur, tot);


	dbg(n, m, tot);

	auto base = cur[0];

	for(int i = 0; i < tot; ++i)
		cur[i] = cur[i] - base;
	Point qu;

	auto in = [&](const Point &p){
		if((p ^ cur[1]) > 0 || (cur[tot - 1] ^ p) > 0 || ((p ^ cur[1]) == 0 && (long)p.x * p.x + (long)p.y * p.y > (long)cur[1].x * cur[1].x + (long)cur[1].y * cur[1].y))
			return true;
		int idx = lower_bound(cur + 1, cur + tot, p, cmp) - cur;
		return ((p - cur[idx]) ^ (cur[idx + 1] - cur[idx])) > 0;
	};
	while(q--){
		cin >> qu.x >> qu.y;
		cout << in(qu - base) << '\n';
	}




}
