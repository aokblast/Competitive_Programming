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



void solve() {
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int n, e, t;
	int res = 0;
	bool adjs[MAXN][MAXN];
	int from, to;
	int tc = 0;
	bool visit[MAXN] = {false};
	int du[MAXN];

	function<void(int)> dfs = [&](int u){
		for(int v = 1; v <= n; ++v){
			if(adjs[u][v]){
				adjs[v][u] = adjs[u][v] = 0;
				++du[u], ++du[v];
				dfs(v);
				++res;
				
			}
		}
	};
	while(cin >> n >> e >> t && (n || e || t)){
		memset(adjs, 0, sizeof(adjs));
		
		while(e--)
			cin >> from >> to, adjs[from][to] = adjs[to][from] = true;
		
		res = 0;
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= n; ++j){
				if(adjs[i][j]){
					memset(du, 0, sizeof(du));
					dfs(i);		
					int cnt = 0;
					for(int i = 1; i <= n; ++i)
						cnt += du[i] % 2;
					if(cnt >= 2)
						cnt -= 2;
					res += cnt >> 1;
					++res;

				}

				
			}
		}
		if(res)
			--res;
		cout << "Case " << ++tc << ": " << res * t << '\n';

	}
}
