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

int T, n;
int a[305];

vector<int> as;
int L = 1, R = n, ad[2] = { 0, 0 }, bas = 0;

int get_L() {
    if(ad[0]) return 1;
    else return a[L];
}
int get_R() {
    if(ad[1]) return 0;
    else return a[R];
}
void del_L() {
    bas++;
    if(ad[0]) ad[0]--;
    else L++;
}
void del_R() {
    if(ad[1]) ad[1]--;
    else R--;
}

void mian() {
    read(n);
    int cnt[2] = { 0, 0 };
    For(i, 1, n) {
        char c; cin >> c;
        a[i] = c - '0';
        cnt[a[i]]++;
    }
    if(cnt[0] != cnt[1]) {
        puts("-1");
        return;
    }
    else {
        L = 1, R = n;
        ad[0] = 0; ad[1] = 0; bas = 0;
        as.resize(0);
        while(L < R) {
            if(get_L() != get_R()) del_L(), del_R();
            else {
                if(get_L()) {
                    as.pb(bas);
                    ad[0]++;
                    bas++;
                    del_R();
                }
                else {
                    as.pb(bas + R - L + 1 + ad[1]);
                    ad[1]++;
                    del_L();
                }
            }
        }
        printf("%d\n", as.size());
        for(auto i : as) printf("%d ", i); puts("");
    }
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
