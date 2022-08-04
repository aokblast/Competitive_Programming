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

const int MAXN = 1e7 + 5;
const ll MOD = 19260817;
const ll INF = 1e9;
const ld EPS = 1e-7;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	int n, p, k;

	cin >> n >> p >> k;

	int cur = 1;
	int res = 0;

	int arr[n + 1], ji[n + 1], rev[n + 1];
	ji[0] = 1;
	
	for(int i = 1; i <= n; ++i)
		cin >> arr[i], ji[i] = ((ll)ji[i - 1] * arr[i]) % p;
	int x, y;

	function<int(int, int)> exgcd = [&](int a, int b){
		if(!b)
			return x = 1, y = 0, a;
		int d = exgcd(b, a % b);
		int t =  x;
		x = y;
		y = t - (a / b) * y;
		return d;
	};

	rev[n] = (exgcd(ji[n], p), x);

	for(int i = n; i >= 1; --i)
		rev[i - 1] = (ll)rev[i] * arr[i] % p;

	for(int i = 1; i <= n; ++i){
		cur = ((ll)cur * k) % p;
		int c = ((ll)cur * rev[i] % p) * ji[i - 1] % p;
		res = (res + c) % p;
	}

	cout << (((res % p) + p) % p) << '\n';


}

