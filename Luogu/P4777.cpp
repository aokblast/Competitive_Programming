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

using lll = __int128;

const int MAXN = 1e7 + 5;
const ll MOD = 19260817;
const ll INF = 1e9;
const ld EPS = 1e-7;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int k;
	cin >> k;

	ll a[k], r[k];

	ll x, y;
	
	for(int i = 0; i < k; ++i)
		cin >> r[i] >> a[i];

	function<ll(ll, ll)> exgcd = [&](ll a, ll b){
		if(!b)
			return x = 1, y = 0, a;
		ll d = exgcd(b, a % b);
		ll t = x;
		x = y;
		y = t - (a / b) * y;
		return d;
	};
		
  	ll	M = r[0],  ans = a[0];

	for(int i = 1; i < k; ++i){
		ll da = (((a[i] - ans) % r[i]) + r[i]) % r[i];
		ll g = exgcd(M, r[i]);
		auto tmp = (lll)M * x * (da / g);
		M = M * (r[i] / g);
		ans = (((ans + tmp) % M) + M) % M;
	}

	cout << ans << '\n';

}

