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

const int MAXN = 1e2 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

int n, m, s, v;

using pdd = pair<double, double>;

pdd go[MAXN], ho[MAXN];

vector<int> adjs[MAXN << 2];

bool vis[MAXN << 2];

int match[MAXN << 2];

bool dfs(int u){
	for(int v : adjs[u]){
		if(!vis[v]){
			vis[v] = true;
			if(match[v] == -1 || dfs(match[v])){
				match[v] = u;
				return true;
			}
		}
	}
	return false;
}

void solve() {
	
	for(int i = 0; i < n; ++i)
		cin >> go[i].first >> go[i].second;

	for(int i = 0; i < m; ++i)
		cin >> ho[i].first >> ho[i].second;
	 
	auto d = [](const pdd &p1, const pdd &p2){
		double a = p1.first - p2.first, b = p1.second - p2.second;
		return sqrt(a * a + b * b);
	};

	for(int i = 0; i < n; ++i)
		adjs[i].clear();	

	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			if(d(go[i], ho[j]) <= s * v)
				adjs[i].push_back(j);

	memset(match, -1, sizeof(match));

	int res = 0;
	for(int i = 0; i < n; ++i){
		memset(vis, 0, sizeof(vis));
		if(dfs(i))
			++res;
	}

	cout << (n - res) << '\n';

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;

	while(cin >> n >> m >> s >> v)
	   solve();	
}
