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

const int MAXN = 1e7 + 5;
const ll MOD = 999911659;
const ll INF = 1e9;
const ld EPS = 1e-7;

const ll MODS[] = {2, 3, 4679, 35617};

ll cu[4] = {0};

ll fac[40000];
ll inv[40000];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	ll k, g;

	cin >> k >> g;


	ll x, y;

	function<ll(ll, ll)> exgcd = [&](ll a, ll b){
		if(!b)
			return x = 1, y = 0, a;
		ll d = exgcd(b, a % b);
		ll t = x;
		x = y;
		y = t - (a / b) * y;
		return d;
	};

	if(g % MOD == 0)
		return (cout << 0 << '\n', 0);

	auto init = [&](int p){
		fac[0] = 1;
		

		for(int i = 1; i < p; ++i)
			fac[i] = (fac[i - 1] * i) % p;

		inv[p - 1] = (exgcd(fac[p - 1], p), x);

		for(int i = p - 2; i >= 0; --i)
			inv[i] = (inv[i + 1] * (i + 1)) % p;
	};


	auto C = [](ll a, ll b, ll p){
		return b > a ? 0 : (fac[a] * inv[b] % p) * inv[a - b] % p;
	};

	function<ll(ll, ll, ll)> lucas = [&](ll n, ll m, ll p){
		if(m == 0)
			return 1ll;
		return (C(n % p, m % p , p) * lucas(n / p, m / p, p)) % p;
	};

	for(int j = 0; j < 4; ++j){

		init(MODS[j]);

		int lim = sqrt(k);
		
		for(int i = 1; i <= lim; ++i){
			if(k % i == 0){
				cu[j] += lucas(k, i, MODS[j]);
				if(i * i != k) {
					cu[j] += lucas(k, k / i, MODS[j]);
				}
			}
		}
	}

	ll n = MOD - 1, res = 0;

	
	auto qpow = [&](ll a, ll b, ll m){
		ll res = 1;	
		while(b){
			if(b & 1){
				res = (res * a) % m;
			}
			b >>= 1;
			a = (a * a) % m;
		}
		return res;
	};


	for(int i = 0; i < 4; ++i){
		ll m = n / MODS[i];
		exgcd(m, MODS[i]);
		res = (res + (cu[i] * m % n) * x) % n;	
	}

	dbg(g, res);

	cout << qpow(g, ((res % n) + n) % n, MOD) << '\n';
}

