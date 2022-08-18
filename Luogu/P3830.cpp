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

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	int q, n;
	cin >> q >> n;
	
	if(q == 1){
		//dp[i] = (dp[i - 1] * (i - 1) + dp[i - 1] + 2) / i

		double dp = 0;
		for(int i = 2; i <= n; ++i)
			dp += 2.0 / i;
		cout << fixed << setprecision(6) << dp << '\n';
	}else{
		double dp[n + 5][n + 5];
		memset(dp, 0, sizeof(dp));
		for(int i = 2; i <= n; ++i){
			dp[i][0] = 1;
			for(int j = 1; j < i; ++j){
				for(int k = 1; k < i; ++k){
					dp[i][j] += dp[k][j - 1] + dp[i - k][j - 1] - dp[k][j - 1] * dp[i - k][j - 1];
				}
				dp[i][j] /= (i - 1);
			}
		}

		double res = 0;
		for(int i = 0; i < n; ++i)
			res += dp[n][i];

		cout << fixed << setprecision(6) << res << '\n';
			


		

	}
}

