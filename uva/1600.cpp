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

const int MAXN = 20 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;


struct E{
	int x, y, cnt;
	E() = default;
	E(int x, int y, int cnt = 0) : x(x), y(y), cnt(cnt){
	}
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
	int res = 0;
	int m, n, k;
	bool mat[MAXN][MAXN], vis[MAXN][MAXN][MAXN];
	int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
	auto bfs = [&](){
		queue<E> q;
		q.emplace(E(1, 1));
		memset(vis, 0, sizeof(vis));
		res = 0;
		vis[1][1][0] = true;
		if(m == 1 && n == 1)
			return;
		
		while(!q.empty()){
			int sz = q.size();
			++res;
			while(sz--){
				auto [x, y, cnt] = q.front(); q.pop();
				for(int i = 0; i < 4; ++i){
					int xx  = x + dir[i][0], yy = y + dir[i][1];
					if(xx == m && yy == n)
						return;
					if(xx <= 0 || yy <= 0 || xx > m || yy > n || (mat[xx][yy] && cnt >= k))
						continue;
					E ne(xx, yy, mat[xx][yy] ? (cnt + 1) : 0);
					if(vis[ne.x][ne.y][ne.cnt])
						continue;
					q.push(ne);
					vis[ne.x][ne.y][ne.cnt] = true;
				}	
			}
		}
		res = -1;
	};
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
		
		cin >> m >> n >>  k;
		memset(mat, 0, sizeof(mat));
		for(int i = 1; i <= m; ++i)
			for(int j = 1; j <= n; ++j)
				cin >> mat[i][j];
    	bfs();
		cout << res << '\n';
	}
}
