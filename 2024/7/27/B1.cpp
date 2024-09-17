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
int num[3][26], len[3], sum[2];
char s[maxn + 5];

vector<pair<int, int> > as;
vector<int> st[3];

int main() {
    freopen("in.txt", "r", stdin);
    int tot = 0;
    For(o, 0, 2) {
        scanf("%s", s + 1); len[o] = strlen(s + 1);
        For(i, 1, len[o]) num[o][s[i] - 'A']++;
    }
    // For(_, 1, 100) {
    vector<int> vec;
    For(o, 0, 25) For(i, 1, num[0][o]) vec.pb(o);
    For(o, 0, 25) if(num[1][o] && num[2][o]) {
        int mn = min((int)vec.size(), min(num[1][o], num[2][o]));
        For(i, 1, mn) {
            as.pb({ vec.back(), o });
            num[0][vec.back()]--;
            vec.pop_back();
        }
        num[1][o] -= mn; num[2][o] -= mn;
    }
    For(o, 0, 25) For(i, 1, 2) For(j, 1, num[i][o]) st[i].pb(o);
    while(vec.size()) {
        if(st[1].size() < st[2].size()) swap(st[1], st[2]);
        as.pb({ vec.back(), st[1].back() });
        vec.pop_back(); st[1].pop_back();
    }
    for(auto o : vec) as.pb({ o, o });
    if(st[1].size() < st[2].size()) swap(st[1], st[2]);
    For(i, 0, st[2].size() - 1) as.pb({ st[1][i], st[2][i] });
    For(i, st[2].size(), st[1].size() - 1) as.pb({ st[1][i], st[1][i] });

    // }

    printf("%d\n", as.size());
    for(auto [i, j] : as) printf("%c%c\n", 'A' + i, 'A' + j);
    return 0;
}
