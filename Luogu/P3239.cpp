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
	
	int tc, n, r;
	cin >> tc;
	pair<double, ll> arr[225];

	double dp[133];
	double power[255][133];

	double p[255];
	while(tc--){
		cin >> n >> r;
		
		memset(dp, 0, sizeof(dp));
		memset(p, 0, sizeof(dp));

		for(int i = 1; i <= n; ++i)
			cin >> arr[i].first >> arr[i].second;

		for(int i = 1; i <= n; ++i){
			power[i][0] = 1;
			for(int j = 1; j <= r; ++j)
				power[i][j] = power[i][j - 1] * (1 - arr[i].first);
		}

			
		dp[0] = power[1][r], p[1] = dp[1] = 1 - dp[0];

		for(int i = 2; i <= n; ++i){
			
			for(int j = r; j >= 1; --j)
				p[i] += dp[j] * (1 - power[i][r - j]), dp[j] = dp[j - 1] * (1 - power[i][r - j + 1]) + dp[j] * power[i][r - j];
			p[i] += dp[0] * (1 - power[i][r]);
			dp[0] = dp[0] * power[i][r];
		}


		double res = 0;

		for(int i = 1; i <= n; ++i)
			res += p[i] * arr[i].second;
		cout << fixed << setprecision(10) << res << '\n';
		

	}
	


}

