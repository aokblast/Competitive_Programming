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

	int n, m, v, e;
	cin >> n >> m >> v >> e;

	int dis[v + 1][v + 1];

	int c[n], d[n];
   	double k[n];

	memset(dis, 0x3f, sizeof(dis));



	for(int i = 0; i < n; ++i)
		cin >> c[i];

	for(int i = 0; i < n; ++i)
		cin >> d[i];

	for(int i = 0; i < n; ++i)
		cin >> k[i];
	
	int a, b, w;

	while(e--){
		cin >> a >> b >> w;
		dis[a][b] = dis[b][a] = min(dis[b][a], w);
	}

	for(int i = 1; i <= v; ++i)
		dis[i][i] = 0;

	for(int k = 1; k <= v; ++k)
		for(int i = 1; i <= v; ++i)
			for(int j = 1; j <= v; ++j)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);

	double dp[m + 1][2];

	for(int i = 0; i <= m; ++i)
		dp[i][0] = dp[i][1] = 1e9;

	dp[0][0] = dp[1][1] = 0;

	for(int i = 1; i < n; ++i){
		for(int j = m; j >= 1; --j){
			dp[j][0] = min(dp[j][0] + dis[c[i]][c[i - 1]], dp[j][1] + dis[d[i - 1]][c[i]] * k[i - 1] + dis[c[i - 1]][c[i]] * (1 - k[i - 1]));
			dp[j][1] = min(dp[j - 1][0] + dis[c[i - 1]][d[i]] * k[i] + dis[c[i - 1]][c[i]] * (1 - k[i]), 
						   dp[j - 1][1] + dis[c[i - 1]][c[i]] * (1 - k[i - 1]) * (1 - k[i]) + dis[c[i - 1]][d[i]] * (1 - k[i - 1]) * k[i]
						   + dis[d[i - 1]][c[i]] * (k[i - 1]) * (1 - k[i]) + dis[d[i - 1]][d[i]] * k[i - 1] * k[i]);
		}
		dp[0][0] += dis[c[i]][c[i - 1]];
	}

	double mn = INT_MAX;


	for(int i = 0; i <= m; ++i)
		mn = min({mn, dp[i][0], dp[i][1]});

	cout << fixed << setprecision(2) << mn << '\n';
	
}

