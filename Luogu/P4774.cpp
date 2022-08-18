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

ll a[MAXN], reward[MAXN], r[MAXN];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	int t;

	multiset<ll> s;

	cin >> t;

	ll sword;

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
	ll g;

	while(t--){
		int n, m;

		cin >> n >> m;

		for(int i = 0; i < n; ++i)
			cin >> a[i];

		for(int i = 0; i < n; ++i)
			cin >> r[i];
		
		for(int i = 0; i < n; ++i)
			cin >> reward[i];

		for(int i = 0; i < m; ++i)
			cin >> sword, s.insert(sword);

		bool hasAns = true;

		ll lim = 0;

		for(int i = 0; i < n; ++i){
			auto iter = s.upper_bound(a[i]);
			ll atk;
			if(iter == s.begin()){
				atk = *s.begin();
				s.erase(s.begin());
			}else {
				atk = *(--iter);
				s.erase(iter);
			}
			lim = max(lim, (ll)ceil(1.0 * a[i] / atk));
			s.insert(reward[i]);
			g = exgcd(atk, r[i]);
			if(a[i] % g){
				hasAns = false;
				break;
			}
			r[i] /= g;
			a[i] = ((((lll)a[i] / g * x) % r[i]) + r[i]) % r[i];
		}

		ll M = r[0], ans = a[0];

		if(!hasAns)
			goto t;

		for(int i = 1; i < n; ++i){
			ll da = (((a[i] - ans) % r[i]) + r[i]) % r[i];
			g = exgcd(M, r[i]);
			if(da % g){
				hasAns = false;
				break;
			}
			auto tmp = (lll)M * x * (da / g);
			M = M * (r[i] / g);
			ans = (((ans + tmp) % M) + M) % M;
		}

		if(ans < lim)
			ans += M * (ceil(1.0 * (lim - ans) / M));
t:

		cout << (hasAns ? ans : -1) << '\n';
		s.clear();
	}
}

