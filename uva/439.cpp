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

const int MAXN = 1e1 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;



void solve() {
    
}

int main() {
   	int vis[MAXN][MAXN]; 
	char c1, c2, c3, c4;
	int res = 0;
	int dir[8][2] = {2, 1, 2, -1, -2, 1, -2, -1, 1, 2, 1, -2, -1, 2, -1, -2};
	auto bfs = [&](){
		queue<pair<int, int>> q;
		res = 0;
		if(c1 == c3 && c2 == c4)
			return;
		q.push({c1, c2});
		vis[c1][c2] = true;
		memset(vis, 0, sizeof(vis));
		while(!q.empty()){
			int sz = q.size();
			++res;
			while(sz--){
				auto [x, y] = q.front(); q.pop();
				for(int i = 0; i < 8; ++i){
					int xx = x + dir[i][0], yy = y + dir[i][1];
					if(xx <= 0 || yy <= 0 || xx > 8 || yy > 8 || vis[xx][yy])
						continue;
					if(xx == c3 && yy == c4)
						return;
					q.push({xx, yy});
					vis[xx][yy] = true;
				}
			}
		}
		return ;
	
	};
	while(cin >> c1 >> c2 >> c3 >> c4){
		c1 -= 'a' - 1;
		c2 -= '1' - 1;
		c3 -= 'a' - 1;
		c4 -= '1' - 1;
		bfs();
		c1 += 'a' - 1;
		c2 += '1' - 1;
		c3 += 'a' - 1;
		c4 += '1' - 1;
		cout << "To get from " << (c1) << (c2) << " to " << (c3) << (c4) << " takes " << res << " knight moves.\n";
	}

}
