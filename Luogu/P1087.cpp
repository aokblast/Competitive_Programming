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
	
	int n, ps[MAXN];
	char c;
	cin >> n;

	ps[0] = 0;
	
	for(int i = 1; i <= (1 << n); ++i)
		cin >> c, ps[i] = ps[i - 1] + c - '0';

	function<void(int, int)> dfs = [&](int l, int r){
		if(l == r)
			return void(cout << (ps[l + 1] - ps[l] == 0 ? 'B' : 'I'));
		int mid = (l + r) >> 1;

		dfs(l, mid);
		dfs(mid + 1, r);
		int val = ps[r + 1] - ps[l];
		cout << (val == (r - l + 1) ? 'I' : (val == 0 ? 'B' : 'F'));
	};
	dfs(0, (1 << n) - 1);

	cout << '\n';


	
	
	
}
