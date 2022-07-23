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

const int MAXN = 3e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	int n, m, a, b;

	cin >>  n >> m;

	vector<int> ch[n + 1];

	for(int i = 1; i < n; ++i)
		cin >> a >> b, ch[a].push_back(b), ch[b].push_back(a);

	int pa[n + 1][32], dep[n + 1];
	memset(pa, 0, sizeof(pa));
	
	function<void(int, int)> dfs = [&](int u, int p){
		pa[u][0] = p, dep[u] = dep[p] + 1;
		for(int i = 1; i < 32; ++i)
			pa[u][i] = pa[pa[u][i - 1]][i - 1];

		for(const int v : ch[u]){
			if(v == p)
				continue;
			dfs(v, u);
		}
	};


	auto lca = [&](int a, int b){
		if(dep[a] > dep[b])
			swap(a, b);
		int diff = dep[b] - dep[a];
		int i = 0;
		for(; diff; ++i, diff >>= 1)
			if(diff & 1)
				b = pa[b][i];

		if(a == b)
			return a;

		for(i = 31; i >= 0; --i)
			if(pa[a][i] != pa[b][i])
				a = pa[a][i], b = pa[b][i];

		return pa[a][0];
	};

	dfs(1, 0);
	int x, y, z;
	while(m--){
		cin >> x >> y >> z;
		int c1 = lca(x, y);
		int s = lca(c1, z);
		int jihe = c1;
		c1 = lca(y, z);
		if(dep[c1] > dep[jihe])
			jihe = c1;
		c1 = lca(x, z);
		if(dep[c1] > dep[jihe])
			jihe = c1;

		cout << jihe << ' ' << (dep[z] + dep[x] + dep[y] - (dep[s] * 2) - dep[jihe]) << '\n';	
	}



	
}
