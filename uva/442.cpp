#include <bits/stdc++.h>
#define MAXLEN 300 + 5
#define graph vi adjs[MAXLEN]; bool visit[MAXLEN][MAXLEN]; int rd[MAXLEN], cd[MAXLEN];
#define tree1 int l[MAXLEN], r[MAXLEN], val[MAXLEN], visit[MAXLEN];
#define rpt(var, lim) for(register int var = 0; var < lim; ++var)
#define mst(x, val) memset(x, val, sizeof(x))
#define dp1d int dp[MAXLEN];
#define dp2d int dp[MAXLEN][MAXLEN];
#define dp3d int dp[MAXLEN][MAXLEN][MAXLEN];
#define mp(a, b) make_pair(a, b)
#define all(x) (x).begin(), (x).end()
#define plld(x) printf("%lld\n", x);
#define pd(x) printf("%d\n", x);
#define slld(x) scanf(" %lld", &x);
#define sd(x) scanf(" %d", &x);
#define cincout ios::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

template<typename fType, typename sType> ostream &operator<<(ostream &os, pair<fType, sType> p){
	return os << p.first << " " << p.second;
}

using vi = vector<int>;
using qi = queue<int>;
using si = stack<int>;
using ll = long long;
using pdd = pair<double, double>;
using pll = pair<ll, ll>;

pll matrix[128];

int main(){
	int n, w, h;
	sd(n)
	char id;
	stack<pll> stk;
	rpt(i, n) {
		scanf(" %c %d %d", &id, &w, &h);
		matrix[id].first = w;
		matrix[id].second = h;
	}
	string exp;
	while(cin >> exp){
		while(!stk.empty()) stk.pop();
		int m = 0;
		bool hasAnswer = true;
		for(char &c : exp){
			if(c == '(') continue;
			else if (c != ')') {
				stk.push(matrix[c]);
				continue;
			}
			pll f = stk.top();stk.pop();
			pll s = stk.top();stk.pop();
			if(s.second != f.first){
				hasAnswer = false;
				break;
			}
			m += s.first * f.first * f.second;
			stk.push(mp(s.first, f.second));
		}
		if(!hasAnswer) printf("error\n");
		else{
			pd(m)
		}	
	}

}
