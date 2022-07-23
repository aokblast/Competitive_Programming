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
const ld EPointS = 1e-9;

using pdd = pair<double, double>;

inline double cross(pdd &p1, pdd &p2, pdd &p3){
	return (p2.first - p1.first) * (p3.second - p1.second) - (p2.second - p1.second) * (p3.first - p1.first);
}

inline double dis(pdd &p1, pdd &p2){
	return sqrt((p2.first - p1.first) * (p2.first - p1.first) + (p2.second - p1.second) * (p2.second - p1.second));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	int n;
	double a, b, r, x, y, t;

	cin >> n;

	cin >> a >> b >> r;
	pdd ps[n << 2];

	pdd p1 = {-b / 2 + r, a / 2 - r}, p2 = {-b / 2 + r, -a / 2 + r}, p3 = {b  / 2 - r, -a / 2 + r}, p4 = {b /  2 - r, a / 2 - r};
	
	auto rot = [](const pdd &p, double t) -> pdd{
		double co = cos(t), si = sin(t);
	  	return {co * p.first - si * p.second, si * p.first + co * p.second};
	};
	for(int i = 0; i < n; ++i){
		cin >> x >> y >> t;
		pdd t1 = rot(p1, t), t2 = rot(p2, t), t3 = rot(p3, t), t4 = rot(p4, t);
		ps[(i << 2)] = {t1.first + x, t1.second + y};
		ps[(i << 2) + 1] = {t2.first + x, t2.second + y};
		ps[(i << 2) + 2] = {t3.first + x, t3.second + y};
		ps[(i << 2) + 3] = {t4.first + x, t4.second + y};
	}

	sort(ps, ps + (n << 2));

	pdd u[n << 2], d[n << 2];

	int ui = 0, di = 0;

	for(int i = 0; i < (n << 2); ++i){
		while(ui >= 2 && cross(u[ui - 2], u[ui - 1], ps[i]) <= 0)
			--ui;
		while(di >= 2 && cross(d[di - 2], d[di - 1], ps[i]) >= 0)
			--di;
		u[ui++] = ps[i];
		d[di++] = ps[i];
	}
	double res = 0;
	for(int i = 1; i < ui; ++i)
		res += dis(u[i], u[i - 1]);

	for(int i = 1; i < di; ++i)
		res += dis(d[i], d[i - 1]);

	cout << setprecision(2) << fixed << (res + 2.0 * M_PI * r) << '\n';

}
