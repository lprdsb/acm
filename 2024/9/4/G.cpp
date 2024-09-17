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

#define maxn 19
struct Matrix {
    int a[maxn + 5][maxn + 5];
    Matrix() {
        For(i, 0, 18) For(j, 0, 18) a[i][j] = inf;
    }
} tra[maxn + 5];
Matrix operator * (cst Matrix &x, cst Matrix &y) {
    Matrix res;
    For(i, 0, 18) For(j, 0, 18) {
        int tmp = x.a[i][j];
        For(p, 0, 18) res.a[i][p] = min(res.a[i][p], tmp + y.a[j][p]);
    }
    return res;
}

#define maxm 200000
int n, k, a[maxm + 5];

void out(Matrix a) {

    For(i, 0, 18) {
        For(j, 0, 18) {
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
    if(l % k != 1) res = pre[r] * suf[l];
    else res = pre[r];
    int as = inf;
    For(i, 1, 9) as = min(as, res.a[i][0]);
    return as;
}

int main() {
    freopen("in.txt", "r", stdin);
    For(i, 1, 9) {
        tra[i].a[9 + i][0] = 0;
        For(j, 1, 9) {
            tra[i].a[9 + i][j] = 0;
            tra[i].a[j][j] = tra[i].a[j][9 + j] = j;
        }
    }
    // out(tra[9]);
    read(n); read(k);
    For(i, 1, n) {
        char c; cin >> c;
        a[i] = c - '0';
    }
    For(i, 1, n) {
        if(i % k == 1) pre[i] = tra[a[i]];
        else pre[i] = tra[a[i]] * pre[i - 1];
    }
    Rof(i, n, 1) {
        if(i % k == 0 || i == n) suf[i] = tra[a[i]];
        else suf[i] = suf[i + 1] * tra[a[i]];
    }
    For(i, 1, n - k + 1) printf("%d ", get_f(i, i + k - 1));
    For(i, 1, n) out(pre[i]);
}
