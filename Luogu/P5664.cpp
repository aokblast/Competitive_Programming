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

	int n, m;

	cin >> n >> m;
	int a[n + 1][m + 1];

 	ll sum[n + 1];

	ll f = 1;

	memset(sum, 0, sizeof(sum));

	for(int i = 1; i <= n; ++i){
		sum[i] = 0;
		for(int j = 1; j <= m; ++j)
			cin >> a[i][j], sum[i] = (sum[i] + a[i][j]) % MOD;
		f = f * (sum[i] + 1) % MOD;
	}
	--f;

	ll dp[n + 1][2 * n + 1];

	//
	// first j takes k to t 

	for(int t = 1; t <= m; ++t){
		memset(dp, 0, sizeof(dp));
		dp[0][n] = 1;

		for(int j = 1; j <= n; ++j){
			for(int k = -n; k <= n; ++k){
				dp[j][k + n] = (dp[j - 1][k + n] + (k - 1 + n >= 0 ? dp[j - 1][k - 1 + n] : 0) * (a[j][t]) % MOD + (k + 1 + n <= 2 * n ? dp[j - 1][k + 1 + n] : 0) * (sum[j] - a[j][t]) % MOD) % MOD;
			}
		}

		for(int i = 1; i <= n; ++i)
			f = (f - dp[n][i + n]) % MOD;

		f %= MOD;

		
	}

	cout << ((f % MOD + MOD) % MOD) << '\n';



		
}
