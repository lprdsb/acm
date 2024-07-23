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

#define maxn 1000000
int n, m, a[maxn + 5], b[maxn + 5], c[maxn + 5];
pair<int, int> pa[maxn + 5];

int st[maxn + 5], tp = 0;
set<pair<int, int> > se;
int main() {
    // freopen("in.txt", "r", stdin);
    read(n); read(m);
    For(i, 1, n) read(a[i]);
    For(i, 1, n) read(b[i]);
    For(i, 1, n) pa[i] = { a[i], a[i] - b[i] };
    sort(pa + 1, pa + n + 1);
    Rof(i, n, 1) {
        while(tp && pa[i].sec <= pa[st[tp]].sec) tp--;
        st[++tp] = i;
    }
    For(i, 1, m) read(c[i]);
    int now = 0; c[m + 1] = -1;
    sort(c + 1, c + m + 1);
    For(i, 1, m + 1) {
        if(i != 1 && c[i] != c[i - 1]) {
            se.insert({ c[i - 1], now });
            now = 0;
        }
        now++;
    }
    LL res = 0;
    For(i, 1, tp) {
        // cout << pa[st[i]].fir << " asd " << pa[st[i]].sec << endl;
        // for(auto [k, v] : se) cout << k << " " << v << endl;
        vector<pair<int, int> > vec, vec1;
        auto it = se.lower_bound({ pa[st[i]].fir, 0 });
        while(it != se.end()) vec.pb(*it), it++;
        // cout << vec.size() << endl;
        for(auto v : vec) {
            se.erase(v);
            res += 1ll * v.sec * ((v.fir - pa[st[i]].fir) / pa[st[i]].sec + 1);
            vec1.pb({ pa[st[i]].fir + (v.fir - pa[st[i]].fir) % pa[st[i]].sec - pa[st[i]].sec, v.sec });
        }
        sort(vec1.begin(), vec1.end());
        int now = 0;
        vec1.pb({ -1, 0 });
        For(j, 0, vec1.size() - 1) {
            if(j && vec1[j].fir != vec1[j - 1].fir) {
                auto it = se.lower_bound({ vec1[j - 1].fir, 0 });
                if(it != se.end() && it->fir == vec1[j - 1].fir) {
                    now += it->sec;
                    se.erase(it);
                }
                se.insert({ vec1[j - 1].fir, now });
                now = 0;
            }
            now += vec1[j].sec;
        }
    }
    printf("%lld\n", 2 * res);
    return 0;
}
