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



int last = 0;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	
	int n, m, q, a, b, t;
	cin >> n >> m >> q;
	vector<int> adjs[n + 1];
	int djs[n + 1];
	int sz[n + 1];
	int d[n + 1];
	memset(d, 0, sizeof(d));


	function<void(int, int)> dfs = [&](int u, int p){
		queue<pair<int, int>> q;
		q.push({u, p});
		while(!q.empty()){
			auto [u, p] = q.front(); q.pop();
			for(const int adj : adjs[u]){
				if(adj ==p)
					continue;
				d[adj] = d[u] + 1;
				last = adj;
				q.push({adj, u});
			}
		}
	};

	function<int(int)> parent = [&](int u){
		return u == djs[u] ? u : djs[u] = parent(djs[u]);
	};

	for(int i = 1; i <= n; ++i)
		djs[i] = i;

	while(m--){
		cin >> a >> b;
		djs[parent(a)] = parent(b);
		adjs[a].push_back(b);
		adjs[b].push_back(a);
	}


	memset(sz, -1, sizeof(sz));

	for(int i = 1; i <= n; ++i){
		int pi = parent(i);
		if(sz[pi] == -1){
			last = pi;
			dfs(pi, 0);
			d[last] = 0;
			dfs(last, 0);
			sz[pi] = d[last];
		}
	}


	while(q--){
		cin >> t;
		if(t == 1){
			cin >> a;
			cout << sz[parent(a)] << '\n';
		}else{
			cin >> a >> b;
			int pa = parent(a), pb = parent(b);
			if(pa == pb)
				continue;
			sz[djs[pb] = pa] = max({sz[pa], sz[pb], (1 + (sz[pa] + 1) / 2 + (sz[pb] + 1) / 2)});
		}
	}
}
