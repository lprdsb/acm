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

string opt(string s) {
    string res = "";
    For(i, 1, s.length() - 1) res += s[i];
    res += s[0];
    return res;
}

int n;
string s[55];

int main() {
    //freopen("in", "r", stdin);
    read(n);
    For(i, 1, n) cin >> s[i];
    int res = inf, fl = 0;
    For(i, 1, n) {
        int resi = 0;
        For(j, 1, n) if(j != i) {
            int cnt = 0;
            string tem = s[j];
            while(tem != s[i]) {
                tem = opt(tem);
                cnt++;
                if(cnt >= 50) {
                    fl = 1;
                    break;
                }
            }
            resi += cnt;
            if(fl) break;
        }
        res = min(res, resi);
        if(fl) break;
    }
    if(fl) puts("-1");
    else printf("%d\n", res);
}
