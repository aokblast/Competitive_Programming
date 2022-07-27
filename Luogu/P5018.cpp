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

const int MAXN = 3e3 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	
	int vals[n + 1];

	pair<int, int> ch[n + 1];

	for(int i = 1; i <= n; ++i)
		cin >> vals[i];

	for(int i = 1; i <= n; ++i)
		cin >> ch[i].first >> ch[i].second;
	
	int res = 1;
	int szs[n + 1];

	function<int(int)> szz = [&](int u){
		return u == -1 ? 0 : (szs[u] = szz(ch[u].first) + szz(ch[u].second) + 1);
	};

	szz(1);

	function<bool(int, int)> dfs = [&](int a, int b){
		if(a == -1 && b == -1)
			return true;
		if(a == -1 || b == -1 || vals[a] != vals[b])
			return false;
		return dfs(ch[a].first, ch[b].second) && dfs(ch[a].second, ch[b].first);
	};

	for(int i = 1; i <= n; ++i){
		if(ch[i].first != -1 && ch[i].second != -1){
			if(dfs(ch[i].first, ch[i].second))
				res = max(res, szs[i]); 
		}	
	}

	cout << res << '\n';
		
}
