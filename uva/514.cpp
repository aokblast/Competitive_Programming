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

int n;
int ans;
int arr[MAXN];

void solve() {
    cin >> arr[1];
    if(arr[1] == 0){
        ans = -1;
        return;
    }
    for(int i = 2; i <= n; ++i)
        cin >> arr[i];
    int b = 1, a = 1; 
    stack<int> stk;
    while(b <= n){
        if(a == arr[b])
            ++a, ++b;
        else if(!stk.empty() && stk.top() == arr[b])
            ++b, stk.pop();
        else if(a <= n)
            stk.push(a++);
        else{
            ans = 0;
            return;
        }
    }
}

int main() {
    int c = 0;
    while(cin >> n && n){
        while(1){
            ans = 1;
            solve();
            cout << (ans == 1 ? "Yes" : (ans == -1 ? "" : "No")) << '\n';
            if(ans == -1)break;
        }
    }
}
