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
vector<int> vec[30];

int main() {
    // freopen("in.txt", "r", stdin);
    read(n); read(q);
    For(i, 1, n) read(a[i]);
    vec[0].pb(-inf);
    For(i, 1, n) vec[0].pb(i);
    vec[0].pb(inf);
    auto chkmn = [](int _x, int _y)->bool {return _x < _y;};
    auto chkmx = [](int _x, int _y)->bool {return _x > _y;};
    auto work = [](vector<int> &x, auto chk)->vector<int> {
        if(x.size() == 3) return x;
        vector<int> res;
        res.pb(-inf);
        For(i, 1, x.size() - 2) {
            if(i == 1) {
                if(chk(a[x[i]], a[x[i + 1]])) res.pb(x[i]);
            }
            else if(i == x.size() - 2) {
                if(chk(a[x[i]], a[x[i - 1]])) res.pb(x[i]);
            }
            else if(chk(a[x[i]], a[x[i - 1]]) && chk(a[x[i]], a[x[i + 1]])) res.pb(x[i]);
        }
        res.pb(inf);
        return res;
        };
    auto chk = [&](int o) {return (o & 1) ? chkmn : chkmx;};
    For(i, 1, 29) vec[i] = work(vec[i - 1], chk(i));
    // cout << "asd" << endl;

    // For(i, 0, 3) {
    //     cout << i << endl;
    //     for(auto j : vec[i]) cout << j << " "; cout << endl;
    // }

    while(q--) {
        int l, r, L, R; read(l); read(r); L = l + 1, R = r - 1;
        For(i, 0, 29) {
            auto cc = chk(i + 1);
            if(L > R) {
                printf("%d\n", cc(a[l], a[r]) ? a[l] : a[r]);
                break;
            }
            if(!l) {
                int tem = vec[i][lower_bound(vec[i].begin(), vec[i].end(), L) - vec[i].begin()];
                if(tem > R) l = r, L = R + 1;
                else l = tem, L = l + 1;
            }
            if(!r) {
                int tem = vec[i][lower_bound(vec[i].begin(), vec[i].end(), R + 1) - vec[i].begin() - 1];
                if(tem < L) r = l, R = L - 1;
                else r = tem, R = r - 1;
            }
            if(L > R) {
                printf("%d\n", cc(a[l], a[r]) ? a[l] : a[r]);
                break;
            }
            int ll = L, rr = R;
            int tem = lower_bound(vec[i].begin(), vec[i].end(), ll) - vec[i].begin();
            if(vec[i][tem] > rr) {
                printf("%d\n", cc(a[l], a[r]) ? a[l] : a[r]);
                break;
            }
            if(cc(a[l], a[vec[i][tem]])) L = vec[i][tem] + 1;
            else {
                if(vec[i][tem + 1] <= rr) {
                    if(cc(a[vec[i][tem]], a[vec[i][tem + 1]])) l = vec[i][tem];
                    else l = 0;
                    L = vec[i][tem] + 1;
                }
                else {
                    printf("%d\n", cc(a[vec[i][tem]], a[r]) ? a[vec[i][tem]] : a[r]);
                    break;
                }
            }

            tem = lower_bound(vec[i].begin(), vec[i].end(), rr + 1) - vec[i].begin() - 1;
            if(cc(a[r], a[vec[i][tem]])) R = vec[i][tem] - 1;
            else {
                if(vec[i][tem - 1] >= ll) {
                    if(cc(a[vec[i][tem]], a[vec[i][tem - 1]])) r = vec[i][tem];
                    else r = 0;
                    R = vec[i][tem] - 1;
                }
                else {
                    printf("%d\n", cc(a[vec[i][tem]], a[l]) ? a[vec[i][tem]] : a[l]);
                    break;
                }
            }
        }
    }
    return 0;
}
