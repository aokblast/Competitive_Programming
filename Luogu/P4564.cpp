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
const ll MOD = 998244353;
const ll INF = 1e9;
const ld EPS = 1e-7;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	ll n, tc;
	cin >> n;
	ll b[n + 2];

	ll dp[n + 2][105];
	ll inv[n + 2];

	inv[1] = 1;

	for(int i = 2; i <= n; ++i)
		inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;

	memset(dp, 0, sizeof(dp));

	for(int i = 1; i <= n; ++i)
		cin >> b[i], dp[i][b[i]] = 1;
	cin >> tc;
	ll t, id, u, v;

	ll x, y;


	function<ll(ll, ll)> exgcd = [&](ll a, ll b){
		if(!b)
			return x = 1, y = 0, a;
		ll d = exgcd(b, a % b);
		ll t = x;
		x = y;
		y = t - (a / b) * y;
	   	return d;
	};

	ll k;

	ll p[n + 2], f[n + 2], g[n + 2], c, tot[n + 2];


	while(tc--){
		cin >> t;
		if(t == 0){
			cin >> id >> u >> v;
			ll p = (((exgcd(v, MOD), x) * u % MOD) + MOD) % MOD;
			ll q = (1 - p + MOD) % MOD; 

			dp[id][0] = (dp[id][0] + p * dp[id][1] % MOD) % MOD;

			for(int i = 1; i <= b[id]; ++i)
				dp[id][i] = (q * dp[id][i] % MOD + p * dp[id][i + 1] % MOD) % MOD;
		}else{
			cin >> k;

			for(int i = 1; i <= k; ++i)
				cin >> c, p[i] = 1 - dp[c][0], f[i] = 0, g[i] = 0;
			f[0] = 1;


			for(int i = 1; i <= k; ++i){
				for(int j = i; j >= 1; --j)
					f[j] = (f[j] * (1  - p[i]) % MOD + f[j - 1] * p[i] % MOD) % MOD;
				f[0] = f[0] * (1 - p[i]) % MOD;
			}

			for(int i = 1; i <= k; ++i){
				tot[i] = 0;

				if(p[i] == 1){
					for(int j = 0; j < k; ++j)
						tot[i] = ((f[j + 1] * inv[j + 1] % MOD) + tot[i]) % MOD;
				}else{

					ll iv = (exgcd(1 - p[i], MOD), x);
					g[0] = f[0] % MOD * iv % MOD;
					tot[i] = g[0] * inv[1] % MOD;
					for(int j = 1; j < k; ++j){
						g[j] = (f[j] - g[j - 1] * p[i]) % MOD * iv % MOD;
						tot[i] = (tot[i] + g[j] * inv[j + 1] % MOD) % MOD;
					}
				}
				tot[i] = ((tot[i] * p[i] % MOD) + MOD) % MOD;	

			}

			for(int i = 1; i <= k; ++i)
				cout << tot[i] << (i == k ? '\n' : ' ');
		}
	}

	for(int i = 1; i <= n; ++i){
		ll tot = 0;
		for(int j = 1; j <= b[i]; ++j)
			tot = (tot + j * dp[i][j] % MOD) % MOD;
		cout << tot << (i == n ? '\n' : ' ');
	}


}

