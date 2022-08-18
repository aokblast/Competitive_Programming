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

	int c[4], n, d[4], s;

	cin >> c[0] >> c[1] >> c[2] >> c[3] >> n;


	int dp[MAXN];

	while(n--){
		cin >> d[0] >> d[1] >> d[2] >> d[3] >> s;
		
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for(int i = 0; i < 4; ++i)
			for(int j = c[i]; j <= s; ++j)
				dp[j] += dp[j - c[i]];

		int res = dp[s];

		for(int i = 1; i < 	(1 << 4); ++i){
			int neg = 1;
			int cur = s;
			for(int j = 0; j < 4; ++j) {
				if(i & (1 << j)){
					neg *= -1;
					cur -= c[j] * (d[j] + 1);
				}
			}
			if(cur >= 0)
				res += neg * dp[cur];

		}

		cout << res << '\n';
	}



		
}
