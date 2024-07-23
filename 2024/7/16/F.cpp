#include<bits/stdc++.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define Tra(u, i) for(int i = hd[u]; ~i; i = e[i].net)
#define cst const
#define LL long long
#define DD double
#define LD long double
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define inf 0x3f3f3f3f
#define Inf 0x3f3f3f3f3f3f3f3f
#define eps 1e-12
using namespace std;

template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

#define maxn 100
LL X, N, M;
struct Com {
    LL A, B, C, D, E, F, G, H, I, U, V, J, K, L, R, P[maxn + 5];
} com[maxn + 5];

pair<LL, LL> stock[maxn + 5][maxn + 5][maxn + 5];

DD get_cash(LL x, int idx, int l, int r) {
    if(!idx) return 0;
    DD res = 0;
    res += x * com[idx].A + com[idx].B;
    res += (r - l) * (r - l + 1) / 2 * com[idx].C + (r - l + 1) * (com[idx].D + com[idx].C * x);
    if(com[idx].R == r) res += (DD)(r - l + 2) * (com[idx].C * (x + r - l) + com[idx].D) / 12;
    res += (r - l) * (r - l + 1) / 2 * com[idx].E + (r - l + 1) * com[idx].F;
    if(com[idx].R == r) res -= com[idx].E * (r - l) + com[idx].F;
    res += (DD)(stock[idx][l][r].fir + x * stock[idx][l][r].sec) / com[idx].I;
    return res;
}

int vf[maxn + 5][maxn + 5][maxn + 5], vg[maxn + 5][maxn + 5];
DD f[maxn + 5][maxn + 5][maxn + 5], g[maxn + 5][maxn + 5];

int alive[maxn + 5][maxn + 5];

int main() {
    // freopen("in.txt", "r", stdin);
    read(X); read(N); read(M);
    For(i, 1, M) {
        read(com[i].A);read(com[i].B);read(com[i].C);read(com[i].D);read(com[i].E);read(com[i].F);
        read(com[i].G);read(com[i].H);read(com[i].I);read(com[i].U);read(com[i].V);read(com[i].J);read(com[i].K);read(com[i].L);read(com[i].R);
        For(j, 1, N) read(com[i].P[j]);
    }

    For(i, 1, M) {
        LL mx[105];
        LL sum[105];
        Rof(r, N, 1) {
            mx[r + 1] = sum[r + 1] = 0;
            Rof(l, r, 1) {
                mx[l] = max(mx[l + 1], com[i].P[l]);
                sum[l] = sum[l + 1] + mx[l];
                LL uni = (sum[l + 1] - sum[min((LL)r, l + com[i].I) + 1]);
                stock[i][l][r] = { stock[i][l + 1][r].fir + stock[i][l + 1][r].sec + com[i].H * uni, uni * com[i].G + stock[i][l + 1][r].sec };
            }
        }
        For(j, com[i].L, com[i].R) alive[j][i]++;
    }
    For(i, 1, N) For(j, 1, M) alive[i][j] += alive[i][j - 1];
    // cout << get_cash(5, 1, 1, 1) + get_cash(6, 2, 3, 10) << endl;
    vf[0][0][0] = 1;
    For(i, 0, N - 1) {
        For(j, 0, N) For(p, 0, M) vg[j][p] = 0;
        For(j, 0, N) {
            For(idx, 0, M) if(vf[i][j][idx]) {
                For(k, 0, M) if(!k || (i + 1 >= com[k].L && i + 1 <= com[k].R)) if(!idx || k < com[idx].U || k > com[idx].V) if(k != idx || !k) {
                    if(!vg[j][k] || g[j][k] < f[i][j][idx]) {
                        g[j][k] = f[i][j][idx];
                        vg[j][k] = 1;
                    }
                }
            }
        }
        For(j, 0, N) {
            For(idx, 1, M) if(vg[j][idx]) For(r, i + 1, min(N, com[idx].R)) {
                DD tem = g[j][idx] + get_cash(j + X, idx, i + 1, r);
                if(!vf[r][j + r - i][idx] || f[r][j + r - i][idx] < tem) {
                    f[r][j + r - i][idx] = tem;
                    vf[r][j + r - i][idx] = 1;
                }
                if(r == com[idx].R && (!vf[r][j + r - i][0] || f[r][j + r - i][0] < tem)) {
                    f[r][j + r - i][0] = tem;
                    vf[r][j + r - i][0] = 1;
                }
                if(alive[r + 1][com[idx].V] - alive[r + 1][com[idx].U - 1]) {
                    tem += com[idx].J * (r - i) + com[idx].K;
                    if(!vf[r + 1][j + r - i][0] || f[r + 1][j + r - i][0] < tem) {
                        f[r + 1][j + r - i][0] = tem;
                        vf[r + 1][j + r - i][0] = 1;
                    }
                }
            }
            if(vg[j][0]) For(r, i + 1, N) {
                DD tem = g[j][0];
                if(!vf[r][j][0] || f[r][j][0] < tem) {
                    f[r][j][0] = tem;
                    vf[r][j][0] = 1;
                }
            }
        }
        // if(i == 0) cout << vf[1][1][1] << endl;
    }
    DD res = 0;
    For(i, 0, N + 1) For(j, 0, N) For(idx, 0, M) res = max(res, f[i][j][idx]);
    printf("%.10lf\n", res);
    return 0;
}
