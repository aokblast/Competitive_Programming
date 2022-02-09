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

const int MAXN = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;



void solve() {
    
}

int main() {

	int n, m;
	vector<pair<int, int>> adjs[MAXN];
	vector<int> ans(MAXN);
	int d[MAXN];
	bool vis[MAXN];
	bool inq[MAXN];

	auto bfs = [&](){
		queue<int> q;
		q.push(n);
		memset(d, 0x3f, sizeof(d));
		memset(vis, 0, sizeof(vis));
		vis[n] = true;
		d[n] = 0;
		while(!q.empty()){
			int f = q.front(); q.pop();
			for(const auto [adj, color] : adjs[f]){
				d[adj] = min(d[adj], d[f] + 1);
				if(!vis[adj])
					q.push(adj), vis[adj] = true;
			}
		}
	};
	auto bfs2 = [&](){
		queue<int> q;
		q.push(1);
		memset(vis, 0, sizeof(vis));
		memset(inq, 0, sizeof(inq));
		fill(ans.begin(), ans.begin()  + d[1], 0);
		
		while(!q.empty()){
			int f = q.front(); q.pop();
			int mCol = INT_MAX;
			vis[f] = true;
			for(const auto [adj, color] : adjs[f])
				if(d[adj] == d[f] - 1 && !vis[adj])
					mCol = min(mCol, color);
			for(const auto [adj, color] : adjs[f]){
				if(d[adj] == d[f] - 1 && !vis[adj] && !inq[adj] && color == mCol){
					q.push(adj), inq[adj] = true;
				}
			}
			int idx = d[1] - d[f];
			if(!ans[idx])
				ans[idx] = mCol;
			else
				ans[idx] = min(ans[idx], mCol);
		}	
	};
	
	while(cin >> n >> m){
		int a, b, c;
		for(int i = 0; i <= n; ++i)
			adjs[i].clear();
		while(m--){
			cin >> a >> b >> c;
			adjs[a].push_back({b, c});
			adjs[b].push_back({a, c});
		}
		bfs();
		bfs2();
		int cnt = d[1];
		cout << cnt << '\n';
		for(int i = 0; i < cnt; ++i)
			cout << ans[i] << ((i + 1 == cnt) ? '\n' : ' ');
		
	
	}


}
