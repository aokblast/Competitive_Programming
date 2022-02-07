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

const int MAXN = 1e4 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

int main() {
    int tc = 1;
    cin >> tc;
    string lines[MAXN];
    int n = 0;

    auto isSym = [](char c){
        return c != '-' && c != '|' && c != ' ' && c != '#';
    };
    function<void(int, int)> dfs = [&](int x, int y){
        if(x >= n)
            return;
        cout << lines[x][y] << '(';
        if(lines[x + 1][y] == '|'){
            int l = y;
            while(l >= 0 && lines[x + 2][l] == '-')
                --l;
            ++l;
            while(l < lines[x + 3].size() && lines[x + 2][l] == '-'){
                if(isSym(lines[x + 3][l]) )
                    dfs(x + 3, l);
                ++l;
            }

        }
        cout << ')';

    };
    getchar();
    for(int t = 1; t <= tc; ++t){
         n = 0;
         while(getline(cin, lines[n]) && lines[n] != "#")
            ++n;
         cout << '(';
        for(int i = 0; i < lines[0].size(); ++i)
            if(lines[0][i] != ' '){
                dfs(0, i);
                break;
            }
        cout << ")\n";
        

    } 
    getline(cin, lines[0]);
}
