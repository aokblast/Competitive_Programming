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

const int MAXN = 2e7 + 16;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-7;

static mt19937 engine;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	int tc;
	ll num;

	cin >> tc;

	auto qmul = [](const ll a, const ll b, const ll mod) -> ll{
		return ((__int128) a * b - (a / mod) * (__int128)b * mod + mod) % mod;
	};

	auto qpow = [&](ll a, ll b, const ll mod) {
		ll res = 1;
		while(b){
			if(b & 1)
				res = qmul(res, a, mod);
			a = qmul(a, a, mod);
			b >>= 1;
		}
		return res;
	};

	auto is_prime = [&](ll p){
		if(p < 3 || p % 2 == 0)
			return p == 2;
		ll u = p - 1;

		int t = 0;
		while(!(u & 1))
			u >>= 1, ++t;
		const static ll ud[] = {2,325,9375,28178,450775,9780504,1795265022};
	  	for(const ll a : ud){
			ll v = qpow(a, u, p);
			if(v == 1 || v == p - 1 || v == 0)
				continue;

			for(int j = 1; j <= t; ++j){
				v = qmul(v, v, p);
			 	if(v == p - 1 && j != t){
					v = 1;
				   	break;
			   	}
			   	if(v == 1)
				   	return false;
		   	}
		  	if(v != 1)
				return false;	
	   }	   
	   return true;
	};

	function<ll(ll, ll)> gcd = [&](ll a, ll b){
		return b == 0 ? a : gcd(b, a % b);
	};


	auto PR = [&](ll n){
		if(n == 4)
			return 2ll;
		if(is_prime(n))
			return n;
		uniform_int_distribution<ll> Rand(2, n - 2);
		
		while(1){
			ll c = Rand(engine); 
			auto f = [=](const ll x){
				return ((__int128)x * x + c) % n; 
			};
			ll t = 0, r = 0, p = 1, q;
			do{
				for(int i = 0; i < 128; ++i){
					t = f(t), r = f(f(r));
					if(t == r || (q =  (__int128)p * abs(t - r) % n) == 0)
						break;
					p = q;
				}
				ll d =  gcd(p, n);
				if(d > 1)
					return d;

			}while(t != r);
		}
	};
	unordered_map<ll, ll> mp;
	function<ll(ll)> max_prime = [&](ll n){
		if(mp.count(n))
			return mp[n];
		ll fac = PR(n);
		return mp[n] = (fac == 1 || fac == n ? fac : max(max_prime(fac), max_prime(n / fac)));

	};

	while(tc--){
		cin >> num;

		if(is_prime(num)){
			cout << "Prime\n";
			continue;
		}

		cout << max_prime(num) << '\n';
		mp.clear();
	}

}
