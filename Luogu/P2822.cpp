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


using lll = __int128;

const int MAXN = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-7;

int c[2005][2005];
int pref[2005][2005];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	memset(c, 0, sizeof(c));
	memset(pref, 0, sizeof(pref));
	c[1][0] = c[1][1] = 1;

	int t, k;
	cin >> t >> k;
	

	for(int i = 2; i <= 2001; ++i){
		c[i][0] = 1;
		for(int j = 1; j <= i; ++j){
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % k;
		}
	}

	for(int i = 2; i <= 2001; ++i) {
		for(int j = 1; j <= i; ++j)
			pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + (c[i][j] == 0);
		pref[i][i + 1] = pref[i][i];
	}

	
	while(t--){
		int n, m;
		cin >> n >> m;
		if(m > n)
			m = n;
		cout << pref[n][m] << '\n';
	}

		
}

