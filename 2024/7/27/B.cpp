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

#define maxn 2000
int num[3][26], d[3][26];
char s[maxn + 5];

vector<pair<int, int> > as;
vector<int> st[3];

int main() {
    freopen("in.txt", "r", stdin);
    For(o, 0, 2) {
        scanf("%s", s + 1);
        int n = strlen(s + 1);
        For(i, 1, n) num[o][s[i] - 'A']++;
    }
    For(o, 0, 25) num[0][o] = max(num[0][o], max(num[1][o], num[2][o]));
    vector<int> v;
    For(o, 0, 25) {
        int tem = num[0][o] - num[1][o] - num[2][o];
        if(tem > 0) For(i, 1, tem) v.pb(o);
    }
    For(o, 0, 25) {
        int tem = num[1][o] + num[2][o] - num[0][o];
        if(tem > 0) {
            int mn = min(tem / 2, (int)v.size());
            // cout << mn << endl;
            For(i, 1, mn) {
                num[0][v.back()]--;
                as.pb({ o, v.back() });
                v.pop_back();
            }
            num[1][o] -= mn;
            num[2][o] -= mn;
        }
    }

    For(o, 0, 25) {
        int tem = num[1][o] + num[2][o] - num[0][o];
        if(tem >= 0) {
            For(i, 1, num[0][o] - num[1][o]) st[1].pb(o);
            For(i, 1, num[0][o] - num[2][o]) st[2].pb(o);
        }
        else {
            For(i, 1, num[1][o]) st[2].pb(o);
            For(i, 1, num[2][o]) st[1].pb(o);
            For(i, 1, num[0][o] - num[1][o] - num[2][o]) st[0].pb(o);
        }
    }
    vector<int> vec[3];
    For(o, 0, 25) {
        int mn = min((int)st[0].size(), min(d[1][o], d[2][o]));
        For(i, 1, mn) as.pb({ o, st[0].back() }), st[0].pop_back();
        d[1][o] -= mn; d[2][o] -= mn;

        mn = min((int)st[1].size(), d[1][o]);
        For(i, 1, mn) as.pb({ o, st[1].back() }), st[1].pop_back();
        d[1][o] -= mn;


        mn = min((int)st[2].size(), d[2][o]);
        For(i, 1, mn) as.pb({ o, st[2].back() }), st[2].pop_back();
        d[2][o] -= mn;

        For(i, 1, 2) For(j, 1, d[i][o]) vec[i].pb(o);
    }
    // for(auto [i, j] : as) printf("%c%c\n", 'A' + i, 'A' + j);
    // cout << st[0].size() << endl;
    // For(o, 0, 25) cout << d[1][o] << " " << d[2][o] << endl;
    while(st[0].size() && (vec[1].size() || vec[2].size())) {
        if(vec[1].size() < vec[2].size()) swap(vec[1], vec[2]);
        as.pb({ st[0].back(), vec[1].back() });
        st[0].pop_back(); vec[1].pop_back();
    }
    For(i, 0, 2) for(auto o : st[i]) as.pb({ o, o });
    For(i, 0, vec[2].size() - 1) as.pb({ vec[1][i], vec[2][i] });
    For(i, vec[2].size(), vec[1].size() - 1) as.pb({ vec[1][i], vec[1][i] });


    printf("%d\n", as.size());
    for(auto [i, j] : as) printf("%c%c\n", 'A' + i, 'A' + j);
    return 0;
}
