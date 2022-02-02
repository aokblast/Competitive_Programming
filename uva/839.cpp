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




int main() {
    int tc = 1;
    cin >> tc;
    
    bool res = true;

    function<ll()> dfs = [&](){
        ll w1, d1, w2, d2;
        cin >> w1 >> d1 >> w2 >> d2;
        if(!w1)
            w1 = dfs();
        if(!w2)
            w2 = dfs();
        res =  res && (w1 * d1 == w2 * d2);
        return w1 + w2;
    };

    


    for (int t = 1; t <= tc; t++) {
        res = true;
        dfs();
        cout << (res == true ? "YES" : "NO") << '\n';
        if(t != tc)
            cout << '\n';

    }
}
