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

const int MAXN = 3e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

using pii = pair<int, int>;
using pdd = pair<double, double>;


inline double cross(const pdd &p1, const pdd &p2, const pdd &p3){
	return (p2.first - p1.first) * (p3.second - p1.second) - (p2.second - p1.second) * (p3.first - p1.first);

}

inline double dist(const pdd &p1, const pdd &p2){
	return sqrt((p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	pdd ps[n];

	for(int i = 0; i < n; ++i)
		cin >> ps[i].first >> ps[i].second;
	

	sort(ps, ps + n);

	pdd u[n], d[n];
	int ui = 0, di = 0;
	for(int i = 0; i < n; ++i){
		while(ui >= 2 && cross(u[ui - 2], u[ui - 1], ps[i]) <= 0)
			--ui;
		while(di >= 2 && cross(d[di - 2], d[di - 1], ps[i]) >= 0)
			--di;
		u[ui++] = ps[i];
		d[di++] = ps[i];
	}

	double res = 0;

	for(int i = 1; i < ui; ++i)
		res += dist(u[i], u[i - 1]);

	for(int i = 1; i < di; ++i)
		res += dist(d[i], d[i - 1]);

	printf("%.2lf\n", res);




}
