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

const int MAXN = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-7;

const double d = (sqrt(5) + 1) / 2.0;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	long w, n, k;

	cin >> w >> n >> k;

	long x, y;

	function<ll(ll, ll)> exgcd = [&](ll a, ll b){
		if(!b)
			return x = 1, y = 0, a;
		ll d = exgcd(b, a % b);
		ll t = x;
		x = y;
		y = t  - (a / b) * y;
		return d;
	};

	auto qpow = [](ll a, ll b, ll MOD){
		ll res = 1;
		while(b){
			if(b & 1)
				res = (res * a) % MOD;
			a = a * a % MOD;
			b >>= 1;
		}
		return res;
	};

	exgcd(qpow(2, k, MOD), MOD);
	
	cout << (((w % MOD) * (((x % MOD) + MOD) % MOD)) % MOD) << '\n';

}

