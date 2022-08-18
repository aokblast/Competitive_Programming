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

ll inv[MAXN], power[MAXN], pinv[MAXN];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	int tc;
	cin >> tc;

	ll n, m, p;



	auto C = [&](ll n, ll m){
		return n < m ? 0 : power[n] * pinv[m] % p * pinv[n - m] % p;
	};



	function<ll(ll, ll)> lucas = [&](ll n, ll m){
		if(m == 0)
			return 1ll;
		return (C(n % p, m % p) * lucas(n / p, m / p)) % p;
	};

	


	while(tc--){
		cin >> n >> m >> p;

		inv[0] = pinv[0] = power[0] = inv[1] = pinv[1] = power[1] = 1;

		for(ll i = 2; i <= p; ++i)
			inv[i] = (ll)(p - p / i) * inv[p % i] % p, power[i] = power[i - 1] * i % p, pinv[i] = pinv[i - 1] * inv[i] % p;

		cout << lucas(n + m, m) << '\n';




		

	}
		
}

