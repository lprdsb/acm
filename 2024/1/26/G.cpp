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

#define maxn 1000
int n, m, q;
struct Poi { Poi *ch[2]; int x; } poi[maxn + 5][maxn + 5];

Poi* find(int x, int y) {
    // cout << "asd1" << endl;
    Poi *res = &poi[0][0];
    For(i, 1, x) res = res->ch[0];
    For(i, 1, y) res = res->ch[1];
    // cout << "asd" << endl;
    return res;
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(n); read(m); read(q);
    For(i, 1, n) For(j, 1, m) read(poi[i][j].x);
    For(i, 0, n) For(j, 0, m) {
        poi[i][j].ch[0] = &poi[i + 1][j];
        poi[i][j].ch[1] = &poi[i][j + 1];
    }
    while(q--) {
        int x1, y1, x2, y2, w, h; read(x1); read(y1); read(x2); read(y2); read(h); read(w);
        Poi *p[4][2];
        p[0][0] = find(x1 - 1, y1); p[0][1] = find(x2 - 1, y2);
        p[1][0] = find(x1 + h - 1, y1); p[1][1] = find(x2 + h - 1, y2);
        p[2][0] = find(x1, y1 - 1); p[2][1] = find(x2, y2 - 1);
        p[3][0] = find(x1, y1 + w - 1); p[3][1] = find(x2, y2 + w - 1);
        For(o, 0, 1) For(i, 1, w) {
            swap(p[o][0]->ch[0], p[o][1]->ch[0]);
            For(o1, 0, 1) p[o][o1] = p[o][o1]->ch[1];
        }
        For(o, 2, 3) For(i, 1, h) {
            swap(p[o][0]->ch[1], p[o][1]->ch[1]);
            For(o1, 0, 1) p[o][o1] = p[o][o1]->ch[0];
        }
    }
    For(i, 1, n) {
        Poi *now = &poi[i][0];
        For(j, 1, m) {
            now = now->ch[1];
            printf("%d ", now->x);
        }
        puts("");
    }
}
