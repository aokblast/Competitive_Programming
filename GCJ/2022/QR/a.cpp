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

const int MAXN = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

int n, m;

void solve() {
   	cin >> n >> m;
	int ji = m * 2;
	cout << "..";
	for(int i = 0; i < ji - 1; ++i)
		cout << (i % 2 ? '-' : '+');
	cout << '\n';

	for(int i = 0; i < n; ++i){
		cout << (i == 0 ? '.' : '|');
		for(int j = 0; j < ji; ++j)
			cout << (j % 2 ? '|' : '.');
		cout << '\n' << '+';
		for(int j = 0; j < ji; ++j)
			cout << (j % 2 == 0? '-' : '+');	
		

		cout << '\n';
	}

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cout << "Case #" << t << ":\n";
        solve();
    }
}
