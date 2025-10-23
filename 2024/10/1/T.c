#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define LL long long
#define mod 999997
#define maxn 1000000

int P[2], b[2];

int hd[maxn + 5], len = 0, net[maxn + 5];
LL val[maxn + 5][3];

void add(LL v[3]) {
    int u = v[1] % mod;
    if(len != maxn) {
        For(o, 0, 2) val[len][o] = v[o];
        net[len] = hd[u];
        hd[u] = len++;
    }
    else {
        For(o, 0, 2) val[hd[u]][o] = v[o];
    }
}

int lim[2] = { 7, 40 };
int st[2][105];
int b1[2];
LL ss[2];
void out(LL x, int ty) {
    int bb = ty ? 2 : 26;
    For(i, 1, lim[ty]) st[ty][i] = x % bb, x /= bb;
    Rof(i, lim[ty], 1) {
        if(!ty) putchar('a' + st[ty][i]);
        else {
            // printf("%d", st[ty][i]);
            out(ss[st[ty][i]], 0);
        }
    }
    if(ty) puts("");
}

int chk(LL v[3], int ty) {
    int u = v[1] % mod;
    for(int i = hd[u]; ~i; i = net[i]) {
        int fl = 1;
        For(o, 1, 1) if(val[i][o] != v[o]) {
            fl = 0;
            break;
        }
        if(fl) {
            if(ty) {
                // printf("%lld %lld\n", v[0], val[i][0]);
                out(v[0], 1); out(val[i][0], 1);
            }
            else {
                b1[0] = v[2]; ss[0] = v[0];
                b1[1] = val[i][2]; ss[1] = val[i][0];
            }
            return 1;
        }
    }
    return 0;
}

int dfs(int pos, LL now, int hsh[2]) {
    if(!pos) {
        LL v[3] = { now ,hsh[0], hsh[1] };
        if(chk(v, 0)) return 1;
        else add(v);
        return 0;
    }
    For(o, 0, 25) {
        if(rand() % 26 <= 5) {
            int hshi[2];
            For(o1, 0, 1) hshi[o1] = (1ll * hsh[o1] * b[o1] + o + 1) % P[o1];
            if(dfs(pos - 1, now * 26 + o, hshi)) return 1;
        }
    }
    return 0;
}

int B = 1;
int dfs1(int pos, LL now, int hsh) {
    if(!pos) {
        LL v[3] = { now , hsh, 0 };
        if(chk(v, 1)) return 1;
        else add(v);
        return 0;
    }
    if(rand() & 1) {
        if(dfs1(pos - 1, now << 1, (1ll * hsh * B + b1[0]) % P[1])) return 1;
        if(dfs1(pos - 1, now << 1 | 1, (1ll * hsh * B + b1[1]) % P[1])) return 1;
    }
    else {
        if(dfs1(pos - 1, now << 1 | 1, (1ll * hsh * B + b1[1]) % P[1])) return 1;
        if(dfs1(pos - 1, now << 1, (1ll * hsh * B + b1[0]) % P[1])) return 1;
    }
    return 0;
}

int main() {
    // freopen("in.txt", "r", stdin);
    memset(hd, -1, sizeof hd);
    For(o, 0, 1) scanf("%d%d", &b[o], &P[o]);
    if(P[0] > P[1]) {
        int tmp;
        tmp = b[0]; b[0] = b[1]; b[1] = tmp;
        tmp = P[0]; P[0] = P[1]; P[1] = tmp;
    }
    int hsh[2] = { 0, 0 };
    lim[0] = 7; lim[1] = 30;
    dfs(lim[0], 0, hsh);
    For(i, 1, lim[0]) B = 1ll * B * b[1] % P[1];
    // out(ss[0], 0); puts(""); out(ss[1], 0); puts("");
    memset(hd, -1, sizeof hd); len = 0;
    dfs1(lim[1], 0, 0);
}