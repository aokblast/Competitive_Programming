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

const int MAXN = 1e3 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

pair<int, int> st[MAXN];


void solve() {
	int n, p;
	cin >> n >> p;
	ll a = 0, b = 0, res = 0;
	int tmp;
	for(int i = 0; i < n;++i){
		int mx = INT_MIN, mn = INT_MAX;
		for(int j = 0; j < p; ++j){
			cin >> tmp;
			mx = max(mx, tmp);
			mn = min(mn, tmp);
		}
		st[i] = make_pair(mn, mx);
		res += mx - mn;
	}
	ll pa, pb;
	res += st[0].first;
	pa = pb = st[0].second;
	for(int i = 1; i < n; ++i){
		ll t1 = a, t2 = b;
		a = min(t1 + abs(st[i].second - pa), t2 + abs(st[i].second - pb));
		b = min(t1 + abs(st[i].first - pa), t2 + abs(st[i].first - pb));
		pa = st[i].first, pb = st[i].second;
		
	}
	cout << (res + min(a, b)) << '\n';

	
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
}

