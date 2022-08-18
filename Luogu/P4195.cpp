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
const ll MOD = 999911659;
const ll INF = 1e9;
const ld EPS = 1e-7;



signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	int a, b, p;


	
	int x, y;
	
	function<int(int, int)> exgcd = [&](int a, int b){
		if(!b)
			return x = 1, y = 0, a;
		int d = exgcd(b, a % b);
		int t = x;
		x = y;
		y = t - (a / b) * y;
		return d;
	};

	int res;

	unordered_map<int, int> mp;

	auto bsgs = [&](){
		a %= p, b %= p;
		if(b == 1 || p == 1){
			res = 0;
			return true;
		}
		ll ax =1;
		int k = 0, g;
		while((g = exgcd(a, p)) != 1){
			if(b % g)
				return false;
			++k;
			b /= g, p /= g;
			ax = ((ll)ax * (a / g)) % p;
			if(ax == b){
				res = k;
				return true;
			}
		}

		exgcd(ax , p); 
		b = ((ll)b * (((x % p) + p) % p)) % p;

		int lim = ceil(sqrt(p));

		int cur = 1;

		mp.clear();

		for(int i = 0; i < lim; ++i){
			mp[(ll)cur * b % p] = i;
			cur = (ll)cur * a % p;
		}
		a = cur, cur = 1;
		if(!a){
			if(b)
				return false;
			res = k + 1;
			return true;
		}

		for(int i = 0; i <= lim; ++i){
			if(mp.count(cur) && i * lim - mp[cur] >= 0){
				res = i * lim - mp[cur] + k;
				return true;
			}
			cur = (ll)cur * a % p;
		}
		return false;
	};

	while(cin >> a >> p >> b && a && b && p){
		cout << (bsgs() ? to_string(res) : "No Solution") << '\n';
	}



}

