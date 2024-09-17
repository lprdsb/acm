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
int n, q, a[maxn + 5];

void que(int l, int r) {
    vector<int> vec;
    For(i, l, r) vec.pb(a[i]);
    sort(vec.begin(), vec.end());
    int mmn = inf, mmx = -1;
    For(i, 2, vec.size() - 1) {
        if(vec[i] < vec[i - 1] + vec[i - 2]) {
            mmn = min(mmn, i);
            mmx = max(mmx, i);
        }
    }
    if(mmx - mmn >= 3) puts("YES");
    else if(mmx != -1) {
        if(mmx == mmn) puts("NO");
        else {
            // cout << mn << " " << mx << endl;
            For(mn, mmn, mmx - 1) For(mx, mn + 1, mmx) {
                vector<int> ok;
                Rof(i, mx - 1, 0) if(i != mn) {
                    ok.pb(vec[i]);
                    if(ok.size() == 4) break;
                }
                if(ok.size() != 4) continue;
                if(mn + 1 == mx) {
                    if(ok[0] + ok[1] > vec[mx] && ok[2] + ok[3] > vec[mn]) {
                        puts("YES");
                        return;
                    }
                    else if(ok[0] + ok[2] > vec[mx] && ok[1] + ok[3] > vec[mn]) {
                        puts("YES");
                        return;
                    }
                    else if(ok[0] + ok[3] > vec[mx] && ok[1] + ok[2] > vec[mn]) {
                        puts("YES");
                        return;
                    }
                    else if(ok[1] + ok[2] > vec[mx] && ok[0] + ok[3] > vec[mn]) {
                        puts("YES");
                        return;
                    }
                    else if(ok[1] + ok[3] > vec[mx] && ok[0] + ok[2] > vec[mn]) {
                        puts("YES");
                        return;
                    }
                    else if(ok[2] + ok[3] > vec[mx] && ok[0] + ok[1] > vec[mn]) {
                        puts("YES");
                        return;
                    }
                }
                else {
                    if(ok[0] + ok[1] > vec[mx] && ok[2] + ok[3] > vec[mn]) {
                        puts("YES");
                        return;
                    }
                    else if(ok[0] + ok[2] > vec[mx] && ok[1] + ok[3] > vec[mn]) {
                        puts("YES");
                        return;
                    }
                    else if(ok[0] + ok[3] > vec[mx] && ok[1] + ok[2] > vec[mn]) {
                        puts("YES");
                        return;
                    }
                }
            }
            puts("NO");
        }
    }
    else puts("NO");
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(n); read(q);
    For(i, 1, n) read(a[i]);
    while(q--) {
        int l, r; read(l); read(r);
        if(r - l + 1 >= 400) puts("YES");
        else que(l, r);
    }
}
