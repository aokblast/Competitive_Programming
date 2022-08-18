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

double dp[101][1 << 15] = {{0}};

bool vis[101][1 << 15] = {{false}};

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	int k, n;
	cin >> k >> n;

	int p[n + 1], pre[n + 1];
	memset(pre, 0, sizeof(pre));


	for(int i = 1; i <= n; ++i){
		int x;
		cin >> p[i - 1] >> x;

		while(x){
			pre[i - 1] |= 1 << (x - 1);
			cin >> x;
		}

	}

	function<double(int, int)> dfs = [&](int step, int cur) -> double{
		if(step == k)
			return 0;
				
		if(vis[step][cur])
			return dp[step][cur];
		vis[step][cur] = true;
		for(int i = 0; i < n; ++i){
			if((pre[i] & cur) == pre[i]){
				dp[step][cur] += max({dfs(step + 1, cur), dfs(step + 1, cur | 1 << i) + p[i]}); 
			}else{
				dp[step][cur] += dfs(step + 1, cur);
			}
		}
		return (dp[step][cur] /= (double)n);
	};

	cout << fixed << setprecision(6) << dfs(0, 0) << '\n';






}

