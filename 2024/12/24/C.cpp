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

#define maxn 5000
int T, t, n, a[maxn + 5];
char s[maxn + 5];

int chk(int x, int y) {
    For(i, 0, n - t) {
        if(a[x + i] != a[y + i]) return (a[x + i] ^ a[t + i]) < (a[y + i] ^ a[t + i]);
    }
    return 0;
}

void mian() {
    scanf("%s", s + 1); n = strlen(s + 1);
    For(i, 1, n) a[i] = s[i] - '0';
    cout << 1 << " " << n << " ";
    t = 0;
    For(i, 1, n) if(!a[i]) {
        t = i;
        break;
    }
    if(t == 0) cout << "1 1" << endl;
    else {
        int mx = 1;
        For(i, 2, t - 1) if(chk(mx, i)) mx = i;
        cout << mx << " " << mx + n - t << endl;
    }
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
