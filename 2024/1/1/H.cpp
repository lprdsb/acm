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

#define maxn 100000
int n;
int ok[maxn + 5][2];
pair<int, pair<int, int> > st[2 * maxn + 5];

bool chk() {
    For(i, 1, n) ok[i][0] = ok[i][1] = 0;
    For(i, n + 1, 2 * n) ok[st[i].sec.fir][st[i].sec.sec] = 1;
    For(i, 1, n) if(!(ok[i][0] ^ ok[i][1])) return 1;
    For(i, 2, n) if(ok[i][0] != ok[1][0]) return 0;
    return 1;
}

int main() {
    //freopen("in", "r", stdin);
    read(n);
    int top = 0;
    For(i, 1, n) {
        int a, b; read(a); read(b);
        st[++top] = { a, {i, 0} };
        st[++top] = { b, {i, 1} };
    }
    sort(st + 1, st + top + 1);
    LL res = 0;
    if(chk()) {
        LL tem = 0;
        For(i, 1, n) tem -= st[i].fir;
        For(i, n + 1, 2 * n) tem += st[i].fir;
        res = max(res, tem);
    }

    swap(st[n], st[n + 1]);
    if(chk()) {
        LL tem = 0;
        For(i, 1, n) tem -= st[i].fir;
        For(i, n + 1, 2 * n) tem += st[i].fir;
        res = max(res, tem);
    }
    swap(st[n], st[n + 1]);

    swap(st[n], st[n + 2]);
    if(chk()) {
        LL tem = 0;
        For(i, 1, n) tem -= st[i].fir;
        For(i, n + 1, 2 * n) tem += st[i].fir;
        res = max(res, tem);
    }
    swap(st[n], st[n + 2]);

    swap(st[n - 1], st[n + 1]);
    if(chk()) {
        LL tem = 0;
        For(i, 1, n) tem -= st[i].fir;
        For(i, n + 1, 2 * n) tem += st[i].fir;
        res = max(res, tem);
    }
    swap(st[n - 1], st[n + 1]);

    printf("%lld\n", res);

}
