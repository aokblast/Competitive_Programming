#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
#include<cstdio>
#include<vector>
#include<string>
#include<fstream>
#include<cstring>
#include<ctype.h>
#include<iostream>
#include<algorithm>
#define maxn 1000
#define INF (1<<30)
#define PI acos(-1.0)
#define mem(a, b) memset(a, b, sizeof(a))
#define For(i, n) for (int i = 0; i < n; i++)
#define debug puts("===============")
const int N = 362881;
typedef long long ll;
using namespace std;
int ch, cv;
int fac[10];
struct node {
    int x, w;
    node(int _x, int _w) {
        x = _x, w = _w;
    }
    bool operator < (const node & T) const {
        return w > T.w;
    }
};
void Atoint(int* a, int &x) {
    int i, j, y;
    x = 0;
    for (i = 0; i < 9; i++) {
        y = a[i];
        for (j = 0; j < i; j++)
            if (a[j] < a[i]) y--;
        x += fac[8 - i] * y;
    }
}
void inttoA(int x, int* a) {
    int has[10] = {0};
    int i, j, y;
    for (i = 0; i < 9; i++) {
        y = x / fac[8 - i];
        for (j = 0; j < 9; j++) if (!has[j]) {
            if (y == 0) break;
            y--;
        }
        a[i] = j, has[j] = 1, x %= fac[8 - i];
    }
}
int st, ed;
priority_queue<node> q;
int d[N], vis[N], a[10], b[10];
void update(int x, int w) {
    if (!vis[x] && d[x] > w) {
        d[x] = w, q.push(node(x, w));
    }
}
void work() {
    Atoint(a, st), Atoint(b, ed);
    while(!q.empty()) q.pop();
    memset(d, 0x7F, sizeof(d));
    memset(vis, 0, sizeof(vis));
    d[st] = 0;
    q.push(node(st, 0));
    int x, w, i, y;
    while(!q.empty()) {
        x = q.top().x, w = q.top().w, q.pop();
        if (vis[x]) continue;
        vis[x] = 1;
        if (x == ed) {
            printf("%d\n", w);
            break;
        }
        inttoA(x, a);
        for (i = 0; i < 9; i++) if (!a[i]) break;
        swap(a[i], a[(i + 1) % 9]);
        Atoint(a, y);
        update(y, w + ch);
        swap(a[i], a[(i + 1) % 9]);
        swap(a[i], a[(i + 8) % 9]);
        Atoint(a, y);
        update(y, w + ch);
        swap(a[i], a[(i + 8) % 9]);
        swap(a[i], a[(i + 3) % 9]);
        Atoint(a, y);
        update(y, w + cv);
        swap(a[i], a[(i + 3) % 9]);
        swap(a[i], a[(i + 6) % 9]);
        Atoint(a, y);
        update(y, w + cv);
    }
}
int main () {
    //freopen("1.txt", "r", stdin);
    fac[0] = 1;
    for (int i = 1; i < 10; i++) fac[i] = fac[i - 1] * i;
    while(scanf("%d%d", &ch, &cv), ch || cv) {
        for (int i = 0; i < 9; i++) scanf("%d", a + i);
        for (int i = 0; i < 9; i++) scanf("%d", b + i);
        work();
    }
    return 0;
}
