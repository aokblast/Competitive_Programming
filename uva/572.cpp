#include <bits/stdc++.h>
#define MAXLEN 100
#define graph vi adjs[MAXLEN]; bool visit[MAXLEN]; int rd[MAXLEN], cd[MAXLEN];
#define tree1 int l[MAXLEN], r[MAXLEN], val[MAXLEN], visit[MAXLEN];
#define rpt(var, start, lim) for(register int var = start; var < lim; ++var)
#define mst(x, val) memset(x, val, sizeof(x))
#define dp1d int dp[MAXLEN];
#define dp2d int dp[MAXLEN][MAXLEN];
#define dp3d int dp[MAXLEN][MAXLEN][MAXLEN];
#define mp(a, b) make_pair(a, b)
#define all(x) (x).begin(), (x).end()
#define plld(x) printf("%lld\n", x)
#define pd(x) printf("%d\n", x)
#define slld(x) scanf(" %lld", &(x))
#define sd(x) scanf(" %d", &(x))
#define cincout std::ios::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

template<typename fType, typename sType> ostream &operator<<(ostream &os, pair<fType, sType> p){
	return os << p.first << " " << p.second;
}

using vi = vector<int>;
using qi = queue<int>;
using pqi = priority_queue<int>;
using si = stack<int>;
using ll = long long;
using pdd = pair<double, double>;
using pll = pair<ll, ll>;

int x, y;

char grid[MAXLEN][MAXLEN];
bool visit[MAXLEN][MAXLEN];

void dfs(int a, int b){
	if(a < 0 || b < 0 || a >= x || b >= y) return;
	
	if(grid[a][b] == '@' && !visit[a][b]){
		visit[a][b] = true;
		dfs(a + 1, b);
		dfs(a - 1, b);
		dfs(a + 1, b + 1);
		dfs(a + 1, b - 1);
		dfs(a - 1, b + 1);
		dfs(a - 1, b - 1);
		dfs(a, b + 1);
		dfs(a, b - 1);	
	}
}

int main(){
        int k = 0;
	while(scanf(" %d %d", &x, &y) && x != 0 && y !=0){
		mst(grid, 0);
		mst(visit, 0);
		rpt(i, 0, x){
			rpt(j, 0, y){
				scanf(" %c", &grid[i][j]);
			}
		}
		int ans = 0;
		rpt(i, 0, x){
			rpt(j, 0, y){
				if(grid[i][j] == '@' && !visit[i][j]) {
					++ans;
					dfs(i, j);
				}	
			}
		}
		pd(ans);
	}
}
