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

int main() {
	int n;
	int circs[MAXN][3];
	
	bool vis[MAXN];

	double l, r;
	
	auto cross = [&](int u, int v){
		return (circs[u][0] - circs[v][0]) * (circs[u][0] - circs[v][0]) + (circs[u][1] - circs[v][1]) * (circs[u][1] - circs[v][1]) - (circs[u][2] + circs[v][2]) * (circs[u][2] + circs[v][2])  <= 0;
	};
	function<bool(int)> dfs = [&](int u){
		vis[u] = true;
		if(circs[u][1] - circs[u][2] <= 0)
			return true;
		if(circs[u][0] - circs[u][2] <= 0)
			l = min(l, circs[u][1] - sqrt(circs[u][2] * circs[u][2] - circs[u][0] * circs[u][0]));
		if(circs[u][0] + circs[u][2] >= 1000)
			r = min(r, circs[u][1] - sqrt(circs[u][2] * circs[u][2] - (1000 - circs[u][0]) * (1000 -circs[u][0])));
		for(int i = 0; i < n; ++i)
			if(!vis[i] && cross(u, i) && dfs(i))
				return true;
		return false;
	};

	while(cin >> n){
		bool res = true;
		memset(vis, 0, sizeof(vis));
		l = r = 1000.0;
		for(int i = 0; i < n; ++i)
			cin >> circs[i][0] >> circs[i][1] >> circs[i][2];	
		
		for(int i = 0; i < n; ++i)
			if(circs[i][2] + circs[i][1] >= 1000 && !vis[i] && dfs(i)){
				res = false;
				break;
			}
		if(res)
			cout << fixed <<   setprecision(2) << 0.0 << ' ' << l << ' ' << 1000.0 << ' ' << r;
		else
			cout << "IMPOSSIBLE";
		cout << '\n';
	}



}
