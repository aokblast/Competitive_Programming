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


struct T{
	ll a = 0, ai = 0, aii = 0;
	T() = default;
	const T& operator*=(ll d){
		a *= d, ai *= d, aii *= d;
		return *this;
	}

	const T operator*(ll d) const {
		T res = *this;
		return res *= d;
	}

	const T& operator+=(const T& t){
		a += t.a, ai += t.ai, aii += t.aii;
		return *this;
	}

	const T operator+(const T& t) const{
		T res = *this;
		res += t;
		return res;
	}

};

using lll = __int128;

const int MAXN = 1e5 + 5;
const ll MOD = 998244353;
const ll INF = 1e9;
const ld EPS = 1e-7;

T val[MAXN << 2];
ll tag[MAXN << 2] = {0};
T sum[MAXN << 2];

void pushdown(int u){
	val[u << 1] += sum[u << 1] * tag[u];
	tag[u << 1] += tag[u];
	val[u << 1 | 1] += sum[u << 1 | 1] * tag[u];
	tag[u << 1 | 1] += tag[u];
	tag[u] = 0;
}

void build(int l, int r, int u){
	if(l == r){
		sum[u] = {1, l, 1ll * l * l};
		return;
	}
	int mid = l + (r - l) / 2;
	build(l, mid, u << 1), build(mid + 1, r, u << 1 | 1);
	sum[u] = sum[u << 1] + sum[u << 1 | 1];
}

void modify(int l, int r, int cl, int cr, ll v, int u){
	if(cl >= l && cr <= r){
		val[u] += sum[u] * v;
		tag[u] += v;
		return ;
	}
	pushdown(u);
	int mid = cl + (cr - cl) / 2;
	if(l <= mid)
		modify(l, r, cl, mid, v, u << 1);
	if(r > mid)
		modify(l, r, mid + 1, cr, v, u << 1 | 1);
	val[u] = val[u << 1] + val[u << 1 | 1];
}

T query(int l, int r, int cl, int cr, int u){
	if(cl >= l && cr <= r){
		return val[u];
	}
	T res;
	int mid = cl + (cr - cl) / 2;
	pushdown(u);
	if(l <= mid)
		res += query(l, r, cl, mid, u << 1);
	if(r > mid)
		res += query(l, r, mid + 1, cr, u << 1 | 1);
	return res;
}



signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	
	int n, m;

	cin >> n >> m;

	--n;
	build(1, n, 1);
	char c;
	ll l, r;
	ll val;


	function<ll(ll, ll)> gcd = [&](ll x, ll y){
		return y == 0 ? x : gcd(y, x % y);
	};

	while(m--){
		cin >> c;
		if(c == 'C'){
			cin >> l >> r >> val;
			--r;
			modify(l, r, 1, n, val, 1);
		}else{
			cin >> l >> r;
			--r;
			auto q = query(l, r, 1, n, 1);
			ll res = (r + 1 - l - r * l) * q.a + (r + l) * q.ai - q.aii;
			ll len = r - l  + 1;
			ll tmp = len * (len + 1) / 2;
			ll g = gcd(res, tmp);
			cout << (res / g) << '/' << (tmp / g) << '\n';

		}
	}
	
	


}

