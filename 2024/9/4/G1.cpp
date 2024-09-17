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

#define maxn 10
#define maxm 200000
struct Matrix {
    int a[maxn + 5][maxn + 5];
    void init_uni() {
        For(i, 1, 9) a[i][i] = i;
    }
    Matrix() {
        For(i, 0, 9) For(j, 0, 9) a[i][j] = inf;
    }
} tra[maxm + 5];
void chkmn(int &x, int y) {
    if(x > y) x = y;
}
Matrix operator * (cst Matrix &x, cst Matrix &y) {
    Matrix res;
    For(i, 0, 9) For(j, 0, 9) {
        int tmp = x.a[i][j];
        For(p, 0, 9) chkmn(res.a[i][p], tmp + y.a[j][p]);
    }
    return res;
}

int n, k, a[maxm + 5];

void out(Matrix a) {

    For(i, 0, 9) {
        For(j, 0, 9) {
            if(a.a[i][j] != inf) cout << a.a[i][j] << " ";
            else printf("inf ");
        }
        cout << endl;
    }
    cout << endl;
}

Matrix pre[maxm + 5], suf[maxm + 5];
int get_f(int l, int r) {
    Matrix res;
    if(l % k == 1) res = pre[r];
    else if(r % k == 0) {
        res = suf[l];
    }
    else res = pre[r] * suf[l];
    // out(res);
    int as = inf;
    For(i, 1, 9) as = min(as, res.a[i][0]);
    return as;
}

int main() {
    // freopen("in.txt", "r", stdin);
    // out(tra[9]);
    read(n); read(k);
    For(i, 1, n) {
        char c; cin >> c;
        a[i] = c - '0';
    }
    For(i, 1, n) {
        tra[i].init_uni();
        For(j, 1, 9) tra[i].a[0][j] = 0;
        if(i > 1) tra[i].a[a[i - 1]][0] = a[i - 1];
    }
    For(i, 1, n) {
        if(i % k == 1) pre[i] = tra[i];
        else pre[i] = tra[i] * pre[i - 1];
    }
    Rof(i, n, 1) {
        if(i % k == 0 || i == n) suf[i] = tra[i];
        else suf[i] = suf[i + 1] * tra[i];
    }
    For(i, 1, n - k + 1) printf("%d ", get_f(i + 1, i + k - 1));
    // For(i, 1, n) out(pre[i]);
}
