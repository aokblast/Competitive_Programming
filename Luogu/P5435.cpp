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

const int MAXN = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-7;

int minp[MAXN] = {0};
int g[1010][1010];
int fac[MAXN][3];
bitset<MAXN> vis;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	
	const ll MOD = 998244353;

	int n;
	cin >> n;


	int a[n + 1], b[n + 1];

	fac[1][0] = fac[1][1] = fac[1][2] = 1;
	for(int i = 2; i < MAXN; ++i){
		if(!vis[i]){
			fac[i][0] = fac[i][1] = 1, fac[i][2] = i;
			if(1ll * i * i > MAXN)
				continue;
			for(int j = i * i; j <= MAXN; j += i){
				vis[j] = 1;
				if(!minp[j])
					minp[j] = i;
			}
		}else{
			int tmp = i / minp[i], a = minp[i] * fac[tmp][0], b = fac[tmp][1], c = fac[tmp][2];
			if(a > b)
				swap(a, b);
			if(b > c)
				swap(b, c);
			fac[i][0] = a, fac[i][1] = b, fac[i][2] = c;
		}
	}

	for(int i = 1; i <= 1000; ++i){
		g[i][0] = g[0][i] = i;
		for(int j = 1; j <= i ; ++j)
			g[i][j] = g[j][i] = g[j][i % j];
	}


	auto gcd = [&](int x, int y){
		int tmp = g[fac[x][0]][y % fac[x][0]], res = tmp;
		y /= tmp;
		tmp = g[fac[x][1]][y % fac[x][1]], res *= tmp, y /= tmp;
		tmp = fac[x][2] > 1000 ? (y % fac[x][2] == 0 ? fac[x][2] : 1) : g[fac[x][2]][y % fac[x][2]], res *= tmp;
		return res;
	};

	for(int i = 1; i <= n; ++i)
		cin >> a[i];

	for(int j = 1; j <= n; ++j)
		cin >> b[j];



	for(int i = 1; i <= n; ++i){
		ll cur = 0;
		ll tmp = 1;
		for(int j = 1; j <= n; ++j){
			tmp = (tmp * i) % MOD;
			cur += tmp * gcd(a[i], b[j]);
		}

		cout << (cur % MOD) << '\n';
	}


 
}
