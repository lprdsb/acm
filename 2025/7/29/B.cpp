#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define inf 0x3f3f3f3f
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)


#define maxn 1000000
int n, m, tot = 0, ch[maxn + 5][52];
LL as = 0;

char s[maxn + 5];
struct Node {
    int len, ch[52], fa;
} poi[2 * maxn + 5];


int tot1 = 1;
int ins(int x, int las) {
    int p = las, np;
    if(poi[p].ch[x] && poi[p].len + 1 == poi[poi[p].ch[x]].len) return poi[p].ch[x];
    else np = ++tot1;
    poi[np].len = poi[p].len + 1;
    while(p && !poi[p].ch[x]) poi[p].ch[x] = np, p = poi[p].fa;
    if(!p) poi[np].fa = 1;
    else {
        int q = poi[p].ch[x];
        if(poi[p].len + 1 == poi[q].len) poi[np].fa = q;
        else {
            int nq = ++tot1; poi[nq] = poi[q];
            poi[nq].len = poi[p].len + 1;
            poi[np].fa = poi[q].fa = nq;
            while(p && poi[p].ch[x] == q) poi[p].ch[x] = nq, p = poi[p].fa;
        }
    }
    return np;
}

int to[maxn + 5];

void sol() {
    queue<int> q;
    q.push(0);
    to[0] = 1;
    while(q.size()) {
        int u = q.front(); q.pop();
        For(i, 0, 51) {
            int v = ch[u][i];
            if(!v) continue;
            to[v] = ins(i, to[u]);
            q.push(v);
        }
    }
}

#define P 998244353
int vis[maxn + 5];
int f[maxn + 5][52], sum[maxn + 5];
void dfs(int u) {
    if(vis[u]) return;
    vis[u] = 1;
    sum[u] = 1;
    For(o, 0, 51) {
        int v = poi[u].ch[o];
        if(v) {
            dfs(v);
            sum[u] = (sum[u] + sum[v]) % P;
            For(p, 0, 51) f[u][p] = (f[u][p] + f[v][p]) % P;
        }
        else f[u][o] = (f[u][o] + 1) % P;
    }
}

struct Mat {
    int a[52][52];
} tr[35], uni;
Mat operator * (const Mat &x, const Mat &y) {
    Mat res = {};
    For(i, 0, 51) {
        For(j, 0, 51) {
            int k = x.a[i][j];
            For(p, 0, 51) {
                res.a[i][p] = (res.a[i][p] + 1ll * k * y.a[j][p]) % P;
            }
        }
    }
    return res;
}
Mat operator + (const Mat &x, const Mat &y) {
    Mat res = {};
    For(i, 0, 51) {
        For(j, 0, 51) {
            res.a[i][j] = (x.a[i][j] + y.a[i][j]) % P;
        }
    }
    return res;
}
Mat operator - (const Mat &x, const Mat &y) {
    Mat res = {};
    For(i, 0, 51) {
        For(j, 0, 51) {
            res.a[i][j] = (x.a[i][j] - y.a[i][j] + P) % P;
        }
    }
    return res;
}

void out(Mat a) {

    For(i, 0, 51) {
        For(j, 0, 51) cout << a.a[i][j] << " "; cout << endl;
    }
    puts("");
}

Mat fp(Mat x, int y) {
    Mat res = uni;
    while(y) {
        if(y & 1) res = res * x;
        x = x * x;
        y >>= 1;
    }
    return res;
}

Mat h[35];

Mat get_as(int x) {
    Mat res = {}, tmp = uni;
    int now = 0;
    Rof(o, 30, 0) {
        if((x >> o) & 1) {
            res = res + tmp * h[o];
            tmp = tmp * tr[o];
            now = now + (1 << o);
            // out(res);
        }
    }
    return res;
}

int main() {
    For(o, 0, 51) uni.a[o][o] = 1;
    // freopen("in.txt", "r", stdin);
    // scanf("%d", &n);
    int N = 1;
    int n, k; scanf("%d%d", &n, &k);
    For(i, 1, N) {
        scanf("%s", s + 1); m = strlen(s + 1);
        int now = 0;
        For(j, 1, m) {
            int x;
            if(s[j] >= 'a' && s[j] <= 'z') x = s[j] - 'a';
            else x = s[j] - 'A' + 26;
            if(!ch[now][x]) ch[now][x] = ++tot;
            now = ch[now][x];
        }
    }
    sol();
    dfs(1);
    For(o, 0, 51) {
        int u = poi[1].ch[o];
        if(u) {
            For(p, 0, 51) tr[0].a[o][p] = (tr[0].a[o][p] + f[u][p]) % P;
        }
    }
    For(o, 0, 51) {
        int u = poi[1].ch[o];
        if(!u) {
            For(p, 0, 51) tr[0].a[o][p] = tr[0].a[p][o] = 0;
        }
    }
    // out(tr[0]);
    For(o, 1, 30) tr[o] = tr[o - 1] * tr[o - 1];
    h[0] = uni;
    For(o, 1, 30) h[o] = h[o - 1] * tr[o - 1] + h[o - 1];
    // Mat as = uni;
    // For(i, 1, k - 1) as = as + fp(tr[0], i);
    Mat as = get_as(k);
    // // out(as);
    int res = 0;
    For(o, 0, 51) For(p, 1, 51) as.a[0][o] = (as.a[0][o] + as.a[p][o]) % P;
    For(o, 0, 51) if(poi[1].ch[o]) res = (res + 1ll * sum[poi[1].ch[o]] * as.a[0][o] % P) % P;
    printf("%d\n", res + 1);
}