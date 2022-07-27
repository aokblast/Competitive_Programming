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

	int n, k, a, b;

	cin >> n >> k;
	

	pair<int, int> ps[(n + 1) << 1];
	vector<int> adjs[n + 1];

	int d1[n + 1], d2[n + 1];

	int pa[(n + 1) << 1];

	for(int i = 1; i < n; ++i)
		cin >> a >> b, ps[i << 1] = {b, 1}, ps[i << 1 | 1] = {a, 1}, adjs[a].push_back(i << 1), adjs[b].push_back(i << 1 | 1);
	int last = 0;
	auto bfs = [&](int u, int p){
		queue<pii> q;
		q.push({u, p});
		while(!q.empty()){
			const auto [u, p] = q.front(); q.pop();
			for(const int e : adjs[u]){
				const auto [v, w] = ps[e];
				if(v == p)
					continue;
				d1[v] = d1[u] + 1;
				pa[v] = e ^ 1;
				if(d1[v] > d1[last])
					last = v;
				q.push({v, u});
			}
		}
	};

	auto bfs2 = [&](int u){
		queue<int> q;
		q.push(u);
		while(!q.empty()){
			int u = q.front(); q.pop();
			int e = pa[u];
			if(e == -1)
				break;
			ps[e].second = ps[e ^ 1].second = -1;
			q.push(ps[e].first);
		}
	};
	int d = 0;

	function<void(int, int)> dfs = [&](int u, int p){
		d1[u] = d2[u] = 0;
		for(const int e : adjs[u]){
			const auto [v, w] = ps[e];
			if(v == p)
				continue;
			dfs(v, u);
			int t = d1[v] + w;
			if(t > d1[u])
				d2[u] = d1[u], d1[u] = t;
			else if(t > d2[u])
				d2[u] = t;
		}
		d = max(d, d1[u] + d2[u]);
	};
	memset(d1, 0, sizeof(d1));
	last = 1;
	bfs(1, 0);
	d1[last] = 0;
	memset(pa, -1, sizeof(pa));
	bfs(last, 0);
	int dd = d1[last];
	if(k == 1){
		cout << (2 * (n - 1) - dd + 1) << '\n';
		return 0;
	}

	bfs2(last);

	dfs(1, 0);
	cout << (2 * (n - 1) - dd - d + 2) << '\n';
		
		
}
